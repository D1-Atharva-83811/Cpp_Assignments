// Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
// Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
// should be menu driven and should not cause memory leakage.
// Hint -> Create class Product and inherit into Book and Tape. Also array should be created of
// Product*

#include<iostream>
using namespace std;

class Product {
public:
    int id;
    string title;
    float price;
    Product()
    {
        id = 0;
        title = "";
        price = 0;
    }
    virtual void accept()
    {
    }
    virtual void display()
    {
    }
};

class Book :public Product
{
public:
    string author;
    void accept()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cout << "Enter Book Title: ";
        cin >> title;
        cout << "Enter Book Price: ";
        cin >> price;
        cout << "Enter Author name: ";
        cin >> author;
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Author: " << author << endl;
    }
};


class Tape :public Product
{
public:
    string artist;
    void accept()
    {
        cout << "Enter Tape ID: ";
        cin >> id;
        cout << "Enter Tape Title: ";
        cin >> title;
        cout << "Enter Tape Price: ";
        cin >> price;
        cout << "Enter Artist name: ";
        cin >> artist;
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Artist: " << artist << endl;
    }
};

int main()
{
    int choice, c;
    float total = 0;
    Product* ptr[3] = { NULL };
    cout << "1. Buying Books" << endl;
    cout << "2. Buying Tapes" << endl;
    cin >> c;
    if (c == 1)
    {
        for (int i = 0;i < 3;i++)
        {
            ptr[i] = new Book();
        }
    }
    else if (c == 2)
    {
        for (int i = 0;i < 3;i++)
        {
            ptr[i] = new Tape();
        }
    }
    else
    {
        cout << "Invalid Input.\nTerminating Program.";
        return -1;
    }

    do {
        cout << "********************************" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Accept Details of Purchase" << endl;
        cout << "2. Display Details of Purchase" << endl;
        cout << "3. Display Bill" << endl;
        cout << "********************************" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            for (int i = 0;i < 3;i++)
            {
                ptr[i]->accept();
            }
            break;

        case 2:
            for (int i = 0;i < 3;i++)
            {
                ptr[i]->display();
            }
            break;

        case 3:
            if (c == 1)
            {
                for (int i = 0;i < 3;i++)
                {
                    total += ptr[i]->price;
                }
                total = total * 0.9;
                cout << "Total Bill is: " << total << "Rs." << endl;
            }
            else
            {
                for (int i = 0;i < 3;i++)
                {
                    total += ptr[i]->price;
                }
                total = total * 0.95;
                cout << "Total Bill is: " << total << "Rs." << endl;
            }
        }
    } while (choice != 0);

    for (int i = 0;i < 3;i++)
    {
        delete ptr[i];
        ptr[i] = NULL;
    }
    return 0;
}