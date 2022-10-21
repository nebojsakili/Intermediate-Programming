//1001934192 Nebojsa Kilibarda
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 7

int getAccountInfo(char filename[], char accountHolder[][20], int followers[]);
void exitReport(char filename[], char accountHolder[][20], int followers[]);
int	findPerson(char accountHolder[][20], char person[]);

int main(int argc, char **argv)
{
    char filename[20];
    char accountHolder[10][20];
    int followers[10];
    char answer[5];
    char person[10];
    int index = 0;
    int newFollowers;
    int n=1;

getAccountInfo(argv[1], accountHolder, followers);
    
while(n)
{    
    printf("Add followers or exit?\n");
    scanf("%s", answer);

if (!strcmp("add",answer))
{
    printf("Enter person to find: \n");
    scanf("%s", person);
    index = findPerson(accountHolder, person); //Tries to match input with names of account holders, returns index of account holder if match found
    
    if (index != -1) // -1 is returned if the input doesnt match any of the account holders
    {
    printf("%s has %d followers, how many do you want to add?\n", accountHolder[index], followers[index]);
    scanf("%d", &newFollowers);
    followers[index]+=newFollowers;
    printf("%s now has %d followers\n", accountHolder[index], followers[index]);
    }
    else
    {
    printf("That person could not be found.\n");
    }
}
else if (!strcmp("exit",answer))
{
    printf("Outputting file..");
    exitReport(argv[2], accountHolder, followers); //prints the data to an output file and declares account holder with most followers
    n=0;
}
else
{
    printf("Invalid command. ");
}
}
}

int getAccountInfo(char filename[], char accountHolder[][20], int followers[])
{

FILE *fIn = fopen(filename, "r");

if (!fIn)
    {
    printf("File could not be opened properly.\n");
    return 0;
    }
else
    {
    char line[10];    
    int i=0;    
    while(fgets(line, 10, fIn))
        {
        strtok(line,"\n");    
        strcpy(accountHolder[i], line);
        fgets(line, 10, fIn);
        strtok(line,"\n");
        followers[i]=atoi(line);
        i++;
        }
    return 1;
    }
    fclose(fIn);
}

void exitReport(char filename[],char accountHolder[][20], int followers[])
{
    int ct;
    int mostFollowers=0;
    char mostFollowed[10];
    FILE *fOut = fopen(filename, "w");

    for(ct=0; ct<SIZE; ct++)
    {
    if (mostFollowers<followers[ct])
    {
        mostFollowers=followers[ct];
        strcpy(mostFollowed, accountHolder[ct]);
    }
    fprintf(fOut,"---Followers for %s: %d\n", accountHolder[ct], followers[ct]);   
    }
    fprintf(fOut,"\n--Most followers: %s with %d followers!\n", mostFollowed, mostFollowers);
    fprintf(fOut,"This user gets %d dollars!", 5*mostFollowers); 
}

int	findPerson(char accountHolder[][20], char person[]) //returns index of accountHolder array if it matches the user input, otherwise returns -1
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        if (!strcmp(accountHolder[i], person))
        {
            return i;
        }
    }
    return -1; 
}