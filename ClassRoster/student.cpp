#include "student.h"
#include <iostream>
#include "roster.h"

using namespace std;

Student::Student(string _firstName, string _lastName, string _studentID, string _email, int _age, DegreeProgram _degree, int _numDays[3])
{
	this->firstName = _firstName;
	this->lastName = _lastName;
	this->studentID = _studentID;
	this->emailAddress = _email;
	this->age = _age;
	this->degree = _degree;

	for (int i = 0; i < 3; i++)
	{
		this->numCourseDays[i] = _numDays[i];
	}
}

string Student::GetStudentId() 
{
	return studentID;
}

string Student::GetFirstName() 
{
	return firstName;
}

string Student::GetLastName()  
{
	return lastName;
}

string Student::GetEmail()  
{
	return emailAddress;
}

int Student::GetAge()  
{
	return age;
}

DegreeProgram Student::GetDegreeProgram() 
{
	return degree;
}

int *Student::GetNumberOfDays()  
{
	return numCourseDays;
}


void Student::SetStudentId(string _studentId) 
{
	this->studentID = _studentId;
}

void Student::SetFirstName(string _firstName) 
{
	this->firstName = _firstName;
}

void Student::SetLastName(string _lastName) 
{
	this->lastName = _lastName;
}

void Student::SetEmail(string _email) 
{
	this->emailAddress = _email;
}

void Student::SetAge(int _age) 
{
	this->age = _age;
}

void Student::SetDegreeProgram(DegreeProgram _degree) 
{
	this->degree = _degree;
}

string Student::DegreeProgramToString(DegreeProgram _degree)
{
	if (_degree == DegreeProgram::NETWORK)
	{
		return "Network";
	}
	if (_degree == DegreeProgram::SECURITY)
	{
		return "Security";
	}
	if (_degree == DegreeProgram::SOFTWARE)
	{
		return "Software";
	}
}

void Student::SetNumberOfCourseDays(int _numDays[]) 
{
	for (int i = 0; i < 3; i++)
	{
		this->numCourseDays[i] = _numDays[i];
	}
}

void Student::Print() 
{
	cout << "Student ID: " << this->studentID << '\t';
	cout << "First name: " << this->firstName << '\t';
	cout << "Last name: " << this->lastName << '\t';
	cout << "Age: " << this->age << '\t';
	cout << "Days in course: { " << this->numCourseDays[0] << ", " << this->numCourseDays[1] << ", " << this->numCourseDays[2] << " }" << '\t';
	cout << "Degree program: " << DegreeProgramToString(degree) << endl;
}