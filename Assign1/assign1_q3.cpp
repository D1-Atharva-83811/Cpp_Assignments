// Q3. Write a menu driven program for Student in CPP language. Create a class student with data
// members roll no, name and marks. Implement the following functions
// void initStudent();
// void printStudentOnConsole();
// void acceptStudentFromConsole();

#include <iostream>
using namespace std;

class Student{
    private:
    string rollno;
    string name;
    int marks;

    public:
    void initStudent()
    {
        rollno='0';
        name="Not Applicable";
        marks=0;
    }

    void printStudentOnConsole()
    {
        cout<<"Name of student: "<<name<<endl;
        cout<<"Roll Number of Student: "<<rollno<<endl;
        cout<<"Marks of Student"<<marks<<endl;
    }

    void acceptStudentFromConsole()
    {
        cout<<"Enter name of Student: ";
        cin>>name;
        cout<<"Enter Roll Number: ";
        cin>>rollno;
        cout<<"Enter marks of Student: ";
        cin>>marks;
    }
};

int main()
{
    Student s1;
    int choice;

    do
    {
        cout<<"Enter your choice:\n";
        cout<<"1. Initialize"<<endl;
        cout<<"2. Print Data"<<endl;
        cout<<"3. Accept Data"<<endl;
        cout<<"0. Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            s1.initStudent();
            break;

            case 2:
            s1.printStudentOnConsole();
            break;

            case 3:
            s1.acceptStudentFromConsole();
            break;

            case 0:
            break;

            default:
            cout<<"Invalid Input!!!"<<endl;
            break;
        }
    } while (choice);
    return 0;
}