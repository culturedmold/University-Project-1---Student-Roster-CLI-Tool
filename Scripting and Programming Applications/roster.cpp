//
//  roster.cpp
//  Scripting and Programming - Applications
//
//  Created by Tyler Hampton on 4/29/23.
//

#include "roster.hpp"
#include "degree.h"
#include "student.hpp"
#include <iostream>
#include <vector>

using namespace std;


// CONSTRUCTOR
Roster::Roster() {
}

// DESTRUCTOR
Roster::~Roster() {
    cout << "Calling Destructor...";

    for(int i = 0; i < numStudents; i++) {
        delete studentRosterArray[i];
        studentRosterArray[i] = nullptr;
    }
}

void Roster::add(string studentID, string firstName, string lastName, int age, int courseDaysIn1, int courseDaysIn2, int courseDaysIn3, string email, DegreeProgram degreeProgram) {
    
    int daysInCourseArray[3] = { courseDaysIn1, courseDaysIn2, courseDaysIn3 };
    
    studentRosterArray[index] = new Student(studentID, firstName, lastName, age, daysInCourseArray, email, degreeProgram);
}

// Add student to roster
void Roster::parse(string data) {
    
    size_t right = data.find(",");
    string studentID = data.substr(0, right);
    
    size_t left = (right + 1);
    right = data.find(",", left);
    string firstName = data.substr(left, right - left);
    
    left = (right + 1);
    right = data.find(",", left);
    string lastName = data.substr(left, right - left);
    
    left = (right + 1);
    right = data.find(",", left);
    string email = data.substr(left, right - left);
    
    left = (right + 1);
    right = data.find(",", left);
    int age = stoi(data.substr(left, right - left));
    
    left = (right + 1);
    right = data.find(",", left);
    int daysInCourse1 = stoi(data.substr(left, right - left));
    
    left = (right + 1);
    right = data.find(",", left);
    int daysInCourse2 = stoi(data.substr(left, right - left));
    
    left = (right + 1);
    right = data.find(",", left);
    int daysInCourse3 = stoi(data.substr(left, right - left));
    
    DegreeProgram degreeProgram{};
    
    left = (right + 1);
    string program = data.substr(left);
    
    if(program == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }
    else if(program == "NETWORK") {
        degreeProgram = NETWORK;
    }
    else if(program == "SECURITY") {
        degreeProgram = SECURITY;
    }
    
    index++;
    
    add(studentID, firstName, lastName, age, daysInCourse1, daysInCourse2, daysInCourse3, email, degreeProgram);
    
}

// Prints all
void Roster::printAll() {
    cout << "All Roster Information:" << endl;
    for(int i = 0; i < numStudents; i++) {
        if(studentRosterArray[i] == nullptr) {
            continue;
        }
        studentRosterArray[i]->printStudentData();
        cout << endl;
    }
}

// Prints avg number of days in a course by studentID
void Roster::printAverageDaysInCourse(string studentID) {
    int sumDaysIn = 0;
    for(int i = 0; i < numStudents; i++) {
        if(studentRosterArray[i]->getID() == studentID) {
            int* tempArray = studentRosterArray[i]->getDaysInCourse();
            for(int j = 0; j < 3; j++) {
                sumDaysIn += tempArray[j];
            }
            cout << "Average days in course for student " << studentID << ": " << sumDaysIn / 3 << endl;
            return;
        }
    }
    cout << "No average days in courses found. Student " << studentID << " not found in roster." << endl;
}

void Roster::printAllAvgDaysInCourse() {
    for(int i = 0; i < numStudents; i++) {
        printAverageDaysInCourse(studentRosterArray[i]->getID());
    }
}

string Roster::getStudentID(int i) {
    return studentRosterArray[i]->getID();
}

// Removes student by studentID
void Roster::removeStudent(string studentID) {
    for(int i = 0; i < numStudents; i++) {
        if(studentRosterArray[i] == nullptr) {
            continue;
        }
        if(studentRosterArray[i]->getID() == studentID) {
            studentRosterArray[i] = nullptr;
            cout << "Removed student " << studentID << endl;
            return;
        }
    }
    cout << "Student " << studentID << " not found in roster" << endl;
}

// Prints all invalid email addresses
void Roster::printInvalidEmails() {
    cout << "Students with invalid email addresses:" << endl;
    for(int i = 0; i < numStudents; i++) {
        if(studentRosterArray[i] == nullptr) {
            continue;
        }
        string tempEmail = studentRosterArray[i]->getEmail();
        if(tempEmail.find(".") == string::npos || tempEmail.find(" ") != string::npos || tempEmail.find("@") == string::npos) {
            cout << "ID: " << studentRosterArray[i]->getID() << "\t";
            cout << "First Name: " << studentRosterArray[i]->getFirstName() << "\t";
            cout << "Last Name: " << studentRosterArray[i]->getLastName() << "\t";
            cout << "Email: " << studentRosterArray[i]->getEmail() << "\t";
            cout << endl;
        }
    }
}

// Prints student by degree program
void Roster::printStudentByProgram(DegreeProgram degreeProgram) {
    cout << "Students by program: " << degreeTypes[degreeProgram] << endl;
    for(int i = 0; i < numStudents; i++) {
        if(studentRosterArray[i] == nullptr) {
            continue;
        }
            string tempProgram = studentRosterArray[i]->getProgram();
        if(tempProgram == degreeTypes[degreeProgram]) {
            cout << "ID: " << studentRosterArray[i]->getID() << "\t";
            cout << "First Name: " << studentRosterArray[i]->getFirstName() << "\t";
            cout << "Last Name: " << studentRosterArray[i]->getLastName() << "\t";
            cout << "Age: " << studentRosterArray[i]->getAge() << "\t";
            cout << "Email: " << studentRosterArray[i]->getEmail() << "\t";
            cout << endl;
        }
    }
}



