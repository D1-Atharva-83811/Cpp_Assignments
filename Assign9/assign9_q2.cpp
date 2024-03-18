// Q2. Modify assignment 8 - Q2 to save all accounts data into STL list. Provide additional facility to
// display all accounts.


#include<iostream>
using namespace std;
#include<vector>

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
    const int id;
    account_type type;
    float balance;
    static int id_gen;

public:
    Account() :Account(SAVING)
    {

    }
    Account(account_type type) :id(++id_gen)
    {
        this->type = type;
        balance = 0;
    }

    void accept()
    {
        int t;
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
        cout << "******************************" << endl;
        cout << "Account ID: " << id << endl;
        cout << "Account Type: ";
        if (type == 0)
            cout << "Savings" << endl;
        else if (type == 1)
            cout << "Current" << endl;
        else
            cout << "DMAT" << endl;
        cout << "Balance: " << balance << endl;
        cout << "******************************" << endl;
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
int Account::id_gen = 83800;

int main()
{
    int choice;
    int accno, amount;
    vector<Account*>v;
    Account* a = NULL;
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
            a = new Account();
            a->accept();
            v.push_back(a);
            break;

        case 2:
            for (int i = 0;i < v.size();i++)
            {
                v[i]->display();
            }
            break;

        case 3:
            cout << "Enter account number to deposit in: ";
            cin >> accno;
            for (int i = 0;i < v.size();i++)
            {
                if (accno == v[i]->getId())
                {
                    cout << "Enter Amount to deposit: ";
                    cin >> amount;
                    v[i]->deposit(amount);
                }
                else
                {
                    cout << "Account does not Exits." << endl;
                }
            }
            break;

        case 4:
            cout << "Enter account number to withdraw from: ";
            cin >> accno;
            for (int i = 0;i < v.size();i++)
            {
                if (accno == v[i]->getId())
                {
                    cout << "Enter Amount to withdraw: ";
                    cin >> amount;
                    try
                    {
                        v[i]->withdraw(amount);
                    }
                    catch (InsufficientFunds& error)
                    {
                        error.display();
                    }
                }
                else
                {
                    cout << "Account does not Exist." << endl;
                }
            }
            break;
        }
    } while (choice != 0);

    return 0;
}