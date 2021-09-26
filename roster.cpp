#pragma once
#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

//create a student object for each student in the data table and populate classRosterArray.
void Roster::parseAndAdd(string studentData) { 
	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	DegreeProgram degreeprogram;
	string degreeString = studentData.substr(lhs, rhs - lhs);
	if (degreeString == "SECURITY") {
		degreeprogram = DegreeProgram::SECURITY;
	}
	else if (degreeString == "NETWORK") {
		degreeprogram = DegreeProgram::NETWORK;
	}
	else if (degreeString == "SOFTWARE") {
		degreeprogram = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

//sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysInCourse[Student::DaysInCourseArraySize]{daysInCourse1, daysInCourse2, daysInCourse3};
	classRosterArray[++index] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
}
//removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string studentID) {
	bool found = false;
	for (i = 0; i <= Roster::index; i++) {
			if (classRosterArray[i]->GetStudentID() == studentID) {
				found = true;
				if (i < numStudents - 1) {
					Student* temp = classRosterArray[i];
					classRosterArray[i] = classRosterArray[numStudents - 1];
					classRosterArray[numStudents - 1] = temp;
				}
				Roster::index--;
				
				//swaps new last index to maintain proper formatting (A1, A2, A4, A5)
				Student* temp = classRosterArray[Roster::index];
				classRosterArray[Roster::index] = classRosterArray[Roster::index - 1];
				classRosterArray[Roster::index - 1] = temp;
			}
	}
	if (found) {
		cout << "Student " << studentID << " has been removed" << endl;
	}
	else {
		cout << "Student " << studentID << " was not found" << endl;
	}
}

//prints a complete tab-separated list of student data
//loop through all the students in classRosterArray and call the print() function for each student.
void Roster::printAll() {
	cout << "List of Student Data" << endl;
	for (i = 0; i <= Roster::index; i++) {
		classRosterArray[i]->print();
	}
}

//prints a student’s average number of days in the three courses by student ID. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) {
	for (i = 0; i <= Roster::index; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			cout << studentID << " | ";
			cout << ((classRosterArray[i]->GetDaysInCourse()[0] + classRosterArray[i]->GetDaysInCourse()[1] + classRosterArray[i]->GetDaysInCourse()[2]) / 3);
			cout << endl;
		}

	}
}

//verifies student email addresses and displays all invalid email addresses to the user.
//valid email should include an at sign('@') and period('.') and should not include a space(' ').
void Roster::printInvalidEmails() {
	bool invalid = false;
	for (i = 0; i <= Roster::index; i++) {
		string emailAddress = (classRosterArray[i]->GetEmailAddress());
		string studentID = (classRosterArray[i]->GetStudentID());
		if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos || emailAddress.find(' ') != string::npos) {
			invalid = true;
			cout << studentID << " | "<< emailAddress << endl;
		}
		else if (!invalid) {
			cout << "No Invalid Email Addresses" << endl;
		}
	}
}

//prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	for (i = 0; i <= Roster::index; i++) {
		if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeprogram) {
			classRosterArray[i]->print();
		}
	}
}

//destructor to release the memory that was allocated dynamically in Roster.
Roster::~Roster() {
	for (i = 0; i < numStudents; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}