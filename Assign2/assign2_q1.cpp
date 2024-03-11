// Q1. Write a menu driven program to calculate volume of the box(length * width * height).
// Provide necessary constructors.

#include <iostream>
using namespace std;

class Volume {
private:
    int l;
    int w;
    int h;

public:

    Volume() :Volume(l, w, h) {
        l = 1;
        w = 1;
        h = 1;
    }

    Volume(int l, int w, int h) {
        this->l = l;
        this->w = w;
        this->h = h;
    }

    Volume(int a) :Volume(a, a, a) {}

    void acceptDif()
    {
        cout << "Enter Length: ";
        cin >> this->l;
        cout << "Enter Width: ";
        cin >> this->w;
        cout << "Enter Height: ";
        cin >> this->h;
    }

    void acceptSame()
    {
        cout << "Enter side length: " << endl;
        cin >> l;
        w = l;
        h = l;
    }

    void acceptUnknown()
    {
        l = 1;
        w = 1;
        h = 1;
    }

    void print() {
        int v;
        v = l * w * h;
        cout << "Length is: " << l << endl;
        cout << "width is: " << w << endl;
        cout << "height is: " << h << endl;
        cout << v << endl;
    }

};

int main()
{
    int choice;
    Volume v1;
    do
    {
        cout << "Enter you choice:\n";
        cout << "1. Side are Different" << endl;
        cout << "2. Sides are Same" << endl;
        cout << "3. Side are unknown" << endl;
        cout << "4. Print Volume" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            v1.acceptDif();
            break;

        case 2:
            v1.acceptSame();
            break;

        case 3:
            v1.acceptUnknown();
            break;

        case 4:
            v1.print();
            break;

        case 0:
            break;

        default:
            cout << "Invalid Input!!" << endl;
            break;
        }
    } while (choice);

    return 0;

}