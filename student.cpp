#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (i = 0; i < DaysInCourseArraySize; ++i) {
        this->daysInCourse[i] = 0;
    }
    this->degreeprogram = DegreeProgram::SECURITY;
}

//constructor using all of the input parameters from the data table
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeprogram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (i = 0; i < DaysInCourseArraySize; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeprogram = degreeprogram;
}

Student::~Student() {}

//accessor (i.e., getter) for each instance variable from part D1
string Student::GetStudentID() {
    return studentID;
}
string Student::GetFirstName() {
    return firstName;
}
string Student::GetLastName() {
    return lastName;
}
string Student::GetEmailAddress() {
    return emailAddress;
}
int Student::GetAge() {
    return age;
}
int* Student::GetDaysInCourse() {
    return daysInCourse;
}
DegreeProgram Student::GetDegreeProgram() {
    return degreeprogram;
}

//mutator (i.e., setter) for each instance variable from part D1
void Student::SetStudentID(string idToSet) {
    this->studentID = idToSet;
}
void Student::SetFirstName(string firstNameToSet) {
    this->firstName = firstNameToSet;
}
void Student::SetLastName(string lastNameToSet) {
    this->lastName = lastNameToSet;
}
void Student::SetEmailAddress(string emailAddressToSet) {
    this->emailAddress = emailAddressToSet;
}
void Student::SetAge(int ageToSet) {
    this->age = ageToSet;
}
void Student::SetDaysInCourse(int daysToSet[]) {
    for (i = 0; i < DaysInCourseArraySize; i++) {
        this->daysInCourse[i] = daysToSet[i];
    }
}
void Student::SetDegreeProgram(DegreeProgram degreeToSet) {
    degreeprogram = degreeToSet;
}

//print() to print specific student data - provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
void Student::print() {
    cout << GetStudentID() << "\t" << "First Name: " << GetFirstName() << "\t" << "Last Name: " << GetLastName() << "\t" << "Age: " << GetAge() << "\t";
    cout << "daysInCourse:  {" << GetDaysInCourse()[0] << ", " << GetDaysInCourse()[1] << ", " << GetDaysInCourse()[2] << "} " << "Degree Program: ";
    cout << degreeString[(int)GetDegreeProgram()] << endl;
}