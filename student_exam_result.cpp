#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;
    string className;

public:
    void inputStudentDetails() {
        cout << "Enter roll number: ";
        cin >> rollNo;
        cin.ignore();

        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter class: ";
        getline(cin, className);
    }

    void displayStudentDetails() const {
        cout << "\nRoll number: " << rollNo
             << "\nName: " << name
             << "\nClass: " << className << '\n';
    }
};

class Exam : public Student {
protected:
    static const int SUBJECT_COUNT = 6;
    double marks[SUBJECT_COUNT];

public:
    void inputMarks() {
        cout << "\nEnter marks for six subjects:\n";
        for (int i = 0; i < SUBJECT_COUNT; ++i) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void displayMarks() const {
        cout << "\nMarks:\n";
        for (int i = 0; i < SUBJECT_COUNT; ++i) {
            cout << "Subject " << i + 1 << ": " << marks[i] << '\n';
        }
    }
};

class Result : public Exam {
private:
    double totalMarks = 0;
    double percentage = 0;

public:
    void calculateResult() {
        totalMarks = 0;
        for (double mark : marks) {
            totalMarks += mark;
        }
        percentage = totalMarks / SUBJECT_COUNT;
    }

    void displayResult() const {
        displayStudentDetails();
        displayMarks();

        cout << fixed << setprecision(2)
             << "\nTotal marks: " << totalMarks << " out of "
             << SUBJECT_COUNT * 100
             << "\nPercentage: " << percentage << "%\n";
    }
};

int main() {
    Result studentResult;

    studentResult.inputStudentDetails();
    studentResult.inputMarks();
    studentResult.calculateResult();

    cout << "\n--- Student Result ---\n";
    studentResult.displayResult();

    return 0;
}
