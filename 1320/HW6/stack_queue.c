#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_queue.h"

/*STACK FUNCTIONS*/

//checking if the stack is full
int is_full(Stack* s)
{
    if(s->top == (SIZE - 1))
    {
        return 1;
    }
    return 0;
}

//Checks if the stack is empty
int is_empty(Stack* s)
{
    if((s->top == 0) && (s->stk[s->top] == 0))
    {
        printf("Stack is empty.\n");
        return 1;
    }
    return 0;
}

//pushing a new element on top of the stack
void push(Stack* s, float add)
{
    float n;
    int check = is_full(s);
    if(check)
    {
        printf("Stack is full.\n");
        return;
    }
    else
    {
        s->top++;
        s->stk[s->top] = add;
    }
    return;
}

//popping an element from the top of the stack
float pop(Stack* s)
{
    float n;
    n = s->stk[s->top];
    s->top = s->top - 1;
    return n;
}


//Displays the current stack elements
void display(Stack* s)
{
    int i;
    for(i = 0; i < s->top; i++)
    {
        printf("%.2f\n", s->stk[i+1]);
    }
    printf("\n");
}


/* QUEUE FUNCTIONS */

//adds an element to the queue
void enqueue(QUEUE* q, char* full_name, int flight_number)
{
    QUEUE_NODE* q_node = malloc(sizeof(QUEUE_NODE));
    if(q_node == NULL)
    {
        printf("Error allocating memory.\n");
        return;
    }
    q_node->name = malloc(15);
    strcpy(q_node->name, full_name);
    q_node->number = flight_number;
    q_node->next = NULL;

    if(q->front == NULL)
    {
        q->front = q_node;
        q->rear = q_node;
    }
    else
    {
        q->rear->next = q_node;
        q->rear = q_node;
    }
}

//removes an element from the front of the queue
void dequeue(QUEUE* q)
{
    if(q->front)
    {
        QUEUE_NODE* temp = q->front;
        q->front=q->front->next;
        free(temp);
        return;
    }
    else
    {
        printf("Queue is empty...\n");
        return;
    }
}

//call to print the entire queue and output info to a file
void print_queue(QUEUE_NODE* q)
{
    if(q == NULL)
    {
        return;
    }
    else
    {
        printf("%s - %d\n", q->name, q->number);

        //using recursion to cycle through the queue
        print_queue(q->next);

    }
}

//frees the dynamically allocated memory after use
void free_queue(QUEUE* q)
{
    QUEUE_NODE* temp;
    while(q->front)
    {
        free(q->front->name);

        temp = q->front;
        q->front = q->front->next;

        free(temp);
    }
}