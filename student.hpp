//
//  student.hpp
//  Scripting and Programming - Applications
//
//  Created by Tyler Hampton on 4/28/23.
//

#ifndef student_hpp
#define student_hpp

#include <iostream>
#include "degree.hpp"
#include <string>

using namespace std;

class Student {
private:
    // class variables
    string studentID;
    string firstName;
    string lastName;
    int age;
    int daysInCourseArray[3];
    string email;
    DegreeProgram degreeProgram;
    
public:
    // CONSTRUCTOR
    Student();
    Student(string studentID, string firstName, string lastName, int age, int daysInCourses[], string email, DegreeProgram degreeProgram);

    ~Student();

    // GETTERS
    string getID();
    string getFirstName();
    string getLastName();
    int getAge();
    string getEmail();
    string getProgram();
    int* getDaysInCourse();
    
    // SETTERS
    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setAge(int age);
    void setEmail(string email);
    void setDaysInCourses(int *daysInCourseArray);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    // Print all student data (call all getters)
    void printStudentData();
    void printDaysInCourse();
    
};

#endif /* student_hpp */
