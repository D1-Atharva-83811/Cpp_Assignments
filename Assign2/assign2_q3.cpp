// Q3. Create a namespace NStudent. Create the Student class(created as per assignment-1 Q3) inside
// namespace. Test the functionalities.

#include <iostream>
using namespace std;

namespace NStudent
{
    class Student
    {
    private:
        string rollno;
        string name;
        int marks;

    public:
        void initStudent()
        {
            rollno = '0';
            name = "Not Applicable";
            marks = 0;
        }

        void printStudentOnConsole()
        {
            cout << "Name of student: " << name << endl;
            cout << "Roll Number of Student: " << rollno << endl;
            cout << "Marks of Student" << marks << endl;
        }

        void acceptStudentFromConsole()
        {
            cout << "Enter name of Student: ";
            cin >> name;
            cout << "Enter Roll Number: ";
            cin >> rollno;
            cout << "Enter marks of Student: ";
            cin >> marks;
        }
    };
}

int main()
{
    NStudent::Student s1;
    int choice;

    do
    {
        cout << "0. Exit" << endl;
        cout << "1. Initiate" << endl;
        cout << "2. Accept" << endl;
        cout << "3. Print" << endl;
        cout << "Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            s1.initStudent();
            break;

        case 2:
            s1.acceptStudentFromConsole();
            break;

        case 3:
            s1.printStudentOnConsole();
            break;

        default:
            cout << "Invalid Input!!!";
            break;
        }
    } while (choice != 0);

    return 0;
}