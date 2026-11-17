#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    // Prefix increment: ++z
    Complex& operator++() {
        ++real;
        ++imaginary;
        return *this;
    }

    // Postfix increment: z++
    Complex operator++(int) {
        Complex old = *this;
        ++(*this);
        return old;
    }

    // Prefix decrement: --z
    Complex& operator--() {
        --real;
        --imaginary;
        return *this;
    }

    // Postfix decrement: z--
    Complex operator--(int) {
        Complex old = *this;
        --(*this);
        return old;
    }

    // Binary addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Binary subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& number) {
        out << number.real << (number.imaginary < 0 ? " - " : " + ")
            << (number.imaginary < 0 ? -number.imaginary : number.imaginary)
            << "i";
        return out;
    }
};

int main() {
    Complex a(3, 4);
    Complex b(1, 2);

    std::cout << "a + b = " << a + b << '\n';
    std::cout << "a - b = " << a - b << '\n';

    std::cout << "++a = " << ++a << '\n';
    std::cout << "b-- = " << b-- << '\n';
    std::cout << "b after decrement = " << b << '\n';

    return 0;
}
