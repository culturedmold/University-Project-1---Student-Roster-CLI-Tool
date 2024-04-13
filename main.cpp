//
//  main.cpp
//  Scripting and Programming - Applications
//
//  Created by Tyler Hampton on 4/28/23.
//

#include <iostream>
#include "student.hpp"
#include "degree.hpp"
#include "roster.hpp"
#include <vector>

int main(void) {
    // Application title
    cout << "Course Title: Scripting and Programming Applications"<< endl;
    cout << "Course Number: C867" << endl;
    cout << "Language Used for Project: C++" << endl;
    cout << "Name: Cory Hampton (Tyler)" << endl;
    cout << "WGU StudentID: 010739720" << endl;
    cout << endl;
    cout << endl;
    
    // student roster data
    std::vector<std::string> studentData = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Cory,Hampton,champ85@wgu.edu,27,3,5,14,SOFTWARE"
    };
    
    // This is our roster object in action
    Roster classRoster;
    
    // loop through newRoster, parse data
    // parse function calls add function, which constructs a student object for each element of newRoster array
    for(int i = 0; i < studentData.size(); i++) {
        classRoster.parse(studentData[i]);
    }
    
    // print all data in roster
    classRoster.printAll();
    cout << endl;
    
    // print all students with invalid email addresses
    classRoster.printInvalidEmails();
    cout << endl;
    
    // loop to print avg days in course for student, using a getter to retrieve studentID
    for(int i = 0; i < classRoster.studentRosterVector.size(); i++) {
        classRoster.printAverageDaysInCourse(classRoster.getStudentID(i));
    }
    cout << endl;
    
    // prints all students in a given degree program
    classRoster.printStudentByProgram(SOFTWARE);
    cout << endl;
    
    // removes a student by student ID
    classRoster.removeStudent("A3");
    cout << endl;
    
    classRoster.printAll();
    cout << endl;
    
    // removes a student... will return message to indicate that student "A3" has already been deleted
    classRoster.removeStudent("A3");
    cout << endl;
    
    // call to destructor... happens automatically?
    //    classRoster.~Roster();

    cout << endl;
    
    return 0;
}

