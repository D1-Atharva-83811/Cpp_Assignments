// Q.4 Write a class Address. Implement constructors, getters, setters, accept(), and display() methods.
// Instead of char[] use string datatype
// string building, city, street
// int pin

#include <iostream>
using namespace std;

class Address
{
private:
    string building;
    string city;
    string street;
    int pin;

public:
    Address() {}

    Address(string building, string city, string street, int pin)
    {
        building = "Sunbeam";
        city = "Pune";
        street = "Hinjewadi";
        pin = 411045;
    }

    string getBuilding() const
    {
        return building;
    }

    void setBuilding(string building)
    {
        building = building;
    }

    string getCity() const
    {
        return city;
    }

    void setCity(string city)
    {
        city = city;
    }

    string getStreet() const
    {
        return street;
    }

    void setStreet(string street)
    {
        street = street;
    }

    int getPin() const
    {
        return pin;
    }

    void setPin(int pin)
    {
        pin = pin;
    }

    void accept()
    {
        cout << "Enter Building name: ";
        cin >> building;
        cout << "Enter City name: ";
        cin >> city;
        cout << "Enter Street name: ";
        cin >> street;
        cout << "Enter Pin code: ";
        cin >> pin;
    }

    void display()
    {
        cout << endl << building << endl << city << endl << street << endl << pin << endl << endl;
    }
};

int main()
{
    Address a1;
    string b, c, s;
    int p;
    int choice;

    do
    {
        cout << "Enter you choice:" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Accept address" << endl;
        cout << "2. Display address" << endl;
        cout << "3. Enter Building name" << endl;
        cout << "4. Enter city name" << endl;
        cout << "5. Enter street name" << endl;
        cout << "6. Enter Pin code" << endl;
        cout << "7. Display Building name" << endl;
        cout << "8. Display city name" << endl;
        cout << "9. Display street name" << endl;
        cout << "10. Display pin code" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            a1.accept();
            break;
        case 2:
            a1.display();
            break;
        case 3:
            // string b;
            cout << "Enter building name";
            cin >> b;
            a1.setBuilding(b);
            break;
        case 4:
            // string c;
            cout << "Enter city name";
            cin >> c;
            a1.setCity(c);
            break;
        case 5:
            // string s;
            cout << "Enter street name";
            cin >> s;
            a1.setStreet(s);
            break;
        case 6:
            // int p;
            cout << "Enter pin code: ";
            cin >> p;
            a1.setPin(p);
            break;
        case 7:
            a1.getBuilding();
            break;
        case 8:
            a1.getCity();
            break;
        case 9:
            a1.getStreet();
            break;
        case 10:
            a1.getPin();
            break;
        default:
            cout << "Invalid Input!";
            break;
        }
    } while (choice != 0);
    return 0;
}