#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;


// Requirements D.1, D.2
// Create the Student class and the variables
// Create the functions for the Student class

class Student
{
	public:
		Student(string firstName, string lastName, string studentID, string email, int age, DegreeProgram degree, int numDays[3]);
		string GetStudentId();
		string GetFirstName();
		string GetLastName();
		string GetEmail();
		int GetAge();
		DegreeProgram GetDegreeProgram();
		int* GetNumberOfDays();

		void Print();

		void SetStudentId(string _studentId);
		void SetFirstName(string _firstName);
		void SetLastName(string _lastName);
		void SetEmail(string _email);
		void SetAge(int _age);
		void SetDegreeProgram(DegreeProgram _degree);
		string DegreeProgramToString(DegreeProgram _degree);
		void SetNumberOfCourseDays(int _numDays[]);

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int numCourseDays[3];
		DegreeProgram degree;
};
#endif
