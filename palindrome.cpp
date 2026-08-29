#include <iostream>
using namespace std;

bool isPalindrome(long long n) {
    if (n < 0) return false;            // treat negative numbers as not palindrome
    long long original = n;
    long long reversed = 0;
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return original == reversed;
}

int main() {
    long long num;
    cout << "Enter a number: ";
    if (!(cin >> num)) return 0;

    if (isPalindrome(num))
        cout << num << " is a palindrome\n";
    else
        cout << num << " is not a palindrome\n";

    return 0;
}
