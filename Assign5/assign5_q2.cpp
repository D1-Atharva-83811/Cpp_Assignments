// Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
// Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
// should be menu driven and should not cause memory leakage.
// Hint -> Create class Product and inherit into Book and Tape. Also array should be created of
// Product*

#include<iostream>
using namespace std;

class Product
{
private:
    int id;
    string title;
    float price;
public:
    Product()
    {
        id = 0;
        title = "";
        price = 0;
    }
    virtual void accept()
    {
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Product Title: ";
        cin >> title;
        cout << "Enter Product Price: ";
        cin >> price;
    }
    virtual void display()
    {
        cout << "Product ID: " << id << endl;
        cout << "Product Name: " << title << endl;
        cout << "Product Price: " << price << endl;
    }
    float getPrice()
    {
        return price;
    }
    virtual void Total(float x)
    {
    }
};

class Book :public Product
{
private:
    string author;
public:
    void accept()
    {
        Product::accept();
        cout << "Enter Author name: ";
        cin >> author;
    }
    void display()
    {
        Product::display();
        cout << "Author: " << author << endl;
    }
};


class Tape :public Product
{
private:
    string artist;
public:
    void accept()
    {
        Product::accept();
        cout << "Enter Artist name: ";
        cin >> artist;
    }
    void display()
    {
        Product::display();
        cout << "Artist: " << artist << endl;
    }
};

int main()
{
    int choice, i = 0;
    float total = 0, bt = 0, tt = 0;
    Product* ptr[3] = { NULL };

    do {
        cout << "********************************" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Accept Book" << endl;
        cout << "2. Accept Tape" << endl;
        cout << "3. Display Details of Purchase" << endl;
        cout << "4. Display Bill" << endl;
        cout << "********************************" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            if (i < 3)
            {
                ptr[i] = new Book();
                ptr[i]->accept();
                i++;
            }
            else
                cout << "Limit reached" << endl;
            break;

        case 2:
            if (i < 3)
            {
                ptr[i] = new Tape();
                ptr[i]->accept();
                i++;
            }
            else
                cout << "Limit reached" << endl;
            break;

        case 3:
            for (int i = 0;i < 3;i++)
            {
                ptr[i]->display();
            }
            break;

        case 4:
            for (int i = 0;i < 3;i++)
            {
                if (typeid(*ptr[i]) == typeid(Book))
                {
                    bt += ptr[i]->getPrice();
                }
            }
            cout << "Book total is: " << bt << endl;
            cout << "After discount is: " << bt * 0.9 << endl;

            for (int i = 0;i < 3;i++)
            {
                if (typeid(*ptr[i]) == typeid(Tape))
                {
                    tt += ptr[i]->getPrice();
                }
            }
            cout << "Tape total is: " << tt << endl;
            cout << "After discout is: " << tt * 0.95 << endl;
            cout << endl;
            cout << "The total Bill is: " << (bt * 0.9) + (tt * 0.95) << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 0);

    for (int i = 0;i < 3;i++)
    {
        delete ptr[i];
        ptr[i] = NULL;
    }
    return 0;
}