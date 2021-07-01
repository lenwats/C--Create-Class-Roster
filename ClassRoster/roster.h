#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include "student.h"

using namespace std;

// Requirement E.1, E.2a, E.2b
// Create an array of pointers; classRosterArray
// Parse each set of data identified in the studentData table
// Add each student object to classRosterArray

class Roster
{
	public:
		Roster();

		void ParseStudentDataTable();

		void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
		void Remove(string studentID);
		void PrintAll();
		void PrintAverageDaysInCourse(string studentID);
		void PrintInvalidEmails();
		void PrintByDegreeProgram(DegreeProgram degreeProgram);

		Student GetStudent(int index);

		~Roster();

	private:
		Student* classRosterArray[5];
		int ROSTER_SIZE = 5;
		int Index = 0;
};

#endif ROSTER_H
