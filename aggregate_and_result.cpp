// #include <iostream>
// #include <fstream>
// #include <string>
// #include <limits>

// using namespace std;


// int * collect_result(int num_student, string* names) {
//   int *scores = new int[num_student];
//   for(int i = 0; i < num_student; i++) {
//     cout<< "Enter score for " << names[i] << " (0 - 100): ";
//     int score;
//     while(!(cin>> score) || score < 0 || score > 100) {
//       cout<< "Invalid score! Enter  a number between 0 and 100: ";
//       cin.clear();
//       cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }
//     scores[i] = score;
//   }
//   return scores;
// }

// int saveStudentResult() {
//   cout<< "Enter number of students (1-50): ";
//   int num_students;
//   while(!(cin>> num_students) || num_students < 0 || num_students > 50) {
//     cout<< "Error: Invalid number of students entered \n";
//     cin.clear();
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//   }

//   string *names = new string[num_students];
//   cout<< "Number of students: " << num_students << endl;
//   // cin.ignore(numeric_limits<streamsize>::max(), '\n');

//   for(int i; i < num_students; i++) {
//     cout<< "Enter name of student " << i+1 << ": ";
//     getline(cin, names[i]);
//     while(names[i].empty()) {
//       cout<< "Name cannot be empty! Enter again: ";
//       getline(cin, names[i]);
//     }
//   }

//   int *scores = collect_result(num_students, names);
//   std::ofstream out_file("students.txt", ios::in);

//   if(!out_file.is_open()) {
//     delete[] names;
//     delete[] scores;
//     return 1;
//   }

//   // out_file<< num_students << std::endl;
//   for(int i = 0; i < num_students; i++) {
//     out_file << names[i] << " " << scores[i] << '\n';
//   }

//   if(out_file.fail()) {
//     cerr<< "Error writing to students.txt!" << std::endl;
//     out_file.close();
//     delete[] names;
//     delete[] scores;
//     return 1;
//   }

//   out_file.close();
//   cout<< "Successfully wrote " << num_students << " student to students.txt" << std::endl;
//   delete[] names;
//   delete[] scores;
//   return 0;
// }


// void studentAggregate () {
//   ifstream studentResult("students.txt");
//   if (!studentResult) {
//     cout << "File not found" << endl;
//   }
  
//   int totalScore = 0, count = 0;
  
//   while (studentResult) {
//     string name;
//     int score;
//     if (studentResult >> name >> score) {
//       // cout << "Read score: " << score << endl;
//       totalScore += score;
//       count++;
//     }
//   }
  
//   studentResult.close();
  
//   if (count == 0) {
//     cout << "No students found." << endl;
//   }
  
//   cout << "Average score: " << totalScore / count << endl;
  
// }


// void studentReport() {

//   string results[50];
//   int count = 0;
//   int num_students = 0;
//   int highestScore = 0;
//   int lowestScore = 100;
//   float totalScore = 0;

//   ifstream students("students.txt");
//   if (!students) {
//     cout << "File not found" << endl;
//   }
//   fstream studentResult("result.txt", ios::out);
//   if (!studentResult) {
//     cout << "File not found" << endl;
//   }
  
//   string name;
//   int score;
//   while (students >> name >> score) {
//     // cout << "Student: " << name << ", Score: " << score << endl;
//     // results[num_students] = {"name": name, "score": score};
//     num_students++;
//     totalScore += score;
//     if(score > 50) {
//       count++;
//     }
//     if(score > highestScore) {
//       highestScore = score;
//     }
//     if(score < lowestScore) {
//       lowestScore = score;
//     }
//   }
  
//   studentResult << "Total number of students: " << num_students << endl;
//   studentResult << "Number of students passed: " << count << endl;
//   studentResult << "Number of students failed: " << num_students - count << endl;
//   studentResult << "Percentage of students passed: " << (count / num_students) * 100 << "%" << endl;
//   studentResult << "Percentage of students failed: " << ((num_students - count) / num_students) * 100 << "%" << endl;
//   studentResult << "Average score: " << (totalScore / num_students) << endl;
//   studentResult << "Highest score: " << highestScore << endl;
//   studentResult << "Lowest score: " << lowestScore << endl;
//   cout << "Successfully wrote " << num_students << " student to result.txt" << endl;
//   students.close();
//   studentResult.close();
// }


// int main() {

//   int choice;

//   cout << "1. Save student result" << endl;
//   cout << "2. Show student aggregate" << endl;
//   cout << "3. Show students report" << endl;

//   // getline(cin, choice);
//   //   while(choice.empty()) {
//   //     cout<< "Name cannot be empty! Enter again: ";
//   //     getline(cin, choice);
//   //   }

//     while(!(cin >> choice) || choice < 1 || choice > 3) {
//       cout<< "Error: Invalid number of students entered \n";
//       cin.clear();
//       cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }
  
//   if(choice == 1) {
//     saveStudentResult();
//   } else if (choice == 2) {
//     studentAggregate();
//   } else if (choice == 3) {
//     studentReport();
//   } else {
//     cout << "Invalid choice" << endl;
//   }

//   return 0;
// }



#include <iostream>
#include <string>



#include <limits>
#include "StudentList.hpp" 

int main() {
    StudentList studentList;

    if (studentList.loadFromFile("students.txt")) {
        std::cout << "Loaded existing student data from students.txt." << std::endl;
    } else {
        std::cout << "No existing student data found or error loading students.txt. Starting fresh." << std::endl;
    }
    int choice;
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add and Save Student Results\n";
        std::cout << "2. Show Student Aggregate Score\n";
        std::cout << "3. Generate Students Report\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

           switch (choice) {
               case 1:
                   studentList.collectStudentDataInteractively();
                   break;
               case 2: {
                   if (studentList.isEmpty()) {
                       std::cout << "No student data available to calculate aggregate." << std::endl;
                   } else {
                       double avg = studentList.calculateAverageScore();
                       std::cout << "Average score: " << avg << std::endl;
                   }
                   break;
               }
               case 3:
                   studentList.generateReport("result.txt");
                   // std::cout << "Student report generated and saved to result.txt." << std::endl; 
                   break;
               case 4:
                   std::cout << "Exiting program." << std::endl;
                   return 0;
               default:
                   std::cout << "Invalid choice. Please try again." << std::endl;
           }
       }
   
       return 0;
   }
   