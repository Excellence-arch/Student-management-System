#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include "Student.hpp"


// struct STudent {
//     std::string name;
//     int score;
// };

class StudentList {
private:
    std::vector<Student> students;

public:
    StudentList();
    void addStudent(const Student& student);

    bool saveToFile(const std::string& filename);

    bool loadFromFile(const std::string& filename);

    double calculateAverageScore() const;

    void generateReport(const std::string& outputFilename);

    void collectStudentDataInteractively();

    bool isEmpty() const;
};

#endif 
