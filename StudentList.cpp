#include "StudentList.hpp"
#include "Student.hpp" // Though included in StudentList.h, good practice for .cpp
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>   // Required for std::numeric_limits
#include <algorithm> // Required for std::max_element, std::min_element
#include <iomanip>  // Required for std::fixed and std::setprecision

// Method to add a student to the list
void StudentList::addStudent(const Student& student) {
    students.push_back(student);
}
StudentList::StudentList(){};

// Method to save the student list to a file
bool StudentList::saveToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for saving." << std::endl;
        return false;
    }

    for(long unsigned int i = 0; i < students.size(); i++) {
        outFile << students[i].getName() << " " << students[i].getScore() << std::endl;

    }
    // for (const auto& student : students) {
    //     outFile << student.getName() << " " << student.getScore() << std::endl;
    // }

    outFile.close();
    return true;
}

bool StudentList::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for loading." << std::endl;
        return false;
    }

    students.clear(); // Clear existing students before loading
    std::string name;
    int score;
    while (inFile >> name >> score) {
        students.emplace_back(name, score);
    }

    if (inFile.fail()) { 
        std::cerr << "Error reading from file " << filename << "." << std::endl;
        inFile.close();
        return false;
    }

    inFile.close();
    return true;
}

double StudentList::calculateAverageScore() const {
    if (students.empty()) {
        return 0.0;
    }
    double totalScore = 0;
    for (const auto& student : students) {
        totalScore += student.getScore();
    }
    return totalScore / students.size();
}

void StudentList::generateReport(const std::string& outputFilename) {
    std::ofstream reportFile(outputFilename);
    if (!reportFile.is_open()) {
        std::cerr << "Error: Could not open file " << outputFilename << " for generating report." << std::endl;
        return;
    }

    if (students.empty()) {
        reportFile << "No student data available to generate a report." << std::endl;
        reportFile.close();
        return;
    }

    int totalStudents = students.size();
    int passedStudents = 0;
    int highestScore = 0; // Assuming scores are non-negative
    int lowestScore = 100; // Assuming scores are 0-100

    if (!students.empty()) {
        highestScore = students[0].getScore();
        lowestScore = students[0].getScore();
    }


    for (const auto& student : students) {
        if (student.getScore() > 50) {
            passedStudents++;
        }
        if (student.getScore() > highestScore) {
            highestScore = student.getScore();
        }
        if (student.getScore() < lowestScore) {
            lowestScore = student.getScore();
        }
    }

    int failedStudents = totalStudents - passedStudents;
    double passPercentage = (totalStudents > 0) ? (static_cast<double>(passedStudents) / totalStudents) * 100.0 : 0.0;
    double failPercentage = (totalStudents > 0) ? (static_cast<double>(failedStudents) / totalStudents) * 100.0 : 0.0;
    double averageScore = calculateAverageScore();

    reportFile << "Student Performance Report" << std::endl;
    reportFile << "--------------------------" << std::endl;
    reportFile << "Total Students: " << totalStudents << std::endl;
    reportFile << "Passed Students: " << passedStudents << std::endl;
    reportFile << "Failed Students: " << failedStudents << std::endl;
    reportFile << std::fixed << std::setprecision(2);
    reportFile << "Pass Percentage: " << passPercentage << "%" << std::endl;
    reportFile << "Fail Percentage: " << failPercentage << "%" << std::endl;
    reportFile << "Average Score: " << averageScore << std::endl;
    reportFile << "Highest Score: " << highestScore << std::endl;
    reportFile << "Lowest Score: " << lowestScore << std::endl;
    reportFile << "--------------------------" << std::endl;

    reportFile.close();
    std::cout << "Report generated and saved to " << outputFilename << std::endl;
}

void StudentList::collectStudentDataInteractively() {
    int numStudents;
    std::cout << "Enter the number of students (1-50): ";
    std::cin >> numStudents;

    while (std::cin.fail() || numStudents < 1 || numStudents > 50) {
        std::cout << "Invalid input. Please enter a number between 1 and 50: ";
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cin >> numStudents;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        int score;

        std::cout << "Enter name for student " << (i + 1) << ": ";
        std::getline(std::cin, name);
        while (name.empty()) {
            std::cout << "Name cannot be empty. Please enter a name: ";
            std::getline(std::cin, name);
        }

        std::cout << "Enter score for " << name << " (0-100): ";
        std::cin >> score;
        while (std::cin.fail() || score < 0 || score > 100) {
            std::cout << "Invalid score. Please enter a score between 0 and 100: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> score;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        addStudent(Student(name, score));
    }

    if (saveToFile("students.txt")) {
        std::cout << "Student data collected and saved to students.txt successfully." << std::endl;
    } else {
        std::cout << "Error: Failed to save student data to students.txt." << std::endl;
    }
}

bool StudentList::isEmpty() const {
    return students.empty();
}


int main() {}