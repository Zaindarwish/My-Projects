#include <iostream>
#include <cstdlib>

using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner {Player1=1,Computer=2,Draw=3};

struct stRoundInfo {
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};
struct stGameResults {
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

int RandomNumber(int From, int To) {
	int randnum = rand() % (To - From + 1) + From;
	return randnum;

}
string WinnerName(enWinner Winner) {
	string arrWinnerName[3] = {"Player1","Computer","No Winner"};
	return arrWinnerName[ Winner - 1 ];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
		return enWinner::Draw;

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player1;
	case enGameChoice::Paper:
		return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player1;
	case enGameChoice::Scissors:
		return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player1;
	}
} 

string ChoiceName(enGameChoice Choice) {
	string arrGameChoices[3] = { "Stone","Paper","Scissors" };
	return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner) {
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F");
		break;
	case enWinner::Computer:
		system("color 4F");
		break;
	case enWinner::Draw:
		system("color 6F");
		break;
	default:
		break;
	}
}

void PrintRoundResults(stRoundInfo RoundInfo) {

	cout << "\n____________Round[" << RoundInfo.RoundNumber << "]____________\n\n";
	cout << "Player1  Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round  Winner: [" << RoundInfo.WinnerName << "] \n";
	cout << "__________________________________\n\n";

	SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes) {

	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (Player1WinTimes < ComputerWinTimes) return enWinner::Computer;
	else return enWinner::Draw;
}

stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTines, short DrawTimes) {

	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.Computer2WinTimes = ComputerWinTines;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTines);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

enGameChoice ReadPlayer1choice() {
	short Choice = 1;
	do {
		cout << "\nYour Choice: [1]:Stone,[2]:Paper,[3]:Scissors ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 3);
	return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice() {
	return (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRounds) {

	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++) {
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else DrawTimes++;

		PrintRoundResults(RoundInfo);
	}
	return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs) {

	string t = "";
	for (int i = 0; i < NumberOfTabs; i++) {
		t = t + "\t";
		cout << t;
	}
	return t;
}

void ShowFinalGameResults(stGameResults GameResults) {

cout << Tabs(2) << "_______________________ [Game Results] ________________________\n\n";
cout << Tabs(2) << "Game Rounds       : " << GameResults.GameRounds << endl;
cout << Tabs(2) << "Player1 Won Times : " << GameResults.Player1WinTimes << endl;
cout << Tabs(2) << "Computer Won Times: " << GameResults.Computer2WinTimes << endl;
cout << Tabs(2) << "Draw Times        : " << GameResults.DrawTimes << endl;
cout << Tabs(2) << "Final Winner      : " << GameResults.WinnerName << endl;
cout << Tabs(2) << "_______________________________________________________________\n\n";
SetWinnerScreenColor(GameResults.GameWinner);
 
}

void ShowGameOverScreen() {
	cout << Tabs(2) << "_______________________________________________________________\n\n";
	cout << Tabs(2) << "                    +++G a m e  O v e r +++\n";
	cout << Tabs(2) << "_______________________________________________________________\n\n";
}

short ReadHowManyRounds() {

	short GameRounds = 1;
	do {
		cout << "How Many Rounds 1 to 10 ?\n";
		cin >> GameRounds;
	} while (GameRounds < 1 || GameRounds > 10);
	return GameRounds;
}

void ResetScreen() {

	system("cls");
	system("color 0F");
}

void StartGame() {

	char PlayAgain = 'Y';
	do {
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);


		cout << endl << Tabs(3) << "Do You Want to play again?Y/N? ";
		cin >> PlayAgain;
		
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main()
{
	srand((unsigned)time(NULL));  
	StartGame();  
	return 0; 
}