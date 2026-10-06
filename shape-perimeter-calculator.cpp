#include <iostream>
#include <iomanip>
using namespace std;

const float PI = 3.14159;

class Shape {
private:
    float radius;
    float length;
    float width;

public:
    // Constructor
    Shape(float r = 0, float l = 0, float w = 0) {
        radius = r;
        length = l;
        width = w;
        cout << "Constructor called - Shape object created" << endl;
    }

    // Destructor
    ~Shape() {
        cout << "Destructor called - Shape object destroyed" << endl;
    }

    // Method to calculate circle perimeter (circumference)
    float circlePerimeter() {
        if (radius <= 0) {
            cout << "Invalid radius! Radius must be positive." << endl;
            return 0;
        }
        return 2 * PI * radius;
    }

    // Method to calculate rectangle perimeter
    float rectanglePerimeter() {
        if (length <= 0 || width <= 0) {
            cout << "Invalid dimensions! Length and width must be positive." << endl;
            return 0;
        }
        return 2 * (length + width);
    }

    // Setter methods
    void setRadius(float r) {
        radius = r;
    }

    void setDimensions(float l, float w) {
        length = l;
        width = w;
    }

    // Getter methods
    float getRadius() {
        return radius;
    }

    float getLength() {
        return length;
    }

    float getWidth() {
        return width;
    }

    // Display shape properties
    void displayProperties() {
        cout << "\n--- Shape Properties ---" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
    }
};

int main() {
    cout << "=== Shape Perimeter Calculator ===" << endl;

    // Create a circle (radius = 5)
    cout << "\n--- Circle Example ---" << endl;
    Shape circle(5);
    circle.displayProperties();
    cout << "Circle Perimeter (Circumference): " << fixed << setprecision(2) 
         << circle.circlePerimeter() << " units" << endl;

    // Create a rectangle (length = 10, width = 6)
    cout << "\n--- Rectangle Example ---" << endl;
    Shape rectangle(0, 10, 6);
    rectangle.displayProperties();
    cout << "Rectangle Perimeter: " << fixed << setprecision(2) 
         << rectangle.rectanglePerimeter() << " units" << endl;

    // Create another shape and modify it
    cout << "\n--- Modified Shape Example ---" << endl;
    Shape shape;
    shape.setRadius(7);
    shape.setDimensions(12, 8);
    shape.displayProperties();
    cout << "Circle Perimeter: " << fixed << setprecision(2) 
         << shape.circlePerimeter() << " units" << endl;
    cout << "Rectangle Perimeter: " << fixed << setprecision(2) 
         << shape.rectanglePerimeter() << " units" << endl;

    cout << "\n--- End of Program ---" << endl;
    return 0;
}
