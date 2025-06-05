#include <iostream>
#include <string>

using namespace std;


enum gender {
  MALE, FEMALE
};

namespace person {
  template <typename T>
  class Student {
  public:
      Student(const string name, T score, gender studentGender) : name(name), score(score), studentGender(studentGender) {}
      string getName() const { return name; }
      T getScore() const { return score; }
      string getGender() const { 
        switch(studentGender) {
          case MALE:
            return "Male";
          case FEMALE:
            return "Female";
          default:
            return "Unknown";
        }
      };
      
  private:
      string name;
      T score;
      gender studentGender;
  };
}

using namespace person;

int main() {
    Student student1("Alice", 85, FEMALE);
    Student student2("Bob", 90.9, MALE);

    cout << "Student 1: " << student1.getName() << ", Score: " << student1.getScore() << ", Gender: " << student1.getGender() << endl;
    cout << "Student 2: " << student2.getName() << ", Score: " << student2.getScore() << ", Gender: " << student2.getGender() << endl;

    return 0;
}