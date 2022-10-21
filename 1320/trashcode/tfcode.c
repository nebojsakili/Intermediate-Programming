#include <stdio.h> 
#include <string.h> 
 
int run_through(int num, char **a) 
{ 
  int i; 
  int check=0;  
   
  for(i=0;i<num;i++) 
  { 
    printf("%s\n", *(a+i));   
     
    if(!strcmp(*(a+i), "filename")) 
    { 
      check=1; 
    } 
  } 
  return check; 
} 
 
char** find_filename(int n, char **b) 
{ 
  int i; 
  int check=0;  
   
  for(i=0;i<n;i++) 
  { 
    if(!strcmp(*b, "filename")) 
    { 
      b++; 
      break; 
    } 
    b++; 
  } 
  return b; 
   
} 
 
int main(int argc, char **argv) 
{ 
  int choice; 
  char **hold; 
   
  if(!(argc<6)) 
  { 
    printf("Not happening.\n");
    printf("%d", choice); 
  } 
   
  else 
  { 
    choice=run_through(argc, argv); 
     
    if(choice==0) 
    { 
      printf("Here.\n"); 
    } 
     
    else 
    { 
      hold=find_filename(argc, argv); 
      printf("The filename is %s!\n", *hold); 
       
    } 
  } 
}