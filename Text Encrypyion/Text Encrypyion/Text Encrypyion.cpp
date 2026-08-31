#include<iostream>
using namespace std;



	// ((N - 3) * 2 + 8);

char Decryption(int Z)
{
	int X = ((Z - 8) / 2 + 3);
	return (char)X;

}

int main() {

	int Number;

	cout << "Enter encrypted Number | enter -1\n";
	while (true) {
		cin >> Number;
		if (Number == -1) {
			break;
		}
		else {

			cout << Decryption(Number);
		}
	}
return 0;
}