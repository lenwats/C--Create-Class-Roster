#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
using namespace std;



int main()
{
	cout << "Course Title: Scripting and Programming - Applications C867\n";
	cout << "Language: C++\n";
	cout << "Student ID: #001425432\n";
	cout << "Name: Lenore Watson\n\n";

	Roster classRoster;

	classRoster.ParseStudentDataTable();
	cout << endl;

	classRoster.PrintAll();
	cout << endl;

	classRoster.PrintInvalidEmails();
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		Student student = classRoster.GetStudent(i);
		classRoster.PrintAverageDaysInCourse(student.GetStudentId());
	}
	cout << endl;

	classRoster.PrintByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.Remove("A3");
	cout << endl;

	classRoster.PrintAll();
	cout << endl;

	classRoster.Remove("A3");

	classRoster.~Roster();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

