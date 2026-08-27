#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

enum enQuestionsLevel { EasyLevel = 1, MidLevel = 2, HardLevel = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

struct stQuestion {
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionsLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuizz {
    stQuestion QuestionList[100];
    short NumberOfQuestions = 0;
    enQuestionsLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfWrongAnswer = 0;
    short NumberOfRightAnswer = 0;
    bool IsPass = false;
};

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

string GetOpTypeSymbol(enOperationType OpType) {
    switch (OpType) {
    case enOperationType::Add:  return "+";
    case enOperationType::Sub:  return "-";
    case enOperationType::Mult: return "*";
    case enOperationType::Div:  return "/";
    default:                    return "Mix";
    }
}

string GetQuestionLevelText(enQuestionsLevel QuestionLevel) {
    string arrQuestionLevelText[4] = { "Easy", "Med", "Hard", "Mix" };
    return arrQuestionLevelText[QuestionLevel - 1];
}

void SetScreenColor(bool RightAnswer) {
    if (RightAnswer)
        system("Color 2F");
    else
       
        system("Color 4F");
}

short ReadHowManyQuestions() {
    short NumberOfQuestion;
    do {
        cout << "How Many Questions do you want to answer ? ";
        cin >> NumberOfQuestion;
    } while (NumberOfQuestion < 1 || NumberOfQuestion > 100);
    return NumberOfQuestion;
}

enQuestionsLevel ReadQuestionLevel() {
    short QuestionLevel;
    do {
        cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix: ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);
    return (enQuestionsLevel)QuestionLevel;
}

enOperationType ReadOperationType() {
    short OpType;
    do {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
        cin >> OpType;
    } while (OpType < 1 || OpType > 5);
    return (enOperationType)OpType;
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType) {
    switch (OpType) {
    case enOperationType::Add:  return Number1 + Number2;
    case enOperationType::Sub:  return Number1 - Number2;
    case enOperationType::Mult: return Number1 * Number2;
    case enOperationType::Div:  return (Number2 != 0) ? Number1 / Number2 : 0;
    default:                    return Number1 + Number2;
    }
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType) {
    stQuestion Question;

    if (QuestionLevel == enQuestionsLevel::Mix) {
        QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);
    }
    if (OpType == enOperationType::MixOp) {
        OpType = (enOperationType)RandomNumber(1, 4);
    }

    Question.OperationType = OpType;
    Question.QuestionLevel = QuestionLevel;

    switch (QuestionLevel) {
    case enQuestionsLevel::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;
    case enQuestionsLevel::MidLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;
    case enQuestionsLevel::HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;
    default:
        break;
    }

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz) {
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++) {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
    }
}

int ReadQuestionAnswer() {
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

void PrintTheQuestions(stQuizz& Quizz, short QuestionNumber) {
    cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
    cout << "\n____________\n";
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber) {
    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer) {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswer++;

        cout << "\a";
        cout << "Wrong Answer :-(\n";
        cout << "The right answer is : " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << "\n";
    }
    else {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswer++;
        cout << "Correct Answer :-) \n";
    }
    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectTheQuestion(stQuizz& Quizz) {
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++) {
        PrintTheQuestions(Quizz, Question);
        Quizz.QuestionList[Question].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, Question);
    }
    Quizz.IsPass = (Quizz.NumberOfRightAnswer >= Quizz.NumberOfWrongAnswer);
}

string GetFinalResultsText(bool Pass) {
    return Pass ? "PASS :-)" : "FAIL :-(";
}

void PrintQuizzResults(stQuizz Quizz) {
    cout << "\n_____________________________\n\n";
    cout << " Final Results is " << GetFinalResultsText(Quizz.IsPass) << endl;
    cout << "_____________________________\n\n";
    cout << "Number of Questions    : " << Quizz.NumberOfQuestions << endl;
    cout << "Question Level         : " << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;
    cout << "Operation Type         : " << GetOpTypeSymbol(Quizz.OpType) << endl;
    cout << "Number of Right Answers: " << Quizz.NumberOfRightAnswer << endl;
    cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswer << endl;
    cout << "_____________________________\n";
}

void PlayMathGame() {
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.QuestionsLevel = ReadQuestionLevel();
    Quizz.OpType = ReadOperationType();

    GenerateQuizzQuestions(Quizz);
    AskAndCorrectTheQuestion(Quizz);
    PrintQuizzResults(Quizz);
}

void ResetScreen() {
    system("cls");
    system("color 0F");
}

void StartGame() {
    char PlayAgain = 'Y';
    do {
        ResetScreen();
        PlayMathGame();
        cout << endl << "Do You Want to Play Again ? Y/N ? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}