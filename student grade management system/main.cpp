#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Function prototypes
void addStudentGrades(vector<string>& names, vector<int>& grades);
void displayStatistics(const vector<int>& grades);

int main() {
    vector<string> studentNames;
    vector<int> studentGrades;
    int choice;

    do {
        cout << "Student Grade Management System" << endl;
        cout << "1. Add Student Grades" << endl;
        cout << "2. Display Statistics" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover newline

        switch (choice) {
            case 1:
                addStudentGrades(studentNames, studentGrades);
                break;
            case 2:
                displayStatistics(studentGrades);
                break;
            case 3:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    } while (choice != 3);

    return 0;
}

void addStudentGrades(vector<string>& names, vector<int>& grades) {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover newline

    for (int i = 0; i < numStudents; ++i) {
        string name;
        int grade;

        cout << "Enter name of student " << (i + 1) << ": ";
        getline(cin, name);
        cout << "Enter grade for " << name << ": ";
        cin >> grade;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover newline

        names.push_back(name);
        grades.push_back(grade);
    }
}

void displayStatistics(const vector<int>& grades) {
    if (grades.empty()) {
        cout << "No grades available to display statistics." << endl;
        return;
    }

    int sum = 0;
    int highest = grades[0];
    int lowest = grades[0];

    for (int grade : grades) {
        sum += grade;
        if (grade > highest) highest = grade;
        if (grade < lowest) lowest = grade;
    }

    double average = static_cast<double>(sum) / grades.size();

    // Calculate grade distribution
    int gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0, gradeF = 0;
    for (int grade : grades) {
        if (grade >= 90) gradeA++;
        else if (grade >= 80) gradeB++;
        else if (grade >= 70) gradeC++;
        else if (grade >= 60) gradeD++;
        else gradeF++;
    }

    cout << "Statistics:" << endl;
    cout << "Average Grade: " << average << endl;
    cout << "Highest Grade: " << highest << endl;
    cout << "Lowest Grade: " << lowest << endl;
    cout << "Grade Distribution:" << endl;
    cout << "A: " << gradeA << endl;
    cout << "B: " << gradeB << endl;
    cout << "C: " << gradeC << endl;
    cout << "D: " << gradeD << endl;
    cout << "F: " << gradeF << endl;
}
