// Q2. Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using
// Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not
// given, allocate stack of size 5.
// Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print()

#include <iostream>
using namespace std;

class Stack
{
private:
    const int size;
    int limit = -1;
    int *arr;

public:
    Stack(int n) : size(n)
    {
        arr = new int[size];
        cout << "Stack size: " << size << endl;
        cout << endl;
    }
    ~Stack()
    {
        delete[] arr;
    }
    void push()
    {
        if (isFull())
        {
            cout << "Stack Overflow. The stack is Full." << endl;
            return;
        }

        int value;
        cout << "Enter value you want to push: ";
        cin >> value;
        cout << endl;
        arr[++limit] = value;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Undeflow. The stack is empty." << endl;
            return;
        }

        arr[limit--];
        cout << "Element popped!" << endl;
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "The stack is empty." << endl;
            return;
        }
        cout << "The top element is: " << arr[limit] << endl;
    }
    bool isEmpty()
    {
        return limit == -1;
    }
    bool isFull()
    {
        return limit == size - 1;
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "The stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= limit; ++i)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};

int main()
{
    int size = 5;
    int choice;
    int c;
    cout << "1. Default stack size (default=5)" << endl;
    cout << "2. Personal stack size" << endl;
    cin >> c;
    cout << endl;
    switch (c)
    {
    case 1:
        break;
    case 2:
        cout << endl;
        cout << "Enter stack size: ";
        cin >> size;
        cout << endl;
        break;
    default:
        cout << "Invalid Input!";
        cout << endl;
        break;
    }
    Stack s(size);

    do
    {
        cout << "**************************" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Check top element" << endl;
        cout << "4. Print stack" << endl;
        cout << "**************************" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.print();
            break;
        default:
            cout << "Invalid Input!!";
            break;
        }
    } while (choice);
    return 0;
}