// Q1. Write a user defined function factorial() that calculates factorial of given number and it throws
// exception if number entered by user is negative.

#include<iostream>
using namespace std;

// template<typename T>
int factorial(int num)
{
    if (num < 0)
    {
        throw 2;
    }
    else if (num == 0)
    {
        return 1;
    }
    else
        return (num * factorial(num - 1));
}

int main()
{
    int num;
    int fact;
    cout << "Enter Number whose factorial is to be found: ";
    cin >> num;
    try
    {
        fact = factorial(num);
        cout << "The Factorial is= " << fact << endl;
    }
    catch (int error)
    {
        cout << "Number cannot be Negative or zero." << endl;
    }
    return 0;
}