#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <algorithm>
#include "Student.h"

class StudentList {
private:
    std::vector<Student> students;

public:
    // Method to add a student to the list
    void addStudent(const Student& student);

    // Method to save the student list to a file
    bool saveToFile(const std::string& filename);

    // Method to load the student list from a file
    bool loadFromFile(const std::string& filename);

    // Method to calculate the average score of all students
    double calculateAverageScore() const;

    // Method to generate a report and save it to a file
    void generateReport(const std::string& outputFilename);

    // Method to interactively collect student data from the user
    void collectStudentDataInteractively();

    // Method to check if the student list is empty
    bool isEmpty() const;
};

#endif // STUDENTLIST_H
