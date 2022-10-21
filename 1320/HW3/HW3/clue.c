//1001934192 Nebojsa Kilibarda
#include <stdio.h>
#include <string.h>


int meet_with_suspect(char *susp[], int meet[], char *name);

int main (int argc, char **argv) 
{ 
  char* all_suspects[]={"Mustard", "Scarlet","Plum"}; 
  int meet[3]={0};  /*Number of times met for each suspect-each array index corresponds to the array index of the suspect name 
in all_suspects*/ 
  char name[100]; 
  int check=1; 
 
  while(check) 
  { 
    printf("\n***Enter a suspect's name: "); 
    fgets(name,100,stdin); 
    strtok(name,"\n"); 
 
    if(!strcmp(name,"exit")) 
    { 
       check=0; 
    } 
 
    else 
    {
        check=meet_with_suspect(all_suspects,meet,name); 
    } 
  } 
 
  printf("Total meets for Mustard: %d\n",meet[0]); 
  printf("Total meets for Scarlet: %d\n",meet[1]); 
  printf("Total meets for Plum: %d\n",meet[2]); 
} 

int meet_with_suspect(char *susp[], int meet[], char *name)
{
    int i;
    char answer[5];
    int found = 0;
    
    for(i=0; i < 3; i++)
    {
        if(!strcmp(susp[i], name))
        {
            printf("Suspect found. Adding meeting.\n");
            meet[i]++;
            found++;
        }
    }
    
    if(!found)
    {
        printf("Suspect not found.\n");
    }

    printf("--Would you like to continue meeting?\n");
    fgets(answer, 5, stdin);
    strtok(answer, "\n");
    
    if(!strcmp(answer, "yes"))
    {
        return 1;
    }
    else if(!strcmp(answer, "no"))
    {
        return 0;
    }
    else
    {
        printf("Invalid entry.\n");
        return 1;
    }
}
