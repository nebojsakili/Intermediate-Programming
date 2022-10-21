#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_queue.h"
#include "hw6.h"


int main(void)
{
    QUEUE* q = malloc(sizeof(QUEUE));
    q->front = NULL;
    q->rear = NULL;
    Stack money;
    Stack* s = &money;
    int k = 0; //stores the menu choice for Prompt 1
    int c = 1; //while loop trigger
    int ans = 0;
    int flight = 0; //stores the flight number to locate

    //Choose between Prompt #1 (TIP JAR) and Prompt #2 (AIRLINE)
    printf("Select prompt to run:\n1.Prompt #1\n2.Prompt #2\n");
    scanf("%d", &ans);

    //prompt one starts here
    if(ans==1)
    {
        while(c)
        {
            printf("1.Add tips\n2.Cash out\n3.Exit\n");
            scanf("%d", &k);
            if(k == 1)
            {
                //call to insert tips until done is entered
                add_tips(s);
            }
            else if(k == 2)
            {
                //call to pay out employees as well as print the current status of the tip jar
                tips_earned(s);
            }
            else if(k == 3)
            {
                //exit the while loop
                c = 0;
            } 
        }   
    }

    //prompt 2 starts here
    else if(ans == 2)
    {
        printf("Adding in customer info:\n");

        //call to enqueue data read from file
        customer_info(q);

        //call to print out the queue
        print_queue(q->front);

        printf("\nEnter four-digit flight number to locate:");
        scanf("%d", &flight);

        //call to find customers flying specific flight as well as output info to screen and file
        flight_check(q, flight);

        //frees the dynamically allocated memory
        free_queue(q);
    }
    //handle wrong input
    else
    {
        printf("Unrecognized input, terminating.\n");
    }
}