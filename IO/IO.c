#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <ctype.h>
double avg(int arr[], int k);
double max(int arr[], int k);

int main() {
    FILE *fp;                           //init a pointer to the file
    fp = fopen("Integers.txt","r");     //open the file in read mode
    int m;
    int k;
    int counter = 0;
    if((m = fgetc(fp)) != EOF)          //get the first char
    {
        fseek(fp, 0L, SEEK_SET);        //go to the first line again
        (fscanf(fp, "%d ", &k));        //read the first number as integer and store it in k

    }
    fseek(fp, 0L, SEEK_SET);            //go to the start of the file again
    while((m = fgetc(fp)) != EOF) {
        if (m == ' ') {                 //count spaces, meaning counting how many integer found before these spaces
            counter++;
        }
    }
    counter++;                          // one more for the last number
    fseek(fp, 0L, SEEK_SET);            //go to the first line in file
    int* n = (int*) malloc(k);          //create an array with size k (first number in)
    for (int i = 0; i < k; i++)         //read integers to the kth number
        {
        if (fscanf(fp, "%d ", &n[i]) != 1)
        {
            break;
        }
    }
    for (int a = 0; a < k; a++) {        //print the numbers in the array
        printf("%d ", n[a]);
    }
    printf("\n The average is: %lf", avg(n, k));
    printf("\n The max number is: %lf", max(n, k));

}

double avg(int* arr, int k)
{
    double sum = 0.0, avg;
    for (int i=0; i<k; i++)
    {
        sum+=arr[i];
    }
    avg = sum/k;
    return avg;
}

double max(int arr[], int k)
{
    int max = arr[0];
    for (int i = 1; i<k; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}
