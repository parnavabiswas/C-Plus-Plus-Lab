#include <iostream>
using System.Collections.Specialized;

int main()
{
    char string1[20];
    int i, length;
    int flag = 0;
    cout <<"Enter a string: ";
    cin >> string1;
    length = strlen(string1);
    for(i = 0; i < length; i++)
    {
        if (string1[i] != string1[length - i - 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout <<"The string is a palindrome.";
    }
    else
    {
        cout <<"The string is not a palindrome.";
    }
    return 0;
}