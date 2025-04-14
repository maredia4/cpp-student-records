#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

enum GradeLevel { FRESHMAN = 1, SOPHOMORE, JUNIOR, SENIOR };

using GPA = float;
using StudentName = string;

namespace StudentUtils {
void formatName(string &name) {
for (char &c : name) {
c = toupper(c);
}
}

string gradeLevelToString(GradeLevel level) {
switch (level) {
case FRESHMAN: return "Freshman";
case SOPHOMORE: return "Sophomore";
case JUNIOR: return "Junior";
case SENIOR: return "Senior";
default: return "Unknown";
}
}

void displayStudentInfo(const StudentName &name, GradeLevel level, GPA gpa) {
cout << "\nStudent Record:\n";
cout << "Name: " << name << endl;
cout << "Grade Level: " << gradeLevelToString(level) << endl;
cout << fixed << setprecision(2);
cout << "GPA: " << gpa << endl;
}
}

struct Student {
StudentName name;
GradeLevel grade;
GPA gpa;
};

int main() {
vector<Student> students;
char choice;

do {
Student student;
string inputName;
int gradeInput;
float inputGPA;

cout << "\nEnter student name: ";
getline(cin, inputName);

cout << "Enter grade level (1=Freshman, 2=Sophomore, 3=Junior, 4=Senior): ";
cin >> gradeInput;

while (gradeInput < 1 || gradeInput > 4) {
cout << "Invalid grade level. Please enter a number between 1 and 4: ";
cin >> gradeInput;
}

cout << "Enter GPA: ";
cin >> inputGPA;

while (inputGPA < 0.0 || inputGPA > 4.0) {
cout << "Invalid GPA. Please enter a value between 0.00 and 4.00: ";
cin >> inputGPA;
}

cin.ignore();

StudentUtils::formatName(inputName);

student.name = inputName;
student.grade = static_cast<GradeLevel>(gradeInput);
student.gpa = inputGPA;

students.push_back(student);

cout << "Add another student? (y/n): ";
cin >> choice;
cin.ignore();
} while (tolower(choice) == 'y');

sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
return a.name < b.name;
});

for (const auto &student : students) {
StudentUtils::displayStudentInfo(student.name, student.grade, student.gpa);
}

return 0;
}