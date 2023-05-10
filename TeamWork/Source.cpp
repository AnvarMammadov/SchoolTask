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
	School* school = new School{ new Student * [2] {new Student{new char[30] {"Anvar"},new char[30] {"Mammadov"},21},
		new Student{new char[30] {"Murad"},new char[30] {"Qojayev"},20}},2 };
	enum Operations { show = '1', add = '2', delet = '3' };
	while (true)
	{
		system("cls");
		ShowMenu();
		char select = NULL;
		cin >> select;
		if (select == show) {
			system("cls");
			ShowAllStudent(school);
			system("pause");
		}
		else if (select == add) {
			system("cls");
			auto student = GetNewStudent();
			AddStudenteToSchool(school, student);
			cout << "Student added successfully.." << endl;
			system("pause");

		}
		else if (select == delet) {
			cin.ignore();
			cin.clear();
			system("cls");
			ShowAllStudent(school);
			cout << "Enter student ID for delete from school students list : ";
			int id = 0;
			cin >> id;
			if (id > 0 && id <= school->count) {
				int index = id - 1;
				DeleteStudent(school, index);
				cout << "Student deleted successfully.." << endl;
				system("pause");
			}
			else {
				cout << "Not Found ID.." << endl;
				system("pause");
			}
		}
		else {
			cout << "Operation not found.." << endl;
		}
	}
	cout << endl << endl; cin.get();
}
