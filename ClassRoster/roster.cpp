#include "roster.h"
#include "student.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>

// Requirement A. Modify the studentData table to include your personal information as the last item
const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
  "A5,Lenore,Watson,lwat127@wgu.edu,33,6,6,7,SOFTWARE"
};

Roster::Roster() {}

Student Roster::GetStudent(int index)
{
	return *classRosterArray[index];
}

void Roster::ParseStudentDataTable()
{
	for (int i = 0; i < ROSTER_SIZE; i++)
	{
		vector<string> dataArray;
		string dataRow = studentData[i];
		stringstream stream(dataRow);
		string items;

		while (stream.good())
		{
			getline(stream, items, ',');
			dataArray.push_back(items);
		}

		string degreeIndex = dataArray.at(8);
		DegreeProgram degree;

		if (degreeIndex == "SECURITY")
		{
			degree = DegreeProgram::SECURITY;
		}
		if (degreeIndex == "NETWORK")
		{
			degree = DegreeProgram::NETWORK;
		}
		if (degreeIndex == "SOFTWARE")
		{
			degree = DegreeProgram::SOFTWARE;
		}

		Add(dataArray.at(0), dataArray.at(1), dataArray.at(2), dataArray.at(3), stoi(dataArray.at(4)), stoi(dataArray.at(5)), stoi(dataArray.at(6)), stoi(dataArray.at(7)), degree);
	}
}

// Requirement 3.A 
// Sets the instance variables from part D1 and updates the roster
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int numDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	Student* student = new Student(firstName, lastName, studentID, emailAddress, age, degreeprogram, numDays);

	student->SetFirstName(firstName);
	student->SetLastName(lastName);
	student->SetStudentId(studentID);
	student->SetEmail(emailAddress);
	student->SetAge(age);
	student->SetDegreeProgram(degreeprogram);
	student->SetNumberOfCourseDays(numDays);

	classRosterArray[Index++] = student;
}

// Requirement 3.B
// Removes students from the roster by student ID. 
// If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::Remove(string studentID)
{
	bool success = false;

	for (int i = 0; i < Index; i++)
	{
		string id = classRosterArray[i]->GetStudentId();

		if (classRosterArray[i] != nullptr && id == studentID)
		{
			success = true;

			if (i < ROSTER_SIZE - 1)
			{
				Student* swappedStudent = classRosterArray[i];
				classRosterArray[i] = classRosterArray[ROSTER_SIZE - 1];
				classRosterArray[ROSTER_SIZE - 1] = swappedStudent;
			}
			Index--;
		}		
	}
	if (success)
	{
		cout << "Student " << studentID << " was deleted from roster." << endl;
	}
	else
	{
		cout << "Student " << studentID << " was not found OR was removed and is not listed anymore." << endl;
	}
}

// Requirement 3.C
// Prints a complete tab-separated list of student data
void Roster::PrintAll()
{
	for (int i = 0; i < Index; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			classRosterArray[i]->Print();
		}
	}
}

// Requirement 3.D
// Prints a student’s average number of days in the three courses. The student is identified by the studentID parameter
void Roster::PrintAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < Index; i++)
	{
		string id = classRosterArray[i]->GetStudentId();

		if (classRosterArray[i] != nullptr && id == studentID)
		{
			int* numberOfDays = classRosterArray[i]->GetNumberOfDays();
			float average = float(numberOfDays[0] + numberOfDays[1] + numberOfDays[2]) / 3;

			cout << "Student " << studentID << "'s average number of days in three courses is " << average << "." << endl;
		}
	}
}

// Requirement 3.E
// Verifies student email addresses and displays all invalid email addresses to the user
// A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
// First, a function that uses regex to validate emails
bool ValidateEmail(string email) 
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);
}
void Roster::PrintInvalidEmails()
{
	for (int i = 0; i < Index; i++)
	{
		string email = classRosterArray[i]->GetEmail();

		if (ValidateEmail(email))
		{
			return;
		}
		else
		{
			cout << "Student " << classRosterArray[i]->GetStudentId() << " has an invalid email: " << email << endl;
		}
	}
}

// Requirement 3.F
// Prints out student information for a degree program specified by an enumerated type
void Roster::PrintByDegreeProgram(DegreeProgram degree)
{
	for (int i = 0; i <= 4; i++) 
	{		
		DegreeProgram getDegree = classRosterArray[i]->GetDegreeProgram();

		if (getDegree == degree)
		{
			string degrees = classRosterArray[i]->DegreeProgramToString(degree);

			cout << "This student is in the " << degrees << " program:" << endl;
			classRosterArray[i]->Print();
		}
	}
}

Roster::~Roster() {}
