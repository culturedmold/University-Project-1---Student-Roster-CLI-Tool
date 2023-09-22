# Student-Roster-Command-Line-Tool

## Overview:
This project is a fairly straightforward exercise in pointers, parsing, and OOP concepts. The program takes an input string, parses the data, and creates an array of Student objects and outputs the data to console. Various methods are implemented to handle incorrectly formatted data (such as e-mail addresses). 

This was the first formal project presented in my Computer Science bachelors degree, and was a great introduction to OOP, pointers, arrays, and basic data structures/algorithms.

## Future Enhancements
The program has very limited utility due to the following external requirements:
1. Array was required to be used instead of vector to handle the Student objects
2. No storage - everything is done in memory

To solve problem 1, I would use a vector of Student objects. This would allow the user to enter as many or as little "students" into the parsing function and would resize as necessary, greatly increasing the utility of the program. 

To solve problem 2, I would use a lightweight local database (such as sqlite3) to store the data. This would eliminate the cumbersome step of having to re-enter all data each time the application is opened. Using a fixed-size array was an external requirement that I had to follow, but a vector would be ideal.

The application was intentionally lightweight. However, a simple GUI could significantly improve the tool's usability for an average user. 
