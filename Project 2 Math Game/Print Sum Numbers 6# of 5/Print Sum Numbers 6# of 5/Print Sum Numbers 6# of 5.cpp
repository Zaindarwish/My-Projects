#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string Message) {

	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int ProccesNumber(int Number) {
	int Sum = 0;
	int Reminder;
	while (Number > 0) {

		Reminder = Number % 10;
		Number = Number / 10;
		Sum += Reminder;
	}
	return Sum;

}
	int main() {
		cout  << ProccesNumber(ReadPositiveNumber("Please enter Positive Number"));
		cout << endl;

	}


