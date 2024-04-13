//
//  roster.cpp
//  Scripting and Programming - Applications
//
//  Created by Tyler Hampton on 4/29/23.
//

#include "roster.hpp"
#include "degree.hpp"
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
}

void Roster::add(string studentID, string firstName, string lastName, int age, int courseDaysIn1, int courseDaysIn2, int courseDaysIn3, string email, DegreeProgram degreeProgram) {
    
    int daysInCourseArray[3] = { courseDaysIn1, courseDaysIn2, courseDaysIn3 };
    Student temp = Student(studentID, firstName, lastName, age, daysInCourseArray, email, degreeProgram);
    
    studentRosterVector.insert(studentRosterVector.end(), temp);
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
    
    add(studentID, firstName, lastName, age, daysInCourse1, daysInCourse2, daysInCourse3, email, degreeProgram);
    
}

// Prints all
void Roster::printAll() {
    cout << "All Roster Information:" << endl;
    for(int i = 0; i < studentRosterVector.size(); i++) {
        studentRosterVector[i].printStudentData();
        cout << endl;
    }
}

// Prints avg number of days in a course by studentID
void Roster::printAverageDaysInCourse(string studentID) {
    int sumDaysIn = 0;
    for(int i = 0; i < studentRosterVector.size(); i++) {
        if(studentRosterVector[i].getID() == studentID) {
            int* tempArray = studentRosterVector[i].getDaysInCourse();
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
    for(int i = 0; i < studentRosterVector.size(); i++) {
        printAverageDaysInCourse(studentRosterVector[i].getID());
    }
}

string Roster::getStudentID(int i) {
    return studentRosterVector[i].getID();
}

// Removes student by studentID
void Roster::removeStudent(string studentID) {
    for(int i = 0; i < studentRosterVector.size(); i++) {
        if(studentRosterVector[i].getID() == studentID) {
            studentRosterVector.erase(studentRosterVector.begin() + i);
            cout << "Removed student " << studentID << endl;
            return;
        }
    }
    cout << "Student " << studentID << " not found in roster" << endl;
}

// Prints all invalid email addresses
void Roster::printInvalidEmails() {
    cout << "Students with invalid email addresses:" << endl;
    for(int i = 0; i < studentRosterVector.size(); i++) {
        string tempEmail = studentRosterVector[i].getEmail();
        if(tempEmail.find(".") == string::npos || tempEmail.find(" ") != string::npos || tempEmail.find("@") == string::npos) {
            cout << "ID: " << studentRosterVector[i].getID() << "\t";
            cout << "First Name: " << studentRosterVector[i].getFirstName() << "\t";
            cout << "Last Name: " << studentRosterVector[i].getLastName() << "\t";
            cout << "Email: " << studentRosterVector[i].getEmail() << "\t";
            cout << endl;
        }
    }
}

// Prints student by degree program
void Roster::printStudentByProgram(DegreeProgram degreeProgram) {
    cout << "Students by program: " << degreeTypes[degreeProgram] << endl;
    for(int i = 0; i < studentRosterVector.size(); i++) {
        string tempProgram = studentRosterVector[i].getProgram();
        if(tempProgram == degreeTypes[degreeProgram]) {
            cout << "ID: " << studentRosterVector[i].getID() << "\t";
            cout << "First Name: " << studentRosterVector[i].getFirstName() << "\t";
            cout << "Last Name: " << studentRosterVector[i].getLastName() << "\t";
            cout << "Age: " << studentRosterVector[i].getAge() << "\t";
            cout << "Email: " << studentRosterVector[i].getEmail() << "\t";
            cout << endl;
        }
    }
}



