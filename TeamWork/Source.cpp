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


void ShowStudent(Student* student) {
	cout << "Name : " << student->name << endl;
	cout << "Surname : " << student->surname << endl;
	cout << "Age : " << student->age << endl;
}


void ShowAllStudent(School* school) {
	cout << "=====Students Infos=====" << endl << endl;
	for (size_t i = 0; i < school->count; i++)
	{
		cout << "ID : " << i + 1 << endl;
		ShowStudent(school->students[i]);
		cout << "--------------------------------" << endl;
	}
}


Student* GetNewStudent() {
	cin.ignore();
	cin.clear();
	cout << "Enter name : ";
	char* name = new char[30];
	cin.getline(name, 30);
	cout << "Enter surname : ";
	char* surname = new char[30];
	cin.getline(surname, 30);
	cout << "Enter age : ";
	int age = 0;
	cin >> age;
	return new Student{ name,surname,age };
}


void AddStudenteToSchool(School*& school, Student* student) {
	auto temp = new School{ new Student * [school->count + 1],school->count + 1 };
	for (size_t i = 0; i < school->count; i++)
	{
		temp->students[i] = school->students[i];
	}
	temp->students[school->count] = student;
	school = temp;
	temp = nullptr;
}


void DeleteStudent(School*& school, int index) {
	auto temp = new School{ new Student * [school->count - 1],school->count - 1 };
	for (size_t i = 0; i < index; i++)
	{
		temp->students[i] = school->students[i];
	}
	for (size_t i = index + 1; i < school->count; i++)
	{
		temp->students[i - 1] = school->students[i];
	}
	school = temp;
	temp = nullptr;
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