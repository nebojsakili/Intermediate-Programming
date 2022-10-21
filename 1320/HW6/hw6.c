#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_queue.h"
#include "hw6.h"

/*STACK ARRAY FUNCTIONS*/

//call to insert tips until done is entered
void add_tips(Stack *s)
{
    float add; //stores the value entered by user
    int c = 1; //serves as switch for the while loop
    char cmd[5]; //stores the command given by server
    s->top = 0;

    printf("***Tip Jar***\n");

while(c)
{
    printf("Enter tip: $");
    scanf("%s", cmd);
    printf("\n");

    //if done is given as command, exit the while loop
    if(!strcmp(cmd, "done"))
    {
        c = 0;
    }
    //not checking for invalid commands!
    else
    {
    add = atof(cmd);
    push(s, add);
    }
}
}

//call to pay out employees as well as print the current status of the tip jar
void tips_earned(Stack* s)
{
    float earned; //stores the amount earned (2xhours worked)
    float i;
    float payout = 0; //stores the value popped off the top of the stack

    printf("How many hours did you work? ");
    scanf("%f", &i);
    earned = 2*i;
    printf("\nOk, giving you $%.1f\n", earned);
    payout = pop(s);

    //if the value on top of stack is greater than earnings, return the change to the tip jar
    if(payout > earned)
    {
        push(s, (payout - earned));
    }
    //in case the payout is smaller than earnings, pops another off stack and pushes back remainder
    else if(payout < earned)
    {
        payout = payout + pop(s);
        if(payout > earned)
        {
            push(s, (payout - earned));
        }
    }

    printf("***Tip Jar(Updated)***\n");
    display(s); //displays the tip jar after cashing server out
}

////////////////////////////////
/*LINKED LIST QUEUE FUNCTIONS*/
//////////////////////////////

//call to retrieve info from file and enqueue it using linked list
void customer_info(QUEUE* q)
{
    //filename hardcoded
    FILE* fp = fopen("customers.txt", "r");
    if(!fp)
    {
        printf("Error opening file.\n");
    }
    char* line = malloc(30);
    char* token;
    char* full_name = malloc(20);
    int num;
    while(fgets(line, 30, fp))
    {
        token = strtok(line, ",");

        strcpy(full_name, token);
        strcat(full_name, " ");

        token = strtok(NULL, ",");
        strcat(full_name, token);

        token = strtok(NULL, "\n");
        num = atoi(token);
        //enqueueing the values
       enqueue(q, full_name, num);
    }
    //free memory
    free(line);
    free(full_name);
}

void flight_check(QUEUE* q, int flight_number)
{
    //filename hardcoded
    FILE* fOut;
    fOut = fopen("customersout.txt", "w");
    printf("Customers going on selected flight:\n");

    while(q->front)
    {
        if(q->front->number == flight_number)
        {
            printf("%s - %d\n", q->front->name, q->front->number);
            fprintf(fOut, "%s - %d\n", q->front->name, q->front->number);
        }
        q->front = q->front->next;
    }
    fclose(fOut);
}