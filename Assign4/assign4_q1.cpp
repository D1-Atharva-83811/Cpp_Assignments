// Q1. Implement following classes. Test all functionalities in main().Insted of char[] use string
// datatype

#include<iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date()
    {}
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    void displayDate() {
        cout << "The Date is " << day << "/" << month << "/" << year << endl;
    }
    void acceptDate() {
        cout << "Enter Day: ";
        cin >> day;
        cout << "Enter Month: ";
        cin >> month;
        cout << "Enter Year: ";
        cin >> year;
    }
    bool isLeap()
    {
        if (year % 4 == 0) {
            return 1;
        }
        return 0;
    }
};

class Person {
private:
    string name;
    string addr;
    Date birth_date;

public:
    Person() {

    }
    Person(string n, string a, Date d) {
        name = n;
        addr = a;
        birth_date = d;
    }
    void displayPerson()
    {
        cout << "Name of Person: " << name << endl;
        cout << "Address of Person: " << addr << endl;
        cout << "DOB of Person: " << endl;
        birth_date.displayDate();
    }
    void acceptPerson()
    {
        cout << "Enter Person name: ";
        cin >> name;
        cout << "Enter Person Address: ";
        cin >> addr;
        cout << "Person Date of Birth:" << endl;
        birth_date.acceptDate();
    }
};

class Employee {
private:
    int id;
    float sal;
    string dep;
    Date joining;

public:
    Employee() {}
    Employee(int i, float s, string d, Date j) {
        id = i;
        sal = s;
        dep = d;
        joining = j;
    }
    void displayEmployee()
    {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Salary: " << sal << endl;
        cout << "Employee Department: " << dep << endl;
        cout << "Employee Joining Date: " << endl;
        joining.displayDate();
    }
    void acceptEmployee()
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Salary: ";
        cin >> sal;
        cout << "Enter Employee Department: ";
        cin >> dep;
        cout << "Enter Employee Joining Date:" << endl;
        joining.acceptDate();
    }
};

int main()
{
    int choice;
    Employee e1;
    Person p1;
    Date d1;
    do {
        cout << "*********************************" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Accept Person Details" << endl;
        cout << "2. Accept Employee Details" << endl;
        cout << "3. Display Person Details" << endl;
        cout << "4. Display Employee Details" << endl;
        cout << "5. Accept Date" << endl;
        cout << "6. Display Date" << endl;
        cout << "*********************************" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            p1.acceptPerson();
            break;
        case 2:
            e1.acceptEmployee();
            break;
        case 3:
            p1.displayPerson();
            break;
        case 4:
            e1.displayEmployee();
            break;
        case 5:
            d1.acceptDate();
            break;
        case 6:
            d1.displayDate();
            break;
        default:
            cout << "Invalid Input!!!";
            break;
        }
    } while (choice != 0);

    return 0;
}