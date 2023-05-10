#include <iostream>
#include<string>
using namespace std;
struct Student {
	char* name;
	char* surname;
	int age;
};
struct School {
	Student** students;
	int count;
};
void ShowMenu() {
	cout << "Show All Student  [1] " << endl;
	cout << "Add New Student   [2] " << endl;
	cout << "Delete Student    [3] " << endl;
}
void main() {
	system("color f0");
	enum Operations { show = '1', add = '2', delet = '3' };
	while (true)
	{
		system("cls");
		ShowMenu();
		char select = NULL;
		cin >> select;
		if (select == show) {

		}
		else if (select == add) {

		}
		else if (select == delet) {

		}
		else {
			cout << "Operation not found.." << endl;
		}
	}


	cout << endl << endl; cin.get();
}