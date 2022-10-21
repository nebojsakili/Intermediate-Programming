#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

#define SIZE 10

//Stack Implementation using struct array
typedef struct stack{
    float stk[SIZE];
    int top;
}Stack;

void push(Stack* s, float add);
float pop(Stack* s);
void display(Stack* s);
int is_full(Stack* s);
int is_empty(Stack* s);


//Queue Implementation using a linked list
typedef struct queue_node{
    char* name;
    int number;
    struct queue_node* next;
}QUEUE_NODE;

typedef struct queue{
    QUEUE_NODE* front;
    QUEUE_NODE* rear;
}QUEUE;

void enqueue(QUEUE* q, char* full_name, int flight_number);
void dequeue(QUEUE* q);
void print_queue(QUEUE_NODE* q);
void free_queue(QUEUE* q);


#endif
