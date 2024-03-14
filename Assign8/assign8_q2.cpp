// Q2. Write a class to store Account information of Bank customer by using following class diagram.
// Use enum to store information of account type. Create an array of 5 Accounts in main() and accept
// their details from user. Write Menu driven program to deposit/withdraw amount from the account.
// After each transaction display updated account balance. Provide appropriate getters/setters with
// necessary validations. Throw exceptions for invalid values. Also implement an exception class
// InsufficientFunds. In withdraw() member function, if sufficient balance is not available
// in account, throw this exception.

#include<iostream>
using namespace std;

class InsufficientFunds
{
private:
    int accid;
    double cur_balance;
    double withdraw_amount;

public:
    InsufficientFunds(int id, double balance, double amount)
    {
        accid = id;
        cur_balance = balance;
        withdraw_amount = amount;
    }

    void display()
    {
        cout << "Insufficient Balance in account " << accid << endl;
        cout << "Balance is= " << cur_balance << endl;
        cout << "Amount wanted to withdraw= " << withdraw_amount << endl;
    }
};
enum account_type
{
    SAVING,
    CURRENT,
    DMAT
};

class Account
{
private:
    int id;
    account_type type;
    double balance;

public:
    Account() :Account(0, SAVING)
    {

    }
    Account(int id, account_type type)
    {
        this->id = id;
        this->type = type;
    }

    void accept()
    {
        int t;
        cout << "Enter Account ID: ";
        cin >> id;
        cout << "Enter account type: " << endl;
        cout << "1. Savings" << endl;
        cout << "2. Current" << endl;
        cout << "3. DMAT" << endl;
        cin >> t;
        if (t == 1)
            type = SAVING;
        else if (t == 2)
            type = CURRENT;
        else
            type = DMAT;
        cout << "Enter Account Balance: ";
        cin >> balance;
    }

    void display()
    {
        cout << "Account Type: ";
        if (type == 0)
            cout << "Savings" << endl;
        else if (type == 1)
            cout << "Current" << endl;
        else
            cout << "DMAT" << endl;
        cout << "Account ID: " << id << endl;
        cout << "Balance: " << balance << endl;
    }

    void setId(int id)
    {
        this->id = id;
    }

    void setType(account_type type)
    {
        this->type = type;
    }

    int getId()
    {
        return id;
    }

    account_type getType()
    {
        return type;
    }

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "The updated Balance is: " << getBalance() << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            throw InsufficientFunds(id, balance, amount);
        }

        balance -= amount;
        cout << "The updated Balance is: " << getBalance() << endl;
    }
};

int main()
{
    int choice;
    int accno, amount;
    Account a[5];
    do {
        cout << "0. Exit" << endl;
        cout << "1. Enter Account details" << endl;
        cout << "2. Display Account Details" << endl;
        cout << "3. Deposit Amount" << endl;
        cout << "4. Withdraw Amount" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            for (int i = 0;i < 5;i++)
            {
                a[i].accept();
            }
            break;

        case 2:
            for (int i = 0;i < 5;i++)
            {
                a[i].display();
            }
            break;

        case 3:
            cout << "Enter account number to deposit in: ";
            cin >> accno;
            for (int i = 0;i < 5;i++)
            {
                if (accno == a[i].getId())
                {
                    cout << "Enter Amount to deposit: ";
                    cin >> amount;
                    a[i].deposit(amount);
                }
            }
            break;

        case 4:
            cout << "Enter account number to withdraw from: ";
            cin >> accno;
            for (int i = 0;i < 5;i++)
            {
                if (accno == a[i].getId())
                {
                    cout << "Enter Amount to withdraw: ";
                    cin >> amount;
                    try
                    {
                        a[i].withdraw(amount);
                    }
                    catch (InsufficientFunds& error)
                    {
                        error.display();
                    }
                }
            }
            break;
        }
    } while (choice != 0);

    return 0;
}