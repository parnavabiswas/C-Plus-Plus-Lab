#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Person {
private:
    char name[64];
    int age;
    char address[64];
    double basicSalary;
    double hra;        // House Rent Allowance
    double da;         // Dearness Allowance
    double ta;         // Travel Allowance
    double deductions; // Tax and other deductions

public:
    // Constructor
    Person() {
        strcpy(name, "");
        age = 0;
        strcpy(address, "");
        basicSalary = 0;
        hra = 0;
        da = 0;
        ta = 0;
        deductions = 0;
    }

    // Input person details
    void inputDetails() {
        cout << "\nEnter Name: ";
        cin.ignore();
        cin.getline(name, 64);
        
        cout << "Enter Age: ";
        cin >> age;
        
        cout << "Enter Address: ";
        cin.ignore();
        cin.getline(address, 64);
        
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        
        // Calculate allowances (as percentage of basic salary)
        hra = basicSalary * 0.10;        // 10% of basic
        da = basicSalary * 0.08;         // 8% of basic
        ta = basicSalary * 0.05;         // 5% of basic
        deductions = basicSalary * 0.12; // 12% of basic (tax)
    }

    // Calculate total salary
    double getTotalSalary() {
        return basicSalary + hra + da + ta - deductions;
    }

    // Get age (for inline function)
    int getAge() const {
        return age;
    }

    // Display salary slip
    void displaySalarySlip() {
        cout << "\n" << string(50, '=') << endl;
        cout << "                  SALARY SLIP" << endl;
        cout << string(50, '=') << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << string(50, '-') << endl;
        cout << "Basic Salary:        " << fixed << setprecision(2) << basicSalary << endl;
        cout << "HRA (10%):           " << hra << endl;
        cout << "DA (8%):             " << da << endl;
        cout << "TA (5%):             " << ta << endl;
        cout << "                     " << string(15, '-') << endl;
        cout << "Gross Salary:        " << (basicSalary + hra + da + ta) << endl;
        cout << "Deductions (12%):    " << deductions << endl;
        cout << string(50, '-') << endl;
        cout << "Net Salary:          " << getTotalSalary() << endl;
        cout << string(50, '=') << endl;
    }

    // Destructor
    ~Person() {
        // Cleanup if needed
    }
};

// Inline function to find youngest person
inline int findYoungest(Person persons[], int size) {
    int youngestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (persons[i].getAge() < persons[youngestIndex].getAge()) {
            youngestIndex = i;
        }
    }
    return youngestIndex;
}

// Inline function to find eldest person
inline int findEldest(Person persons[], int size) {
    int eldestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (persons[i].getAge() > persons[eldestIndex].getAge()) {
            eldestIndex = i;
        }
    }
    return eldestIndex;
}

int main() {
    Person persons[10];
    int numPersons;

    cout << "=== Person Management System ===" << endl;
    cout << "Enter number of persons (max 10): ";
    cin >> numPersons;

    if (numPersons > 10 || numPersons <= 0) {
        cout << "Invalid input! Maximum 10 persons allowed." << endl;
        return 1;
    }

    // Input details for all persons
    for (int i = 0; i < numPersons; i++) {
        cout << "\n--- Person " << (i + 1) << " ---" << endl;
        persons[i].inputDetails();
    }

    // Display salary slips for all persons
    cout << "\n\n";
    for (int i = 0; i < numPersons; i++) {
        persons[i].displaySalarySlip();
    }

    // Find and display youngest and eldest
    if (numPersons > 0) {
        int youngestIdx = findYoungest(persons, numPersons);
        int eldestIdx = findEldest(persons, numPersons);

        cout << "\n\n=== Age Analysis ===" << endl;
        cout << "Youngest Person: " << persons[youngestIdx].getAge() << " years old" << endl;
        cout << "Eldest Person: " << persons[eldestIdx].getAge() << " years old" << endl;
    }

    return 0;
}
