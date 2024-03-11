// Q1. Write a Matrix class. Allocate memory dynamically in parameterized constructor. Also write
// parameter-less constructor. Write accept() and print() functions.
// Also provide add(), subtract(), multiply() and transpose() function.

#include <iostream>
using namespace std;

class Matrix
{
private:
    int** arr;
    int a;

public:
    Matrix() : Matrix(2)
    {
    }
    Matrix(int a)
    {
        this->a = a;
        arr = new int* [a];
        for (int i = 0; i < a; i++)
        {
            arr[i] = new int[a];
        }
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    void accept()
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                cout << "Enter Element at " << i << "," << j << " : ";
                cin >> arr[i][j];
            }
        }
    }
    void print()
    {
        cout << "Elements are: " << endl;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                cout << " " << arr[i][j];
            }
            cout << endl;
        }
    }
    void addMatrix(Matrix m2)
    {
        Matrix r(a);
        for (int i = 0;i < a;i++)
        {
            for (int j = 0;j < a;j++)
            {
                r.arr[i][j] = arr[i][j] + m2.arr[i][j];
            }
        }
        cout << "Addition is:" << endl;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                cout << " " << r.arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    void subtractMatrix(Matrix m2)
    {
        Matrix r(a);
        for (int i = 0;i < a;i++)
        {
            for (int j = 0;j < a;j++)
            {
                r.arr[i][j] = arr[i][j] - m2.arr[i][j];
            }
        }
        cout << "Subtraction is:" << endl;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                cout << " " << r.arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    void multiplyMatrix(Matrix m2)
    {
        Matrix r(a);
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                for (int k = 0;k < a;k++)
                {
                    r.arr[i][j] += (arr[i][k] * m2.arr[k][j]);
                }
            }
        }
        cout << "Multiplication is:" << endl;
        for (int i = 0;i < a;i++)
        {
            for (int j = 0;j < a;j++)
            {
                cout << " " << r.arr[i][j];
            }
            cout << endl;
        }
        cout << endl;

    }
    void transposeMatrix()
    {
        Matrix r(a);
        for (int i = 0;i < a;i++)
        {
            for (int j = 0;j < a;j++)
            {
                r.arr[i][j] = arr[j][i];
            }
        }
        cout << "Transpose Matrix:" << endl;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                cout << " " << r.arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    int choice;
    int c;
    int a;
    int x;
    cout << "1. Default size matrix";
    cout << "2. Custom size matrix";
    cin >> c;
    cout << endl;
    switch (c)
    {
    case 1:
        cout << endl;
        a = 2;
        break;
    case 2:
        cout << "Enter size of matrix: ";
        cin >> a;
        cout << endl;
        break;
    default:
        cout << "Invaid Input!" << endl;
        break;
    }
    Matrix m1(a);
    Matrix m2(a);
    cout << "Enter elements of M1: " << endl;
    m1.accept();
    cout << "Enter elements of M2: " << endl;
    m2.accept();
    do
    {
        cout << "*********************************" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Print Matrix " << endl;
        cout << "2. Add Matrices" << endl;
        cout << "3. Subtract Matrices" << endl;
        cout << "4. Multiply Matrices" << endl;
        cout << "5. Transpose of Matrix" << endl;
        cout << "*********************************" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            cout << " Matrix M1: " << endl;
            m1.print();
            cout << endl;
            cout << " Matrix M2: " << endl;
            m2.print();
            cout << endl;
            break;

        case 2:
            m1.addMatrix(m2);
            break;

        case 3:
            m1.subtractMatrix(m2);
            break;

        case 4:
            m1.multiplyMatrix(m2);
            break;

        case 5:
            cout << endl;
            cout << "1. Transpose of Matrix M1" << endl;
            cout << "2. Transpose of Matrix M2" << endl;
            cin >> x;
            if (x == 1)
            {
                m1.transposeMatrix();
            }
            else if (x == 2)
            {
                m2.transposeMatrix();
            }
            else
            {
                cout << "Invatid Input!!";
                return -1;
            }
            break;

        default:
            cout << "Invalid Input!!!";
            break;
        }
    } while (choice != 0);

    return 0;
}