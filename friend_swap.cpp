#include <iostream>
using namespace std;

class Second;  // Forward declaration

class First {
private:
    int number;

public:
    void input() {
        cout << "Enter the first number: ";
        cin >> number;
    }

    void display() const {
        cout << number;
    }

    friend void swapNumbers(First&, Second&);
};

class Second {
private:
    int number;

public:
    void input() {
        cout << "Enter the second number: ";
        cin >> number;
    }

    void display() const {
        cout << number;
    }

    friend void swapNumbers(First&, Second&);
};

// This friend function can access the private members of both classes.
void swapNumbers(First& first, Second& second) {
    int temporary = first.number;
    first.number = second.number;
    second.number = temporary;
}

int main() {
    First first;
    Second second;

    first.input();
    second.input();

    cout << "\nBefore swapping: ";
    cout << "First number = ";
    first.display();
    cout << ", Second number = ";
    second.display();

    swapNumbers(first, second);

    cout << "\nAfter swapping: ";
    cout << "First number = ";
    first.display();
    cout << ", Second number = ";
    second.display();
    cout << '\n';

    return 0;
}
