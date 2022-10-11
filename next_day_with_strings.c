#include <stdio.h>
#include <stdlib.h>

typedef enum months      //declaring an enum of months
{
    jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
}month;

typedef struct date     //struct date
{
    month m;
    int day;
}date;

int MaxDaysInMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};    //array that holds how many days each month have
int MaxDays = 30;                                                   //Initial value of a variable that holds maximum days of a month

#define NumberOfTestCases 5                                         //no of test cases


date nextday(date d)                           //a function to get the next day
{
    date NextDay;                                   //the object of struct that will hold the next day
    if (d.day < MaxDaysInMonths[d.m])                   //check if date entered is less than no of days of the month
    {
        NextDay.m = d.m; NextDay.day = (d.day+1)%MaxDaysInMonths[d.m];          //next day = same month + (day + 1)
        return NextDay;
    }
    if (d.day == MaxDaysInMonths[d.m])          //check if date entered is equal to no of days of the month
    {
        NextDay.m = (d.m + 1)%12; NextDay.day = 1;          //next day = (next month)%12 (so we never get past 12), day is the 1st day of the new month)
        return NextDay;
    }
    if (d.day > MaxDaysInMonths[d.m])               //Error in input
    {
        printf("Error");
        return;
    }
}

void PrintDate(date d)                           //a function that prints a date int this form: "March, 21" instead of "mar 21"
{
    switch(d.m)
    {
        case jan:
            if(d.day>0 && d.day<=MaxDaysInMonths[0])        //check the input date for faulty inputs
                printf("January, %d", d.day);
            break;
        case feb:
            if(d.day>0 && d.day<=MaxDaysInMonths[1])
                printf("February, %d", d.day);
            break;
        case mar:
            if(d.day>0 && d.day<=MaxDaysInMonths[2])
                printf("March, %d", d.day);
            break;
        case apr:
            if(d.day>0 && d.day<=MaxDaysInMonths[3])
                printf("April, %d", d.day);
            break;
        case may:
            if(d.day>0 && d.day<=MaxDaysInMonths[4])
                printf("May, %d", d.day);
            break;
        case jun:
            if(d.day>0 && d.day<=MaxDaysInMonths[5])
                printf("June, %d", d.day);
            break;
        case jul:
            if(d.day>0 && d.day<=MaxDaysInMonths[6])
                printf("July, %d", d.day);
            break;
        case aug:
            if(d.day>0 && d.day<=MaxDaysInMonths[7])
                printf("August, %d", d.day);
            break;
        case sep:
            if(d.day>0 && d.day<=MaxDaysInMonths[8])
                printf("September, %d", d.day);
            break;
        case oct:
            if(d.day>0 && d.day<=MaxDaysInMonths[9])
                printf("October, %d", d.day);
            break;
        case nov:
            if(d.day>0 && d.day<=MaxDaysInMonths[10])
                printf("November, %d", d.day);
            break;
        case dec:
            if(d.day>0 && d.day<=MaxDaysInMonths[11])
                printf("December, %d", d.day);
            break;
    }
}
int main()
{
    date d1 = {jan, 1};
    date d2 = {feb, 28};
    date d3 = {mar, 14};
    date d4 = {oct, 31};
    date d5 = {dec, 31};

    date TestCases[NumberOfTestCases] = {d1,d2,d3,d4,d5};

    for (int i = 0; i<NumberOfTestCases; i++)
    {
        PrintDate(nextday(TestCases[i]));
        printf("\n");
    }
    return 0;
}
