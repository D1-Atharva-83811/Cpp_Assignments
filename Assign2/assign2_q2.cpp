// Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
// Mostly they do, but sometimes a car goes by without paying.
// The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
// collected. Model this tollbooth with a class called tollbooth.
// The two data items are a type unsigned int to hold the total number of cars, and a type double to
// hold the total amount of money collected.
// A constructor initializes all data members to 0. A member function called payingCar() increments
// the car total and adds 0.50 to the cash total. An other function, called nopayCar()
// increments the car total but adds nothing to the cash total. Finally, a member function called
// printOnConsole() displays the two totals and number of paying as well as non paying cars total.


#include<iostream>
using namespace std;

class Tollbooth {
private:
    unsigned int tcar;
    double tmoney;
    int nopay;

public:
    Tollbooth()
    {
        tcar = 0;
        tmoney = 0;
        nopay = 0;
    }

    void payingCar()
    {
        tcar++;
        tmoney += 0.5;
    }

    void nopayCar()
    {
        tcar++;
        nopay++;
    }

    void printOnConsole()
    {
        cout << "***************************************************************" << endl;
        cout << "The total number of cars throughout the day: " << tcar << endl << endl;
        cout << "The total revenue generated: " << tmoney << endl << endl;
        cout << "Total paying cars are: " << tcar - nopay << endl << endl;
        cout << "Total non-paying cars are: " << nopay << endl;
        cout << "***************************************************************" << endl;
    }
};

int main()
{
    Tollbooth t1;
    int choice;

    do
    {
        cout << endl << "Enter you choice:" << endl;
        cout << "0. Print Total and exit" << endl;
        cout << "1. Paying Car" << endl;
        cout << "2. Non-Paying Car" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            t1.payingCar();
            break;

        case 2:
            t1.nopayCar();
            break;

        case 0:
            t1.printOnConsole();
            break;

        default:
            cout << "Invalid Input!!!";
            break;
        }
    } while (choice);
    return 0;
}