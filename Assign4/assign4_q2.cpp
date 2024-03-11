// Q2. Write a menu driven program for Student management.
// In main(), create Array of Objects and provide facility for accept, print, search and sort.
// For student accept name, gender, rollNumber and marks of three subjects from user and print name,
// rollNumber, gender and percentage.
// Provide global functions void sortRecords(Studuent[] arr) and int searchRecords(Student[] arr) for
// sorting and searching array.
// Search function returns index of found Student, otherwise returns -1.

#include<iostream>
using namespace std;

class Student {
private:
    int rollno;
    int m1;
    int m2;
    int m3;
    string name;
    string gender;

public:
    Student() {
        rollno = 0;
        m1 = 0;
        m2 = 0;
        m3 = 0;
        name = "";
        gender = "";
    }

    void accept()
    {
        cout << "Enter first name of student: ";
        cin >> name;
        cout << "Enter Gender(Male/Female): ";
        cin >> gender;
        cout << "Enter Roll Number of Student: ";
        cin >> rollno;
        cout << "Enter marks of subject1 (Out of 100): ";
        cin >> m1;
        if (m1 > 100)
        {
            cout << "Invalid Marks!";
            return;
        }
        cout << "Enter marks of subject2 (out of 100): ";
        cin >> m2;
        if (m2 > 100)
        {
            cout << "Invalid Marks!";
            return;
        }
        cout << "Enter marks of subject3 (Out of 100): ";
        cin >> m3;
        if (m3 > 100)
        {
            cout << "Invalid Marks!";
            return;
        }
        cout << endl;
    }

    void print()
    {
        int sum, p;
        sum = m1 + m2 + m3;
        p = sum / 3;
        cout << "*********************************" << endl;
        cout << "Name of student is: " << name << endl;
        cout << "Gender of student is: " << gender << endl;
        cout << "Roll number of student is: " << rollno << endl;
        cout << "Percentage of student is: " << p << "%" << endl;
        cout << "*********************************" << endl;
    }

    int getRoll() {
        return rollno;
    }
};

void sortStudent(Student* arr[], int size) {
    for (int i = 0;i < size;i++)
    {
        for (int j = 0;j < size;j++) {
            if (arr[i]->getRoll() < arr[j]->getRoll())
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int searchStudent(Student* arr[], int size, int r)
{
    for (int i = 0;i < size;i++)
    {
        if (arr[i]->getRoll() == r)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    cout << "Enter the number of students: ";
    int size;
    cin >> size;
    Student* arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new Student;
    }

    int choice;

    do {
        cout << "============================================" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Enter Student Data" << endl;
        cout << "2. Print Student Data" << endl;
        cout << "3. Sort Student Data" << endl;
        cout << "4. Search Student from Data" << endl;
        cout << "============================================" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            for (int i = 0;i < size;i++)
            {
                arr[i]->accept();
            }
            cout << endl;
            break;

        case 2:
            for (int i = 0;i < size;i++) {
                arr[i]->print();
            }
            break;

        case 3:
            sortStudent(arr, size);
            cout << "Sorted Data is: " << endl;
            for (int i = 0;i < size;i++) {
                arr[i]->print();
            }
            break;

        case 4:
            cout << "Enter Roll number to search: ";
            int r;
            cin >> r;
            cout << endl;
            cout << "The desired roll number is at position: " << searchStudent(arr, size, r) + 1 << endl;
            cout << "Student details are: " << endl;
            arr[searchStudent(arr, size, r)]->print();
            break;

        default:
            cout << "Invalid Input!!!" << endl;
            break;
        }
    } while (choice != 0);

    for (int i = 0; i < size; i++)
    {
        delete arr[i];
    }
    return 0;
}