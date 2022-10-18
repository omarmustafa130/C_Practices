#include <stdio.h>
#include <stdlib.h>

/* a struct to hold data and "next" link of the node*/
typedef struct link_list
{
    struct link_list* next;
    int data;
}link_list;

#define INTEGER_TEST_SET     100            //is the number of integers we want to insert into the list

/*Functions prototypes*/

/* void insert_link(int d); is a function that can insert a node into the linked list, inserting is done at the end of the list*/
/* void display_link_list(void); is a function that can display all nodes of the linked list*/
/* void sort_link_list(void); is a function that can perform a bubble sort algorithm on the linked list*/

void insert_link(int d);
void display_link_list(void);
void sort_link_list(void);

/*pointers to the linked list that will be used to go through the list*/
link_list* head = NULL;
link_list* curr = NULL;
link_list* temp = NULL;

int main()
{
    /* inserting (INTEGER_TEST_SET) random integers into the list */
    for (int i = 0; i<INTEGER_TEST_SET; i++)
        insert_link(rand()%1000);

    /* Printing the list before sorting */
    printf("Before sorting: \n");
    display_link_list();

    /* Sorting the list */
    sort_link_list();

    /* Printing the list after sorting */
    printf("\nAfter sorting: \n");
    display_link_list();

    return 0;
}


void insert_link(int d)
{
    if (head == NULL)                                       //first link
    {
        head = (link_list*) malloc(sizeof(link_list));      // Initializing a node
        head->data = d;                                     // insert a node's data
        head->next = NULL;                                  // the first node of the list points to null
    }
    else
    {

        curr = head;                                        // start from the head node
        while(curr->next != NULL)                           // loop over the list
        {
            curr = curr->next;
        }
        curr->next = (link_list*) malloc(sizeof(link_list));      //initialize a new node next to the last node
        curr = curr->next;                                        //make it the last node
        curr->data = d;                                           //insert its data
        curr->next = NULL;                                        //make it point to null
    }
}


void display_link_list(void)
{
    curr = head;                        //start from the head node
    int count = 0;                      //a counter is used to print exactly 5 in every row
    while (curr != NULL)                //loop over the list
    {
        printf("%d   ", curr->data);    //print data of the nodes
        count++;                        //increment counter
        curr = curr->next;              //proceed to the next node

        if (count == 5)                 //when a counter reaches 5 go to the next line and reset the counter
        {
            printf("\n");
            count = 0;
        }
    }

}


void sort_link_list(void)
{
    int t;
    for(int k = 0; k<INTEGER_TEST_SET; k++)                          //outer loop over the INTEGER_TEST_SET integers
    {
        temp = head;                                                 //start at the head node
        for(int i = 1; i<INTEGER_TEST_SET; i++)
        {
            if (temp->next->data < temp->data)                       //check if the next node has an int that is less in value than the current node
            {
                t=temp->data;                                        //if so, replace them
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp=temp->next;                                          //proceed to the next node
        }
    }
}
