// Q1. Implement a Stack class using C++ templates. Test stack operations on Stack<int>,
// Stack<double> and Stack<Box>.

#include <iostream>
using namespace std;
#include<vector>

template<typename T> class Stack
{
private:
    int size;
    int limit = -1;
    T* arr;

public:
    Stack(int n) : size(n)
    {
        arr = new T[size];
        cout << "Stack size: " << size << endl;
        cout << endl;
    }
    ~Stack()
    {
        delete[] arr;
    }
    void push(T& value)
    {
        if (isFull())
        {
            cout << "Stack Overflow. The stack is Full." << endl;
            return;
        }
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

class Box {
    int l;
    int b;
    int h;

public:
    Box() :Box(0, 0, 0)
    {
    }
    Box(int l, int b, int h)
    {
        this->l = l;
        this->b = b;
        this->h = h;
    }
    void acceptBox()
    {
        cout << "Enter Length: ";
        cin >> l;
        cout << "Enter Breadth: ";
        cin >> b;
        cout << "Enter Height: ";
        cin >> h;
    }
    void displayBox()
    {
        cout << "Length: " << l << endl;
        cout << "Breadth: " << b << endl;
        cout << "Height: " << h << endl;
    }
    friend ostream& operator<<(ostream& out, Box& box)
    {
        out << "Length: " << box.l << ", Breadth: " << box.b << ", Height: " << box.h;
        return out;
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
    Stack<int> si(size);
    Stack<double> sd(size);
    Stack<Box> sb(size);
    Box box;
    int value;
    double v;

    do
    {
        cout << "**************************" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Push element in Int" << endl;
        cout << "2. Push element in Double" << endl;
        cout << "3. Push element in Box" << endl;
        cout << "4. Pop element in Int" << endl;
        cout << "5. Pop element in Double" << endl;
        cout << "6. Pop element in Box" << endl;
        cout << "7. Check top element in Int" << endl;
        cout << "8. Check top element in Double" << endl;
        cout << "9. Check top element in Box" << endl;
        cout << "10. Print stacks" << endl;
        cout << "**************************" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter value you want to push: ";
            cin >> value;
            si.push(value);
            break;
        case 2:
            cout << "Enter value you want to push: ";
            cin >> v;
            sd.push(v);
            break;
        case 3:
            box.acceptBox();
            sb.push(box);
            break;
        case 4:
            si.pop();
            break;
        case 5:
            sd.pop();
            break;
        case 6:
            sb.pop();
            break;
        case 7:
            si.peek();
            break;
        case 8:
            sd.peek();
            break;
        case 9:
            sb.peek();
            break;
        case 10:
            cout << "Int Stack: ";
            si.print();
            cout << "Double Stack: ";
            sd.print();
            cout << "Box Stack: ";
            sb.print();
            break;
        default:
            cout << "Invalid Input!!" << endl;
            break;
        }
    } while (choice);
    return 0;
}