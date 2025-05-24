#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int score;

public:
    // Constructor
    Student(std::string studentName, int studentScore) : name(studentName), score(studentScore) {}

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Getter for score
    int getScore() const {
        return score;
    }
};

#endif // STUDENT_H