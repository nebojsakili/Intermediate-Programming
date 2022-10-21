#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char *color;
    int **details;
    struct Node *next;
}Node;

//takes filename and creates a linked list of the string of lights
Node *light_info(char *filename)
{
    FILE *fp = fopen(filename, "r");
    char *line = malloc(20);
    char *token;
    Node *head = NULL;
    Node *temp = NULL;

    //while loop reads in information from the file into the linked list
    while(fgets(line, 20, fp))
    {
        token = strtok(line, ",");
        temp = malloc(sizeof(Node));
        temp->color = malloc(10);
        strcpy(temp->color, token);

        //dynamically allocating memory for two int pointers
        temp->details = malloc(sizeof(int*)*2);
        temp->details[0] = malloc(sizeof(int));
        token = strtok(NULL, ",");
        temp->details[0][0] = atoi(token);

        temp->details[1] = malloc(sizeof(int));
        token = strtok(NULL, "\n");
        temp->details[1][0] = atoi(token);

        //connecting members of the linked list
        temp->next = head;
        head = temp;
    }
    free(line);
    return head; //returns the head of the linked list
}

// Checks if the user is trying to perform a valid command
int lights_check(int on_off, char *ans)
{
    int i = 0;
    //if the lights are already off, and the command is 'off'
    if(on_off == 0 && !strcmp(ans, "off"))
    {
        printf("Lights are already turned off.\n");
        return i;
    }
    //if the command given is 'on' and lights are already on
    else if(on_off == 1 && !strcmp(ans, "on"))
    {
        printf("Lights are already turned on.\n");
        return i;
    }
    //returns 1 if the command given is appropriate
    else
    {
        return i+1;
    }
}

int show_lights(Node *head, char *instruction)
{
    //if the command 'on' is given, first character of each color is printed
    if(!strcmp(instruction, "on"))
    {
    printf("***Turning lights on:\n");
        while(head)
        {
            for(int i = 0; i < head->details[0][0]; i++)
            {
                printf("%c", head->color[0]);
            }
            printf(" "); //space between each light
            head=head->next;
        }
        printf("\n");
        return 1;
    }

    //if the command 'off' is given, dashes are printed instead of first letter of the color
    else if(!strcmp(instruction, "off"))
    {
        printf("Turning lights off..\n");
        while(head)
        {
            for(int i = 0; i < head->details[0][0]; i++)
            {
                printf("-");
            }
            printf(" ");
            head=head->next;
        }
        printf("\n");
        return 0;        
    } 
}

int main(int argc, char** argv)
{
    int on_off = 0;
    int n = 0;
    int check = 1;
    char *answer = malloc(10);
    //calls light_info to populate linked list and sets lights to be the head
    Node *lights = light_info(argv[1]);
    printf("Type in 'on' or 'off' to operate lights, or exit to terminate\n");
    
    while(check)
    {
        scanf(" %s", answer);
        if(!strcmp(answer, "off"))
        {
            n = lights_check(on_off, answer);
            if(n)
            {
                on_off = show_lights(lights, "off");
            }
        }
        else if(!strcmp(answer, "on"))
        {
            n = lights_check(on_off, answer);
            if(n)
            {
                on_off = show_lights(lights, "on");
            }
        }
        else if(!strcmp(answer, "exit"))
        {
            printf("Exiting..\n");
            free(answer);
            free(lights);
            check = 0;
        }
        else
        {
            printf("Valid commands are: on, off or exit\n");
        }
    }
}