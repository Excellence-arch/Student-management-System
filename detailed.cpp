#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int * collect_result(int num_student, string* names) {
  int *scores = new int[num_student];
  for(int i = 0; i < num_student; i++) {
    cout<< "Enter score for " << names[i] << " (0 - 100): ";
    int score;
    while(!(cin>> score) || score < 0 || score > 100) {
      cout<< "Invalid score! Enter  a number between 0 and 100: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    scores[i] = score;
  }
  return scores;
}

int main() {
  cout<< "Enter number of students (1-50): ";
  int num_students;
  while(!(cin>> num_students) || num_students < 0 || num_students > 50) {
    cout<< "Error: Invalid number of students entered \n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  string *names = new string[num_students];
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for(int i; i < num_students; i++) {
    cout<< "Enter name of student " << i+1 << ": ";
    getline(cin, names[i]);
    while(names[i].empty()) {
      cout<< "Name cannot be empty! Enter again: ";
      getline(cin, names[i]);
    }
  }

  int *scores = collect_result(num_students, names);
  std::ofstream out_file("students.txt", ios::app);

  if(!out_file.is_open()) {
    delete[] names;
    delete[] scores;
    return 1;
  }

  out_file<< num_students << std::endl;
  for(int i = 0; i < num_students; i++) {
    out_file << names[i] << " " << scores[i] << '\n';
  }

  if(out_file.fail()) {
    cerr<< "Error writing to students.txt!" << std::endl;
    out_file.close();
    delete[] names;
    delete[] scores;
    return 1;
  }

  out_file.close();
  cout<< "Successfully wrote " << num_students << " student to students.txt" << std::endl;
  delete[] names;
  delete[] scores;
  return 0;
}