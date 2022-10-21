//1001934192 Nebojsa Kilibarda
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct person{ 
 
  char* first_name; 
  char* last_name; 
  int* number_order_registered; //1, 2, 3? etc as shown above 
 
};

int registered(FILE *fp);
void new_register(FILE *fp);
void registered_struct(struct person* b, FILE *fp, int n);
void free_person(struct person *b, int n);

int main(int argc, char *argv[])
{
    int num; // to hold the number of people that's being asked
    int count; // to hold the number of people that are registered
    char choice[2]; // to hold the answer y/n
    FILE *fp; 
    // if the file line is not provided, print an error message
    if (argc != 2)
    {
        printf("Error: Please provide file name\n");
        return -1;
    }

    fp = fopen(argv[1], "a+");
    count = registered(fp);
    struct person p[count];
    struct person *b = malloc(sizeof(p)*count);
    // Once at least 10 people are registered, print the message that the target is reached and exit
    if (count >= 10)
    {
        printf("Target Reached! Exiting...\n");
        return 0;
    }

    printf("\nHow many people to ask right now?\n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("\n-Person %d: Would you like to register to vote?\n", i + 1);
        scanf(" %[^\n]", choice); // choice = 'y' or 'n'

        // if the choice is 'y' continue the loop
        if (choice[0] == 'y')
        {
            new_register(fp); // calls new_register, asking user to input new information (returns nothing)
            registered(fp); // calls registered, showing all names that are registered to vote so far
        }
        // if choice == 'n' print message and carry on to the next
        else if (choice[0] == 'n') 
        {
            printf("Ok.\n");
        }
    }

    printf("\n%d people asked! Taking a break.\n\n", num);
    registered_struct(b, fp, count); //calls registered_struct, printing to screen and file contents of struct array
    free_person(b, count);
    free(b);
    fclose(fp); // close the file

    return 0;
}

// to hold registered voters
int registered(FILE *fp)
{
    int currentVoters = 0;
    char line[25]; // 25 characters to hold the voters name
    printf("\n***Registered so far:***\n\n");
    fseek(fp, 0, SEEK_SET);
    // to determine the status of a previous read function
    // while we didn't reach the end of file
    while (!feof(fp))
    {
        currentVoters++;
        if (fscanf(fp, " %[^\n]", line) != EOF)
        {
            printf("%d. %s\n", currentVoters, line);  // print the name of the voters
        }
    }
    return currentVoters;
}

// Adding new voters to the register
void new_register(FILE *fp)
{
    char line[25];
    printf("Enter name: "); // enter new person to vote
    scanf(" %[^\n]", line);
    printf("Adding: %s\n", line); // adding the new person to the list of registered voters
    fprintf(fp, "%s\n", line);

    return;
}
//stores registered voters in a dynamic array of structs, prints contents to screen and file
void registered_struct(struct person *b, FILE *fp, int n)
{
    char line[40]; //to hold the line being read from fp
    char *token;
    int i; 
    FILE *fOut = fopen("people_info.txt", "w"); //file to write to
    fseek(fp, 0, SEEK_SET); //setting the register.txt file to 0 position
    printf("-Last name, First name...Number of the person!\n");
    fprintf(fOut, "-Last name, First name...Number of the person!\n");

    //reading from one file, printing to screen and other file
    for(i = 0; i < n; i++)
    {
        fgets(line, 40, fp);
        token = strtok(line, " ");
        b[i].first_name = malloc(strlen(line)+1);
        strcpy(b[i].first_name, line);

        token = strtok(NULL, "\n");
        b[i].last_name = malloc(strlen(token)+1);
        strcpy(b[i].last_name, token);
        
        b[i].number_order_registered = malloc(sizeof(int));
        *(b[i].number_order_registered) = i+1;

        printf("-%s, %s...%d!\n", b[i].last_name, b[i].first_name, *b[i].number_order_registered);
        fprintf(fOut, "-%s, %s...%d!\n", b[i].last_name, b[i].first_name, *b[i].number_order_registered);
    }
}

void free_person(struct person *b, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        free(b[i].first_name);
        free(b[i].last_name);
        free(b[i].number_order_registered);
    }
}

/*
(continuation from the problem 2A) After running the program above a few times, you end up with a 
registered list of people in the register.txt file. Your boss has asked you to take the current register.txt file and 
save all the user information into a dynamically allocated array of structs (the number should be determined 
by the number of people in the file, which your program should figure out).  Each struct should look like the 
following:  
 
struct person{ 
 
  char* first_name; 
  char* last_name; 
  int* number_order_registered; //1, 2, 3? etc as shown above 
 
} 
 
The program should then print out all the struct info in the following format (both on screen AND in a text 
file called people_info.txt: 
 
-Last name, First name...Number of the person! 
-Wojcicki, Susan...4!   //example
*/