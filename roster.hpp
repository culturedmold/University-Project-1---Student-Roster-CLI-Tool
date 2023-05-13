//
//  roster.hpp
//  Scripting and Programming - Applications
//
//  Created by Tyler Hampton on 4/29/23.
//

#ifndef roster_hpp
#define roster_hpp
#include "degree.h"
#include "student.hpp"

#include <stdio.h>
#include <iostream>

using namespace std;

class Roster {
    
public:
    const static int numStudents = 5;
    int index = -1; // Help us keep track of the index where we need to place our new student via parse and add methods
    
    // CONSTRUCTOR
    Roster();
    
    // Array of pointers
    Student* studentRosterArray[5];
    
    // DESTRUCTOR
    ~Roster();
    
    // Parse student data
    void parse(string data);
    
    // Add student to roster
    void add(string studentID, string firstName, string lastName, int age, int courseDaysIn1, int courseDaysIn2, int courseDaysIn3, string email, DegreeProgram degreeProgram);
    
    // Prints all
    void printAll();
    
    // Prints avg number of days in a course by studentID
    void printAverageDaysInCourse(string studentID);
    
    // Prints avg number of days in a course for all students in roster
    void printAllAvgDaysInCourse();
    
    // Gets a studentID given an integer to pass as index in studentRosterArray
    string getStudentID(int i);
    
    // Removes student by studentID
    void removeStudent(string studentID);
    
    // Prints all invalid email addresses
    void printInvalidEmails();
    
    // Prints student by degree program
    void printStudentByProgram(DegreeProgram degreeProgram);
    
};

#endif /* roster_hpp */
