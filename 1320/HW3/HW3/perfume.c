//1001934192 Nebojsa Kilibarda
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_spray_perfume(char *ans, char *perfumes[], int *size);
void perfume_spray(int index, char **perf, int perf_bottles[], int size);
void exit_list(char **perf, int perf_bottles[], int size, char *filename);


int main(int argc, char **argv)
{ 
  char answer[40]; 
  char* perfume_names[]={"Gucci Flora", "Chanel Chance", "Dior J'adore"}; 
  char** perf_ptr=perfume_names; 
 
 
  int perfume_bottles_oz[]={32,1,24};  //amount per bottle (e.g. Gucci Flora has 32 oz etc)  
  int num_times_run_loop=atoi(argv[1]); 
  int size=3, index; 
 
  for(int i=0;i<num_times_run_loop;i++) 
  { 
    printf("Which perfume to use? "); 
    fgets(answer, 40, stdin); 
    strtok(answer,"\n"); 
  
    index=find_spray_perfume(answer,perfume_names,&size); 
  
    if(index==-1) 
    { 
      printf("No perfume found with this name...\n"); 
    } 
  
    else 
    { 
      perfume_spray(index, perf_ptr, perfume_bottles_oz, *(&size)); 
    } 
  } 
 printf("Exiting..."); 
 exit_list(&*&*perf_ptr, perfume_bottles_oz, size, argv[2]); 
 
}

/*This function should go through all the perfumes and determine if the perfume entered by the user exists.  If the 
perfume we are checking for does exist, the index in the array where it was found should be returned...if not, -1 
should be returned.*/ 
int find_spray_perfume(char *ans, char *perfumes[], int *size)
{
    for(int i = 0; i < *size; i++)
    {
    if(!strcasecmp(ans, perfumes[i]))
    return i;
    }
    
    return -1;
} 
 
 
/*This function should allow a user to “spray” perfume (meaning reduce the amount of oz by 2).  If there is not 
enough perfume to spray, it should be indicated to the user.*/ 
void perfume_spray(int index, char **perf, int perf_bottles[], int size)
{
    printf("Total oz in this bottle of %s: %d\n", perf[index], perf_bottles[index]);
    if(perf_bottles[index] >= 2)
    {
        perf_bottles[index] -= 2;
        printf("**SPRAY! Now we have %d oz**\n", perf_bottles[index]);
    }
    else
    {
        printf("Not enough to spray 2oz.. you should go buy more.\n");
    }
} 
 
  
/*This function should output an output file in the same format given below.*/ 
void exit_list(char **perf, int perf_bottles[], int size, char *filename)
{
    FILE *fOut = fopen(filename, "w");
    fprintf(fOut, "~~Total Perfumes: %d~~\n\n", size);
    for(int i = 0; i < size; i++)
    {
        fprintf(fOut, "%s %d\n", perf[i], perf_bottles[i]);
    }
}