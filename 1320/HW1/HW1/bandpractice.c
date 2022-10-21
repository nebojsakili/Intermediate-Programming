//1001934192 Nebojsa Kilibarda
#include <stdio.h>
#include <string.h>
#define SIZE 7

int read_doctor_list(char *filename, char *mode, char band_names[][20], char band_diagnose[]);
void band_practice_list(char *filename, char *diagnosis, char band_names[][20], char band_diagnose[]);

int main (int argc, char** argv) 
{ 
 
  char band_names[SIZE][20]; 
  char band_diagnose[SIZE]; 
 
  int n=read_doctor_list("doctorlist.txt","r",band_names,band_diagnose); /*input file, mode to read file, names of band members, diagnosis as letters (for example, Positive should be saved as just ‘P’)*/ 

  if(n) 
  { 
    band_practice_list("output_p.txt","Positive",band_names,band_diagnose); /*output file, which diagnosis to list (Positive in this case), names of band members, diagnosis as letters (for example, Positive should be saved as just ‘P’)*/ 
  
    band_practice_list("output_n.txt","Negative",band_names,band_diagnose); 
  } 
} 

int read_doctor_list(char *filename, char *mode, char band_names[][20], char band_diagnose[])
{
    int ct=0; //counter variable to fill the arrays
    char line[10]; //temp string variable to use with fgets
    FILE *fp = fopen(filename, mode); //filename and mode passed as string literals
    if(!fp)
    {
        printf("File could not open properly.\n");
        return 0;
    }
    while(fgets(line, 10, fp)) //read as long as fgets can retrieve a line
    {
    strtok(line,"\n");
    strcpy(band_names[ct],line);
    
    fgets(line,10,fp);
    strtok(line,"\n");
    if(!strcmp(line, "Positive"))
    {
      band_diagnose[ct]='P';
    }
    else if(!strcmp(line, "Negative"))
    {
      band_diagnose[ct]='N';
    }
    ct++; //increment counter
    }
    fclose(fp);
    return 1; //returns 1 if the file was opened succesfully and after the while loop
}

void band_practice_list(char *filename, char *diagnosis, char band_names[][20], char band_diagnose[]) //passing two string literals and two arrays
{
  printf("Creating list..\n\n");

for(int i=0;i<SIZE;i++) //Loop to print to the screen each band member and their diagnosis
 {
  printf("%s: %c", band_names[i],band_diagnose[i]);
  if(band_diagnose[i]=='P')
  {
    printf("... Can't go to practice!:(\n");
  }
  else
  {
    printf("... Good to go to practice! :)\n");
  }
 }

  FILE *fOut = fopen(filename, "w"); //Writing to a file

  fprintf(fOut, "---List of %s cases:---\n\n", diagnosis);

  for(int i=0; i < SIZE; i++) //For loop to separate the negative from positive cases using the band_diagnose array
  {
  if (!strcmp(diagnosis, "Positive") && (band_diagnose[i]=='P'))
  { 
    fprintf(fOut, "--%s: +Positive+\n", band_names[i]);
  }
  else if (!strcmp(diagnosis, "Negative") && (band_diagnose[i]=='N'))
  { 
    fprintf(fOut, "--%s: -Neg-\n", band_names[i]);
  }
}
}