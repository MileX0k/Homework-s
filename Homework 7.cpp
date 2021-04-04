
#include <iostream>
#include "Functions.h"
#include <fstream>

using namespace std;
using namespace MyLib; // Пятая часть ДЗ:

// Вторая часть ДЗ:

#define CHEK(x,y) ((x) >= 0 && (x) < y ? cout << "true" : cout << "false")

void EnterNum()
{
	int firstnum, finsh;
	cout << "Enter your number: ";
	cin >> firstnum;
	cout << "Enter your number: ";
	cin >> finsh;
	CHEK(firstnum, finsh);
	cout << endl;
}

// Третья часть ДЗ:

#define SIZE 6

#define SORTBUBLE(a,b) int g = 0; g=a; a=b; b=g  

void Task3()
{
	
	int Buble[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cin >> Buble[i];
	}

	for (size_t j = 0; j < SIZE; j++)
	{
		for (size_t i = 0; i < SIZE - 1; i++)
		{
			if (Buble[i] > Buble[i + 1])
			{
				SORTBUBLE(Buble[i], Buble[i + 1]);
			}
		}
	}
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << Buble[i] << " ";
	}
	cout << endl;
}

// Четвертая часть ДЗ:

#pragma pack(push, 1)
struct Employee
{
	int id;
	string country;
	float salary;
	int age;
};

void Task4()
{
	Employee* pEmployee = new Employee;
	
	cout << "Employee:" << endl;
	pEmployee->age = 32;
	pEmployee->country = "Russia";
	pEmployee->id = 5123;
	pEmployee->salary = 31'581.0;
	
	ofstream fout("Employee.txt");
	if (fout.is_open())
	{
		fout << "Employee: " << endl << "id: " << pEmployee->id << endl;
		fout << "Country: " << pEmployee->country << endl;
		fout << "Salary: " << pEmployee->salary << endl;
		fout << "Age: " << pEmployee->age << endl;
	}
	
	cout << pEmployee->country << endl;
	cout << "Structs size: " << sizeof(Employee);

	delete pEmployee;
}


int main()
{
	FunctionArray();   // Первая часть ДЗ 

	EnterNum();  // Вторая часть ДЗ
	
	Task3(); // Третья часть ДЗ
	
	Task4(); // Четвертая часть ДЗ:
}

