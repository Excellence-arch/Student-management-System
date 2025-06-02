#ifndef STUDENT_H
#define STUDENT_H

#include <string>


// Pragma once STUDENT;
class Student {
private:
    std::string name;
    int score;

public:
    // Constructor
    Student(std::string studentName, int studentScore) : name(studentName), score(studentScore) {}

    // Student(std::string studentName) {
    //     name = studentName;
    // }

    std::string getName() const {
        return name;
    }

    int getScore() const {
        return score;
    }
};

#endif