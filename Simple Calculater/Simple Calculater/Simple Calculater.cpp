#include <iostream>
using namespace std;

enum enCulculate { Addition = 0, subtraction = 1, maltiplication = 2, division = 3 };

void ReadNumbers(int& Num1, int& Num2) {


	cout << "Please Enter Your Number1 ?" << endl;
	cin >> Num1;
	cout << "Please Enter Your Number2 ?" << endl;
	cin >> Num2;
}
enCulculate ReadOperationType() {
	int Op;
	cout << "Please Enter Operation Type: Addition=0,Subtraction=1,Maltiplication=2,Division=3" << endl;
	cin >> Op;

	return (enCulculate)Op;
}
float Calculate(int Num1, int Num2, enCulculate OpType) {
	switch (OpType) {


	case enCulculate::Addition:
		return Num1 + Num2;

	case enCulculate::subtraction:
		return Num1 - Num2;

	case enCulculate::maltiplication:
		return Num1 * Num2;

	case enCulculate::division:
		if (Num2 == 0) return 0;
		return Num1 / Num2;

	default:
		return 0;
	}
}
int main() {

	int Num1, Num2;
	ReadNumbers(Num1, Num2);

	enCulculate Op = ReadOperationType();

	cout << "\nThe Result is: " << Calculate(Num1, Num2, Op) << endl;








	return 0;



}
















