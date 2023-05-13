//
//  student.cpp
//  Scripting and Programming - Applications
//
//  Created by Tyler Hampton on 4/28/23.
//

#include "student.hpp"
#include <iostream>
#include <string>

using namespace std;

// CONSTRUCTOR to set default empty values
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->age = 0;
    this->email = "";
    this->degreeProgram = SOFTWARE;
    
    for(int i = 0; i < 3; i++) {
        this->daysInCourseArray[i] = i;
    }
}

// Main CONSTRUCTOR
Student::Student(string studentID, string firstName, string lastName, int age, int daysInCourses[], string email, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->email = email;
    this->degreeProgram = degreeProgram;
    
    // loop through array passed into constructor and assign values to daysInCourseArray accordingly
    for(int i = 0; i < 3; i++) {
        daysInCourseArray[i] = daysInCourses[i];
    }
}

// DESTRUCTOR
Student::~Student() {};

// GETTERS
string Student::getID() {
    return studentID;
}
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}
int Student::getAge() {
    return age;
}
string Student::getEmail() {
    return email;
}
string Student::getProgram() {
    return degreeTypes[(int)degreeProgram];
}
int* Student::getDaysInCourse() {
    return daysInCourseArray;
}

void Student::printStudentData() {
    cout << "ID: " << getID() << "\t";
    cout << "First Name: " << getFirstName() << "\t";
    cout << "Last Name: " << getLastName() << "\t";
    cout << "Age: " << getAge() << "\t";
    cout << "Email: " << getEmail() << "\t";
    cout << "Days In Courses: ";
    printDaysInCourse();
    cout << "\t";
    cout << "Program: " << getProgram() << "\t";
}

void Student::printDaysInCourse() {
    cout<< "[ ";
    for(int i = 0; i < 3; i++) {
        cout << daysInCourseArray[i] << " ";
    }
    cout << "]";
}

// SETTERS
void Student::setID(string ID) {
    studentID = ID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setEmail(string email) {
    this->email = email;
}
void Student::setDaysInCourses(int *daysInCourseArray) {
    for(int i = 0; i < 3; i++) {
        daysInCourseArray[i] = this->daysInCourseArray[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}


