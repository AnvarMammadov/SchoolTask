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


void WriteFile(School* school) {
	FILE* file;
	fopen_s(&file, "school.txt", "w");
	for (size_t i = 0; i < school->count; i++)
	{
		fwrite(school->students[i]->name, sizeof(char), strlen(school->students[i]->name), file);
		fwrite(" ", sizeof(char), 1, file);
		fwrite(school->students[i]->surname, sizeof(char), strlen(school->students[i]->surname), file);
		fwrite(" ", sizeof(char), 1, file);
		string strAge = to_string(school->students[i]->age);
		char* charAge = new char[strAge.length() + 1] {};
		strcpy_s(charAge, strAge.length() + 1, strAge.c_str());
		fwrite(charAge, sizeof(char), strlen(charAge), file);
		fwrite("\n", sizeof(char), strlen("\n"), file);
		delete[]charAge;
		charAge = nullptr;
	}
	fclose(file);
}


void AddStudentToFile(Student* student) {
	FILE* file;
	fopen_s(&file, "school.txt", "a");
	fwrite(student->name, sizeof(char), strlen(student->name), file);
	fwrite(student->surname, sizeof(char), strlen(student->surname), file);
	string strAge = to_string(student->age);
	char* charAge = new char[strAge.length() + 1];
	strcpy_s(charAge, strAge.length() + 1, strAge.c_str());
	fwrite(charAge, sizeof(char), strlen(charAge), file);
	delete[]charAge;
	charAge = nullptr;
	fclose(file);
}

void main() {
	system("color f0");
	enum Operation { show = '1', add = '2', delet = '3' };
	School* school = new School{ new Student * [2] {new Student{new char[30] {"Anvar"},new char[30] {"Mammadov"},21},
		new Student{new char[30] {"Murad"},new char[30] {"Qojayev"},20}},2 };
	WriteFile(school);
	while (true) {
		system("cls");
		ShowMenu();
		char select;
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
			AddStudentToFile(student);
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
				WriteFile(school);
				cout << "Student deleted successfully.." << endl;
				system("pause");
			}
			else {
				cout << "Not Found ID.." << endl;
				system("pause");
			}
		}
		else {
			cout << "Not found this operation.." << endl;
			system("pause");
		}
	}
	cout << endl << endl << endl; cin.get();
}
