//
//  roster.hpp
//  Scripting and Programming - Applications
//
//  Created by Tyler Hampton on 4/29/23.
//

#ifndef roster_hpp
#define roster_hpp
#include "degree.hpp"
#include "student.hpp"

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Roster {
    
public:
    
    // CONSTRUCTOR
    Roster();
    
    // Array of pointers
    std::vector<Student> studentRosterVector;
    
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
