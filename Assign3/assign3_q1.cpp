// Q1. Write a class for Time and provide the functionality
// Time()
// Time(int h,int m,int s)
// getHour()
// getMinute()
// getSeconds()
// printTime()
// setHour()
// setMinute()
// setSeconds()
// In main create array of objects of Time.
// Allocate the memory for the array and the object dynamically.

#include <iostream>
using namespace std;

class Time
{
private:
    int h;

    int m;
    int s;

public:
    Time()
    {
        h = m = s = 1;
    }

    void setTime(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }

    int getHour() const
    {
        return h;
    }

    void setHour(int h)
    {
        this->h = h;
    }

    int getMinute() const
    {
        return m;
    }

    void setMinute(int m)
    {
        this->m = m;
    }

    int getSecond()
    {
        return s;
    }

    void setSecond(int s)
    {
        this->s = s;
    }

    void printTime()
    {
        cout << "The time is --> " << h << ":" << m << ":" << s << endl;
        cout << endl;
    }
};

int main()
{
    int choice;
    int n, i = 0;
    cout << "Enter the number of input times: ";
    cin >> n;
    Time* arr = new Time[n];

    for (i;i < n;i++)
    {
        do
        {
            cout << "0. Next Input Time" << endl;
            cout << "1. Input default Time" << endl;
            cout << "2. Input Time" << endl;
            cout << "3. Input Hours" << endl;
            cout << "4. Input Minutes" << endl;
            cout << "5. Input Seconds" << endl;
            cout << "6. Get Hours" << endl;
            cout << "7. Get Minutes" << endl;
            cout << "8. Get Seconds" << endl;
            cout << "9. Print Time" << endl;
            cin >> choice;
            cout << endl;

            switch (choice)
            {
            case 0:
                break;

            case 1:
                arr[i];
                break;

            case 2:
                int x, y, z;
                cout << "Enter Hours: ";
                cin >> x;
                cout << "Enter Minutes: ";
                cin >> y;
                cout << "Enter Seconds: ";
                cin >> z;
                arr[i].setTime(x, y, z);
                break;

            case 3:
                int h;
                cout << "Enter Hours: ";
                cin >> h;
                arr[i].setHour(h);
                break;

            case 4:
                int m;
                cout << "Enter Minutes: ";
                cin >> m;
                arr[i].setMinute(m);
                break;

            case 5:
                int s;
                cout << "Enter Seconds: ";
                cin >> s;
                arr[i].setSecond(s);
                break;

            case 6:
                arr[i].getHour();
                break;

            case 7:
                arr[i].getMinute();
                break;

            case 8:
                arr[i].getSecond();
                break;

            case 9:
                cout << "At time number: " << i << ":" << endl;
                arr[i].printTime();
                break;
            default:
                cout << "Wrong Choice" << endl;
                break;
            }

        } while (choice != 0);
    }
    delete[] arr;
    return 0;
}