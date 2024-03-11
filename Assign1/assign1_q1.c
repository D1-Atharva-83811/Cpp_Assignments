// Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members
// day, month, year. Implement the following functions.
// void initDate(struct Date* ptrDate);
// void printDateOnConsole(struct Date* ptrDate);
// void acceptDateFromConsole(struct Date* ptrDate);

#include <stdio.h>

struct Date{
    int day;
    int month;
    int year;
};

struct Date d;

void initDate(struct Date *ptr)
{
    ptr->day=1;
    ptr->month=1;
    ptr->year=1;
}

void printDateOnConsole(struct Date *ptr)
{
    printf("The date is : %d/%d/%d\n",ptr->day,ptr->month,ptr->year);
}

void acceptDateFromConsole(struct Date *ptr)
{
    printf("Enter Date: ");
    scanf("%d",&ptr->day);
    printf("Enter Month: ");
    scanf("%d",&ptr->month);
    printf("Enter Year: ");
    scanf("%d",&ptr->year);
}

int main()
{
    int choice;
    int x=0;
    while (x!=1)
    {
        printf("Enter Choice: \n");
        printf("1. Initiate\n");
        printf("2. Accept\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            initDate(&d);
            break;
        case 2:
            acceptDateFromConsole(&d);
            break;
        case 3:
            printDateOnConsole(&d);
            break;
        case 4:
            x=1;
            break;
        default:
            printf("Invalid input!");
            break;
        }
    }
    return 0;
}

