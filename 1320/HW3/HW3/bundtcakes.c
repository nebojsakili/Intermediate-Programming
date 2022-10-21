//1001934192 Nebojsa Kilibarda
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_out(int *num, char* f[]);
int name_flavors(char n, char* f[], int *s);

int main()
{
    char line[30];
    int num;
    int *numWanted = &num;
    char *flavors[] = {"Chocolate Chocolate Chip", "Classic Vanilla", "Red Velvet", 
    "White Chocolate Raspberry", "Confetti", "Carrot", "Lemon", "Marble", "Pecan Praline"};
    
    int size = (sizeof(flavors)/sizeof(flavors[0]));
    int* size_ptr = &size;
    int cont = 1;

    while(cont)
    {

        printf("\n***MENU: ***\n 1-Pick How many you want\n 2-See if any match the first letter of your name\n 3-to exit\n");
        fgets(line, 30, stdin);
        strtok(line, "\n");

        if(!strcmp(line, "1"))
        {
            printf("How many do you want?\n");
            fgets(line, 30, stdin);
            strtok(line, "\n");
            num = atoi(line);
            print_out(numWanted, flavors);
        }
        else if(!strcmp(line, "2"))
        {
            printf("Enter a name:\n");
            fgets(line, 30, stdin);
            name_flavors(line[0], flavors, size_ptr);
        }
        else if(!strcmp(line, "3"))
        {
            printf("Bye!");
            cont = 0;
        }
    }    

}

void print_out(int *num, char* f[])
{
    int n;
    for(n = 0; n < *num; n++)
    {
        printf("%s\n", f[n]);
    }
} 

int name_flavors(char n, char* f[], int *s)
{
    int i;
    int counter=0;
    if(96 < n && n < 123)
    {
        n-=32;
    }

    for(i = 0; i < *s; i++)
    {
        if(n == f[i][0])
            {
                printf("Flavor Match! %s\n", f[i]);
                counter++;
            }    
    }
    return counter;
}
