//1001934192 Nebojsa Kilibarda
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_filename(int n, char **b);

int main(int argc, char **argv)
{
    char line[20];
    FILE *fp;
    int valueNum = find_filename(argc, argv);

  if (valueNum != -1)
  {
    printf("\nFilename: %s\n", argv[valueNum+1]);
    printf("We are dealing with %s info.\n", argv[valueNum+2]);
    printf("Contents of the file:\n\n");    
    fp = fopen(argv[valueNum+1], "r");

    while(fgets(line, 20, fp))
    {
      strtok(line, "\n");
            
      if(!strcmp(argv[valueNum+2], "string"))
      {
        printf("%s\n", line); 
      }
      else if(!strcmp(argv[valueNum+2], "numbers"))
      {
        printf("%d\n", atoi(line));
      }    
    }
  }    
  else
  {
    printf("Filename not found. Bye!\n");
    return 0;   
  }

}

int find_filename(int n, char **b) 
{ 
  int i; 
  int counter=0; /*equals -1 if didnt find*/ 
  int check=0; 
   
  for(i=0;i<n&&!check;i++) 
  { 
    if(!strcmp(*b, "filename")) 
    { 
      check=1; 
    } 
    counter++; 
    b++; 
  } 
  if(check!=1) 
  { 
    counter=0; 
  } 
  return (counter-1);  
} 