#pragma once
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster
{
public:
	const static int numStudents = 5;
	Student* classRosterArray[numStudents]; // array of pointers to hold the data provided in the “studentData Table.”

	void parseAndAdd(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);

	~Roster(); //destructor to release the memory that was allocated dynamically in Roster.

private:
	int index = -1;
	int i = 0;
};
