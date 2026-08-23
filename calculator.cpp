#include <iostream>
#include <cmath>
using namespace std;

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

// Function to perform modulus
int modulus(int a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a % b;
}

// Function to display menu
void displayMenu() {
    cout << "\n====== Simple Calculator ======" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Modulus (%)" << endl;
    cout << "6. Exit" << endl;
    cout << "==============================" << endl;
}

int main() {
    double num1, num2;
    int choice;
    char continueCalc;

    cout << "Welcome to the Simple Calculator!" << endl;

    do {
        displayMenu();
        cout << "\nEnter your choice (1-6): ";
        cin >> choice;

        if (choice == 6) {
            cout << "Thank you for using the calculator. Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 6) {
            cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
            continue;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: " << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                break;
            case 5:
                cout << "Result: " << (int)num1 << " % " << (int)num2 << " = " << modulus((int)num1, (int)num2) << endl;
                break;
        }

    } while (true);

    return 0;
}
