#include <iostream>
#include <string>

using namespace std;

struct PersonInfo {

	string FullName;
	int Age;
	string Country;
	string City;
	string EducationalBackGround;
	bool ItWorksBeforre;
	float WeeklySalaryWant;
	float MonthlySalaryWant;
	float YearlySalaryWant;
	string Hobbies;
};
void PersonInformaions(PersonInfo& User1) {

	cout << "Please enter Your FullName?" << endl;
	getline(cin, User1.FullName);
	//cin.ignore(1000, '\n');
	cout << "Please enter Your Age?" << endl;
	cin >> User1.Age;
	cout << "Please enter Your Country?" << endl;
	cin >> User1.Country;
	cout << "Please enter Your City?" << endl;
	cin >> User1.City;
	cout << "Please enter Your Eductional Back Ground?" << endl;
	cin.ignore(1000, '\n');
	getline(cin, User1.EducationalBackGround);
	cout << "Please Choise 1 if You Working Before if not Choise 0? " << endl;
	cin >> User1.ItWorksBeforre;
	cout << "Please enter Salary Weekly You Hope?" << endl;
	cin >> User1.WeeklySalaryWant;
	cout << "Please enter Your Hobbies?" << endl;
	cin.ignore(1000, '\n');
    getline(cin, User1.Hobbies);
};

void CalculatSalary(PersonInfo &User1) {

	User1.MonthlySalaryWant = User1.WeeklySalaryWant * 4;
	
	User1.YearlySalaryWant = User1.MonthlySalaryWant * 12;
	
}

void PrintInfo(PersonInfo &User1) {
	cout << "***********************************************\n\n";
	cout << "Full Name: " << User1.FullName << endl;
	cout << "Age: " << User1.Age << endl;
	cout << "Country: " << User1.Country << endl;
	cout << "City: " << User1.City << endl;
	cout << "Educational: " << User1.EducationalBackGround << endl;
	cout << "Working Before?: " << User1.ItWorksBeforre << endl;
	cout << "Weekly Salary: " << User1.WeeklySalaryWant << endl;
	cout << "Monthly Salary: " << User1.MonthlySalaryWant << endl;
	cout << "Yearly Salary: " << User1.YearlySalaryWant << endl;
	cout << "Hobbies: " << User1.Hobbies << endl;
}

void IfAcceptedForInterview(PersonInfo &User1) {

	if (User1.WeeklySalaryWant < 1200 && User1.ItWorksBeforre == 1) {
			system("color 2F");
			cout << "*************************\n";
			cout << "Accepted To Interview...Good Luck." << endl;

		
	}
	else {
		system("color 4F");
		cout << "Not Accepted To InterView...Good Luck in New Try." << endl;
	}
}

int main() {

	PersonInfo User1;

	PersonInformaions(User1);
	CalculatSalary(User1);
	PrintInfo(User1);
	IfAcceptedForInterview(User1);
	





}