#include <iostream>
using namespace std;

string Name_Medicine[5] = { "Vitamin-C","Aspirin","Panadol","Amoxil","Profen"};
double Price_Medicine[5] = {15000,25000,9500,22000,35000};
int Quantity_Medeicine[5] = {428,350,1000,400,750};

int ReadNumber(string Message) {
	int Number;
	cout << Message << endl;
	cin >> Number;
	return Number;
}
  
void Show_Medicine() {
	
	int Number;
	cout << "If you want Vitamin-C enter 1 or Aspirin enter 2 or Panadol enter 3 or Amoxil enter 4 or Profen enter 5\n";
	cin >> Number;
	if (Number == 1) {
		cout << Name_Medicine[0] << ":Number is 1" << " |Price is: " << Price_Medicine[0] << " |Quantity is: " << Quantity_Medeicine[0] << endl;
	}
	else if (Number == 2) {
		cout << Name_Medicine[1] << ":Number is 2" << " |Price is: " << Price_Medicine[1] << " |Quantity is: " << Quantity_Medeicine[1] << endl;
	}
	else if (Number == 3) {
		cout << Name_Medicine[2] << ":Number is 3" << " |Price is: " << Price_Medicine[2] << " |Quantity is: " << Quantity_Medeicine[2] << endl;
	}
	else if (Number == 4) {
		cout << Name_Medicine[3] << ":Number is 4" << " |Price is: " << Price_Medicine[3] << " |Quantity is: " << Quantity_Medeicine[3] << endl;
	}
	else if (Number == 5) {
		cout << Name_Medicine[4] << ":Number is 5" << " |Price is: " << Price_Medicine[4] << " |Quantity is: " << Quantity_Medeicine[4] << endl;
	}
	else
		cout << "You entered false number!\n";
}

void SaleofMedicine() {

	int NT, NQ;
	int Price;
	cout << "Enter Number of Medicine\n";
	cin >> NT;
	if (NT == 1) {
		cout << "Enter Quantity you need?";
		cin >> NQ;
		if (NQ <= Quantity_Medeicine[0]) {
			Quantity_Medeicine[0] -= NQ;
			Price = NQ * Price_Medicine[0];
			cout << "YOU BUY " << NQ << "FROM " << Name_Medicine[0] << " |PRICE IS: " << Price << endl;
			cout << "THANKS FOR YOU.. \n";
		}
		else
			cout << "Quantity Not enough it is " << Quantity_Medeicine[0] << endl;
	}
	if (NT == 2) {
		cout << "Enter Quantity you need?";
		cin >> NQ;
		if (NQ <= Quantity_Medeicine[1]) {
			Quantity_Medeicine[1] -= NQ;
			Price = NQ * Price_Medicine[1];
			cout << "YOU BUY " << NQ << "FROM " << Name_Medicine[1] << " |PRICE IS: " << Price << endl;
			cout << "THANKS FOR YOU.. \n";
		}
		else
			cout << "Quantity Not enough it is " << Quantity_Medeicine[1] << endl;
	}
	if (NT == 3) {
		cout << "Enter Quantity you need?";
		cin >> NQ;
		if (NQ <= Quantity_Medeicine[2]) {
			Quantity_Medeicine[2] -= NQ;
			Price = NQ * Price_Medicine[2];
			cout << "YOU BUY " << NQ << "FROM " << Name_Medicine[2] << " |PRICE IS: " << Price << endl;
			cout << "THANKS FOR YOU.. \n";
		}
		else
			cout << "Quantity Not enough it is " << Quantity_Medeicine[2] << endl;
	}
	if (NT == 4) {
		cout << "Enter Quantity you need?";
		cin >> NQ;
		if (NQ <= Quantity_Medeicine[3]) {
			Quantity_Medeicine[3] -= NQ;
			Price = NQ * Price_Medicine[3];
			cout << "YOU BUY " << NQ << "FROM " << Name_Medicine[3] << " |PRICE IS: " << Price << endl;
			cout << "THANKS FOR YOU.. \n";
		}
		else
			cout << "Quantity Not enough it is " << Quantity_Medeicine[3] << endl;
	}
	if (NT == 5) {
		cout << "Enter Quantity you need?";
		cin >> NQ;
		if (NQ <= Quantity_Medeicine[4]) {
			Quantity_Medeicine[4] -= NQ;
			Price = NQ * Price_Medicine[4];
			cout << "YOU BUY " << NQ << "FROM " << Name_Medicine[4] << " |PRICE IS: " << Price << endl;
			cout << "THANKS FOR YOU.. \n";
		}
		else
			cout << "Quantity Not enough it is " << Quantity_Medeicine[4] << endl;
	}
}

int main() {

	int Choise;
	int Number;
do {
	Choise = ReadNumber("Enter 1 to Show Medicine or 2 to Buying Medicine or 3 to Exit");
	if (Choise == 1) {
		Show_Medicine();
	}
	else if (Choise == 2) {
		SaleofMedicine();
	}
} while (Choise != 3);
}