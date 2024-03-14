// Q2. Create a class called as Employee with data members id,name and salary.Take the input of size
// when program starts and Create the array of employee pointers of that size. Provide a menu driven
// code for accepting employee, dislpay all employees, find employee based on empid. Here the empid
// should be auto-generated and once initialized it should not be changed.

#include<iostream>
using namespace std;

class Employee {
private:
    const int id;
    string name;
    double salary;
    static int generate_id;

public:
    Employee() :Employee("", 0)
    {

    }
    Employee(string name, double salary) :id(++generate_id)
    {
        this->name = name;
        this->salary = salary;
    }
    void accept()
    {
        cout << "Enter Employee name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> salary;
    }
    void display()
    {
        cout << "Employee name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Employee Salary: " << salary << endl;
    }
    int getId()
    {
        return id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getSalary()
    {
        return salary;
    }
};
int Employee::generate_id = 1000;

int main()
{
    int choice, empid;
    int n;
    cout << "Enter the number of Employees: ";
    cin >> n;
    Employee e[n];
    do {
        cout << "0. Exit" << endl;
        cout << "1. Accept Employee" << endl;
        cout << "2. Display All Employees" << endl;
        cout << "3. Find Employee" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            for (int i = 0;i < n;i++)
            {
                e[i].accept();
            }
            break;

        case 2:
            for (int i = 0;i < n;i++)
            {
                e[i].display();
            }
            break;

        case 3:
            cout << "Enter Employee ID to search: ";
            cin >> empid;
            for (int i = 0; i < n; i++)
            {
                if (e[i].getId() == empid)
                {
                    e[i].display();
                }
            }
            break;

        default:
            cout << "Invalid Input!!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}