#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    double avg;     /*average to be calculated*/
    double sum=0.0; /*average = sum/count so we need to calculate sum*/
    FILE* ptr_to_file;  /*pointer to the text file that contains the raw data*/
    ptr_to_file=fopen("elephant_seal_data.txt", "r");   /*open the file in read mode*/
    int numberArray[1]; /*initialize a one element array, we read all numbers into it so we can get how many numbers in the file*/
    int count =0;
    while(1)
    {
        fscanf(ptr_to_file, "%d ", &numberArray[0]);        /*scan a number and put it in the array*/
        if ( feof(ptr_to_file))                              /* if it is the end of the file, get the last element then break*/
        {
          printf("Number is: %d\n\n", numberArray[0]);
          count++;
          break;
        }
        printf("Number is: %d\n\n", numberArray[0]);
        count++;                                                /*incrementing counter of the numbers in the file*/
    }
    fclose(ptr_to_file);                                           /*close the file first so we can read it from the beginning again*/
    ptr_to_file=fopen("elephant_seal_data.txt", "r");
    int* newArr = (int*) malloc(count);                            /*initialise a dynamic array that can only hold the numbers from the file*/
    for (int i =0; i<count; i++)
    {
        fscanf(ptr_to_file, "%d ", &newArr[i]);
        printf("Number is: %d\n\n", newArr[i]);
        sum+=newArr[i];
    }
    avg = sum/(double)count;
    printf("The average is : %lf", avg);

    return 0;
}
