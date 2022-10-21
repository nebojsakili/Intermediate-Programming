#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{ 
   
  char *country;  /*country name*/ 
  char virus; /*virus*/ 
  int start_cases; /*number of initial cases reported*/ 
  float infection_rate; /*daily rate of infection*/ 
  struct Node* next; 
   
}Node;

/*This function opens a file and creates a linked list of each country being 
monitored for infections. It returns the head of the linked list*/
Node* read_file()
{
    Node* temp = NULL;
    Node* head = NULL;
    FILE *fp = fopen("infectionstuff.txt", "r");
    char *line = malloc(20);
    char *token;

    while(fgets(line, 20, fp))
    {
        temp = malloc(sizeof(Node));

        token = strtok(line, ",");
        temp->country=malloc(10);
        strcpy(temp->country,token);

        token = strtok(NULL, ",");
        temp->virus=token[0];

        token = strtok(NULL, ",");
        temp->start_cases=atoi(token);

        token = strtok(NULL, "\n");
        temp->infection_rate=atof(token);

        temp->next = head;
        head = temp;

    }
    free(line);
    return head;
}