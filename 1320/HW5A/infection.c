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

//This function prints out all of the current cases 
void print_cases(Node* head, int day, int aid_workers)
{
    printf("Day %d (Aid Workers Available: %d)\n", day, aid_workers);
    //handles the case we are printing on day 1
    if(day == 1)
    {
        while(head)
        {
            printf("\n-%s-cases %d (actual: %.4f | rate: %.0f%c daily)", head->country, head->start_cases,
            head->start_cases*1.0,head->infection_rate*100, 37);

            if(head->start_cases >= 30)
            {
                printf(" Careful...");
            }
            printf("\n");
            head = head->next;
        }
    }
    //Prints the actual value on each successive day
    else
    {
        while(head)
        {
            printf("\n-%s-cases %d (actual: %.4f | rate: %.0f%c daily)", head->country, head->start_cases,
            ((head->start_cases)+(head->start_cases)*(head->infection_rate)),head->infection_rate*100, 37);

            if(head->start_cases >= 30)
            {
                printf(" Careful...");
            }
            printf("\n");
            head = head->next;
        }
    }
}

//call to send ait to a select country
void send_aid(Node* head, char *answer, int amount)
{
    while(head)
    {
        if(!strcmp(head->country, answer))
        {
            head->infection_rate = head->infection_rate-(amount/100);
            printf("Rate for %s is now %f\n", head->country,head->infection_rate);
        }
        head = head->next;
    }
}

int main()
{
    int day = 1; //counting days from day 1
    int aid_workers = 50;
    int amount; //to hold the number of workers to send
    char ans; //to store the users selection
    char* answer = malloc(15); //to store the user input
    char* token;
    char* country; //to store the name of country to send aid to

    Node* virus = read_file();
    Node* head = virus;

    print_cases(virus, day, aid_workers);

    while(aid_workers)
    {
        scanf(" %c", &ans);

        while(ans != 's')
        {
        day++;   
            //moving to the next day
            while(virus);
            {
                virus->start_cases = virus->start_cases + virus->start_cases*virus->infection_rate;
                virus = virus->next;
            } 
        virus = head;
        print_cases(virus, day, aid_workers);
        scanf(" %c", &ans);
        }

        printf("Which country to send aid to and how many?\n");
        getchar();
        fgets(answer, 15, stdin);
        token = strtok(answer, " ");
        strcpy(country, token);

        token = strtok(NULL, " ");
        strcat(country, " ");
        strcat(country, token);

        token = strtok(NULL, "\n");
        amount = atoi(token);

        if(amount > aid_workers)
        {
            printf("we don't have that many workers available. We currently have %d\n", aid_workers);
        }
        else if(amount%10)
        {
            printf("Not a valid number of aid workers. Enter multiple of 10.\n");
        }
        else
        {
        while(virus)
            {   
            if(!strcmp(virus->country, country))
            {
                virus->infection_rate = virus->infection_rate-(float)amount/100;
                printf("Rate for %s is now %f\n", virus->country, virus->infection_rate);
            }
                virus = virus->next;
            }
            aid_workers -= amount;
            virus = head;
        }
    }
    printf("No aid workers left. Exiting.\n");

}