#include <iostream>
using namespace std;
#include <string>

//===========================================TASK 1================================================
class Person
{
private:
	string name = "";
	int age = 0;
	char gender = ' ';
	int weight = 0;

public:

	Person() {};

	Person(string n, int a, char g, int w) 
		:name (n), age (a), gender (g), weight (w) {
	};




	void Print()
	{
		cout << "Name: " << name << "\n" << "Age: " << age << "\n" << "Gender: " << gender << "\n" << "Weight: " << weight << "\n";

	}
};



class Student : public Person
{
public:
	int studAge;
	int sumStud = 0;    // ДОДЕЛАТЬ СЧЁТЧИК!!

	Student(string n, int a, char g, int w, int stA)
		: Person(n, a, g, w), studAge(stA)
	{ };

	void Print()
	{
		sumStud++;
		cout << endl << "Student  " << sumStud << ":" << endl;
		Person::Print();
		cout << "Year of study: " << studAge << "\n";
	}
};

//===========================================TASK 2================================================




int main()
{
	//===========================================TASK 1================================================
	cout << "    TASK 1:     " << endl << endl;


	Person person1{"Petr", 23, 'M', 78 };
	person1.Print();

	Student student1{ "Vasya", 21, 'M', 65, 2010 };
	Student student2{ "Lena", 20, 'F', 48, 2011 };
	Student student3{ "Kirill", 19, 'M', 83, 2009 };
	Student student4{ "Kate", 23, 'F', 50, 2007 };
	
	student4.Print();
	
	
	//===========================================TASK 2================================================



	return 0;
}

