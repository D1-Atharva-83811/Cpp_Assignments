// Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
// Date is having data members day, month, year. Implement the following functions.
// void initDate();
// void printDateOnConsole();
// void acceptDateFromConsole();
// bool isLeapYear();

#include<iostream>
using namespace std;

class Date{
    private:
    int d;
    int m;
    int y;

    public:
    void initDate()
    {
        d=1;
        m=1;
        y=1;
    }

    void printDateOnConsole()
    {
        cout<<"The date is: "<<d<<"/"<<m<<"/"<<y<<endl;
    }

    void acceptDateFromConsole()
    {
        cout<<"Enter date: ";
        cin>>d;
        cout<<"Enter month: ";
        cin>>m;
        cout<<"Enter year: ";
        cin>>y;
    }

    bool isLeapYear()
    {
        if(y%4==0)
            return true;

        else
            return false;
    }
};

int main()
{
    struct Date d;
    int choice;
    bool exit=0;

    do
    {
        cout << "Enter Choice: \n";
        cout << "1. Initiate\n";
        cout << "2. Accept\n";
        cout << "3. Print\n";
        cout << "0. Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            d.initDate();
            break;

            case 2:
            d.acceptDateFromConsole();
            break;

            case 3:
            d.printDateOnConsole();
            break;

            case 0:
            break;

            default:
            cout<<"Invalid Input!"<<endl;
            break;
        }
    }
    while(choice);
    return 0;
}