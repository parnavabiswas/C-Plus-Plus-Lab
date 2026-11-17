#include <iostream>
using namespace std;

// Circle: one parameter
 double AREA(double radius) {
    return 3.141592653589793 * radius * radius;
}

// Rectangle: two parameters
double AREA(double length, double width) {
    return length * width;
}

// Triangle: the extra marker distinguishes this overload from the rectangle
double AREA(double base, double height, char) {
    return 0.5 * base * height;
}

int main() {
    double radius, length, width, base, height;

    cout << "Enter circle radius: ";
    cin >> radius;
    cout << "Area of circle = " << AREA(radius) << '\n';

    cout << "\nEnter rectangle length and width: ";
    cin >> length >> width;
    cout << "Area of rectangle = " << AREA(length, width) << '\n';

    cout << "\nEnter triangle base and height: ";
    cin >> base >> height;
    cout << "Area of triangle = " << AREA(base, height, 'T') << '\n';

    return 0;
}
