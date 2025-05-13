#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student {
  string name;
  int score;
};

int getScore(ifstream& student) {
  
  string name;
  int score;

  if (student >> name >> score) {
    cout << "Read score: " << score << endl;
    return score;
  }

  return score;
}

void studentAggregate () {
  ifstream studentResult("student_result.txt");
  if (!studentResult) {
    cout << "File not found" << endl;
  }
  
  int totalScore = 0, count = 0;
  
  while (studentResult) {
    int score = getScore(studentResult);
    if (studentResult) { // only count valid reads
      totalScore += score;
      count++;
    };
  }
  
  studentResult.close();
  
  if (count == 0) {
    cout << "No students found." << endl;
  }
  
  cout << "Average score: " << totalScore / count << endl;
  
}

void saveStudentResult() {
  ofstream studentResult("student_result.txt", ios::app);
  
  // while (true) {
    Student inputStudent;
    cout << "Enter student name: " << endl;
    cin >> inputStudent.name;
    cout << "Enter student score: " << endl;
    cin >> inputStudent.score;
    studentResult << inputStudent.name << " " << inputStudent.score << endl;
  // }
  

  studentResult.close();
}

int main() {

  int choice;

  cout << "1. Save student result" << endl;
  cout << "2. Show student aggregate" << endl;

  cin >> choice;
  
  if(choice == 1) {
    saveStudentResult();
  } else if (choice == 2) {
    studentAggregate();
  } else {
    cout << "Invalid choice" << endl;
  }

  return 0;
}

