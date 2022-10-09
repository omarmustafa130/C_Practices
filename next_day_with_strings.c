#include <stdio.h>
typedef enum month
{
    jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
}month;

typedef struct date
{
    month m;
    int day;
}date;

int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

char* GetEnumID(month m)
{
    switch (m)
    {
        case jan: return "jan"; break;
        case feb: return "feb"; break;
        case mar: return "mar"; break;
        case apr: return "apr"; break;
        case may: return "may"; break;
        case jun: return "jun"; break;
        case jul: return "jul"; break;
        case aug: return "aug"; break;
        case sep: return "sep"; break;
        case oct: return "oct"; break;
        case nov: return "nov"; break;
        case dec: return "dec"; break;
    }
}

char* nextday(date d)
{
    int monthlen = 0, daylen=0, count =0;
    char* FinalString;
    char days [2];
    if (d.day>32 || d.day<1)
    {
        printf("Error");
        return;
    }
    if ((d.m == feb && d.day==28) || ((d.m == apr || d.m == jun || d.m == sep || d.m == nov) && d.day ==30))
    {
        d.m++;
        d.day=0;
    }
    sprintf(days, "%d", d.day+1); //4,6,9,11
    char* months=GetEnumID(d.m);
    monthlen = strlen(months);
    daylen = strlen(days);
    FinalString = (char*) malloc(monthlen + daylen + 1);
    strcpy(FinalString, months);
    strcat(FinalString, ", ");
    strcat(FinalString, days);
    return FinalString;
}

void PrintDate(char* finalString)
{
    int monthlen = 0, daylen=0, count =0;
    char months[3] = {finalString[0], finalString[1], finalString[2]};
    char days [2] = {finalString[5], finalString[6]};
    if (strcmp(months, "jan")==0) printf("%s","January, ");
    else if (strcmp(months, "feb")==0) printf("%s", "February, ");
    else if (strcmp(months, "mar")==0) printf("%s", "March, ");
    else if (strcmp(months, "apr")==0) printf("%s", "April, ");
    else if (strcmp(months, "may")==0) printf("%s", "May, ");
    else if (strcmp(months, "jun")==0) printf("%s", "June, ");
    else if (strcmp(months, "jul")==0) printf("%s", "July, ");
    else if (strcmp(months, "aug")==0) printf("%s", "August, ");
    else if (strcmp(months, "sep")==0) printf("%s", "September, ");
    else if (strcmp(months, "oct")==0) printf("%s", "October, ");
    else if (strcmp(months, "nov")==0) printf("%s", "November, ");
    else if (strcmp(months, "dec")==0) printf("%s", "December, ");
    printf("%s", days);
}
int main()
{
    date d = {feb, 28};
    PrintDate(nextday(d));
    return 0;
}
