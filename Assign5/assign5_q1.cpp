// Q1. Implement following classes. Test all functionalities in main().
// Create a class Date with data memebrs day,month and year.
// Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
// type date.
// Cretae a class Employee with data members id, sal, dept and joining date. The joining date should
// be of type date.
// Employee class should be inherited from Person.
// Implement the above class as per the class Hirerachy and test the functunalities.

#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date()
    {
        day = month = year = 0;
    }
    void acceptDate()
    {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter Month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }
    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};
class Person :public Date
{
private:
    string name;
    string address;
    Date Birthdate;
public:
    Person()
    {
        name = "";
        address = "";
        //Date Birthdate();
    }
    void acceptPerson()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter DOB: " << endl;
        Birthdate.acceptDate();
    }
    void displayPerson()
    {
        cout << "Name is: " << name << endl;
        cout << "Address is: " << address << endl;
        cout << "Date of Birth: " << endl;
        Birthdate.displayDate();
    }
};
class Employee :public Person
{
private:
    int id;
    float sal;
    string dep;
    Date joining;
public:
    Employee()
    {
        id = 0;
        sal = 0;
        dep = "";
        // Date joining();
        Person p;
    }
    void acceptEmployee()
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "ENter Employee Salary: ";
        cin >> sal;
        cout << "Enter Employee Department: ";
        cin >> dep;
        cout << "Enter Joining Date: " << endl;
        joining.acceptDate();
    }
    void displayEmployee()
    {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Salary: " << sal << endl;
        cout << "Employee Works in " << dep << " Department." << endl;
        cout << "Employee Joining Date is: " << endl;
        joining.displayDate();
    }
};

int main()
{
    int choice;
    Employee* dptr = new Employee();
    do {
        cout << "*************************************" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Accept Employee details" << endl;
        cout << "2. Accept Extra details of Employee" << endl;
        cout << "3. Display Employee Details" << endl;
        cout << "4. Display Employee Personal Details" << endl;
        cout << "*************************************" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            dptr->acceptEmployee();
            break;

        case 2:
            dptr->acceptPerson();
            break;

        case 3:
            dptr->displayEmployee();
            break;

        case 4:
            dptr->displayPerson();
            break;

        default:
            cout << "Invalid Input." << endl << "Terminating Program." << endl;
            break;
        }
    } while (choice != 0);
    delete dptr;
    dptr = NULL;
    return 0;
}