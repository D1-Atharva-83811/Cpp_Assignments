// Q1. Implement following classes. Test all functionalities in main() of each created class. Note that
// employee is inherited into manager and salesman. Insted of char[] use string datatype

#include<iostream>
using namespace std;

class Employee
{
private:
    int id;
    float sal;

public:
    Employee() :Employee(0, 0)
    {
    }
    Employee(int id, float sal)
    {
        // cout << "Employee Constructor" << endl;
        this->id = id;
        this->sal = sal;
    }
    virtual ~Employee()
    {
        cout << "Employee Destructor" << endl;
    }
    int getId()
    {
        return id;
    }
    void setId(int id)
    {
        this->id = id;
    }
    float getSal()
    {
        return sal;
    }
    void setSal(float sal)
    {
        this->sal = sal;
    }
    virtual void accept()
    {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> sal;
    }
    virtual void display()
    {
        cout << "ID: " << id << endl << "Salary: " << sal << "Rs." << endl;
    }
};

class Manager :virtual public Employee
{
private:
    float bonus;

public:
    Manager() :Manager(0, 0, 0)
    {
    }
    Manager(int id, float sal, float bonus)
    {
        // cout << "Manager Constructor" << endl;
        Employee::setId(id);
        Employee::setSal(sal);
        this->bonus = bonus;
    }
    // ~Manager()
    // {
    //     cout << "Manager Destructor" << endl;
    // }
    float getBonus()
    {
        return bonus;
    }
    void setBonus(float bonus)
    {
        this->bonus = bonus;
    }
    virtual void accept()
    {
        Employee::accept();
        this->accept_manager();
    }
    virtual void display()
    {
        Employee::display();
        this->display_manager();
    }

protected:
    virtual void accept_manager()
    {
        cout << "Enter Bonus: ";
        cin >> bonus;
    }
    virtual void display_manager()
    {
        cout << "Bonus = " << bonus << "Rs." << endl;
    }
};

class Salesman :virtual public Employee
{
private:
    float comm;

public:
    Salesman() :Salesman(0, 0, 0)
    {
    }
    Salesman(int id, float sal, float comm)
    {
        // cout << "Salesman Constructor" << endl;
        Employee::setId(id);
        Employee::setSal(sal);
        this->comm = comm;
    }
    // ~Salesman()
    // {
    //     cout << "Salesman Destructor" << endl;
    // }
    float getComm()
    {
        return comm;
    }
    void setComm(float comm)
    {
        this->comm = comm;
    }
    virtual void accept()
    {
        Employee::accept();
        this->accept_salesman();
    }
    virtual void display()
    {
        Employee::display();
        this->display_salesman();
    }

protected:
    void accept_salesman()
    {
        cout << "Enter Commission of Salesman: ";
        cin >> comm;
    }
    void display_salesman()
    {
        cout << "Commission of Salesman= " << comm << "Rs." << endl;
    }
};

class sales_manager : public Manager, public Salesman
{
public:
    sales_manager() :sales_manager(0, 0, 0, 0)
    {
    }
    sales_manager(int id, float sal, float bonus, float comm)
    {
        // cout << "SalesManager Constructor" << endl;
        Employee::setId(id);
        Employee::setSal(sal);
        Manager::setBonus(bonus);
        Salesman::setComm(comm);
    }
    // ~sales_manager()
    // {
    //     cout << "SalesManager Destructor" << endl;
    // }
    void accept()
    {
        Employee::accept();
        accept_manager();
        accept_salesman();
    }
    void display()
    {
        Employee::display();
        display_manager();
        display_salesman();
    }
};

int main()
{
    int choice, count = 0;
    int countEmployee = 0, countManager = 0, countSalesman = 0, countSalesManager = 0;
    int n;
    cout << "Enter the number of Employees: ";
    cin >> n;
    Employee* ptr[n];
    for (int i = 0;i < n;i++)
    {
        ptr[i] = NULL;
    }
    do {
        cout << "============================" << endl;
        cout << "0. Exit" << endl;
        cout << "1.Accept Employee" << endl;
        cout << "2. Accept Manager" << endl;
        cout << "3. Accept Salesman" << endl;
        cout << "4. Accept Sales Manager" << endl;
        cout << "5. Display Employee" << endl;
        cout << "6. Display Manager" << endl;
        cout << "7. Display Salesman" << endl;
        cout << "8. Display Sales Manager" << endl;
        cout << "9. Display All" << endl;
        cout << "============================" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            if (count < n)
            {
                ptr[count] = new Employee();
                ptr[count]->accept();
                count++;
            }
            else
            {
                cout << "Limit reached." << endl;
            }
            break;

        case 2:
            if (count < n)
            {
                ptr[count] = new Manager();
                ptr[count]->accept();
                count++;
            }
            else
            {
                cout << "Limit reached." << endl;
            }
            break;

        case 3:
            if (count < n)
            {
                ptr[count] = new Salesman();
                ptr[count]->accept();
                count++;
            }
            else
            {
                cout << "Limit reached." << endl;
            }
            break;

        case 4:
            if (count < n)
            {
                ptr[count] = new sales_manager();
                ptr[count]->accept();
                count++;
            }
            else
            {
                cout << "Limit reached." << endl;
            }
            break;

        case 5:
            for (int i = 0;i < n;i++)
            {
                if (typeid(*ptr[i]) == typeid(Employee))
                {
                    ptr[i]->display();
                    countEmployee++;
                }
            }
            cout << "There are " << countEmployee << " Employees." << endl;
            break;

        case 6:
            for (int i = 0;i < n;i++)
            {
                if (typeid(*ptr[i]) == typeid(Manager))
                {
                    ptr[i]->display();
                    countManager++;
                }
            }
            cout << "There are " << countManager << " Managers." << endl;

            break;

        case 7:
            for (int i = 0;i < n;i++)
            {
                if (typeid(*ptr[i]) == typeid(Salesman))
                {
                    ptr[i]->display();
                    countSalesman++;
                }
            }
            cout << "There are " << countSalesman << " Salesman." << endl;

            break;

        case 8:
            for (int i = 0;i < n;i++)
            {
                if (typeid(*ptr[i]) == typeid(sales_manager))
                {
                    ptr[i]->display();
                    countSalesManager++;
                }
            }
            cout << "There are " << countSalesManager << " SalesManagers." << endl;

            break;

        case 9:
            for (int i = 0;i < count;i++)
            {
                ptr[i]->display();
            }
            break;

        default:
            cout << "Invalid Input" << endl;
            break;
        }
    } while (choice != 0);
    int len = sizeof(ptr) / sizeof(ptr[0]);
    for (int i = 0;i < len;i++)
    {
        delete ptr[i];
        ptr[i] = NULL;
    }
    return 0;
}
