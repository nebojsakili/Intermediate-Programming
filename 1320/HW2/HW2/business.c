// 1001934192 Nebojsa Kilibarda

#include <stdio.h>

float print_out(float* salary, int* num_of_emps);
int rebudget(float* d, float *budget);

int main(int argc, char ** argv) 
{ 
 
  int i=1; 
  float budget, total, salary; 
  float *money_ptr=&salary; 
  float *total_ptr=&total; 
  int employees; 
 
  printf("Enter monthly budget: $"); 
  scanf("%f", &budget); 
   
  while(i) 
  { 
    printf("Enter monthly worker salary: $"); 
    scanf("%f", &salary); 
     
    printf("Enter total workers:"); 
    scanf("%d", &employees); 
 
    total=print_out(money_ptr, &employees); 
    i=rebudget(total_ptr, &budget); 
  } 
 
}


float print_out(float* salary, int* num_of_emps)
{
  int employees = *num_of_emps; //temporary variable for the number of employees
  int managers = employees/2;  //For every 2 employees, a manager, unless odd number, thus int division works
  int directors = managers/3;  //every 3 managers must have a director above them, so managers/3 suffices (minimum employees is 6 which ensures at least one director)
  float total_salaries = *salary;

  printf("**Employee info:**\n");
  printf("Total workers:%d  Monthly salary: $%.2f\n", employees, *salary);
  printf("Total managers:%d  Monthly salary: $%.2f\n", managers, total_salaries*2.5);
  printf("Total directors:%d  Monthly salary: $%.2f\n", directors, total_salaries*5);

  total_salaries = (employees*total_salaries)+(managers*total_salaries*2.5)+(directors*total_salaries*5);
  printf("Total spent: $%.2f\n", total_salaries);

  return total_salaries;
}

int rebudget(float* d, float *budget)
{
  int n = 0;
  if(*budget > *d)
  {
    printf("This goes UNDER your budget by $%.2f\n\n", (*budget - *d));
  }
  else
  {
    printf("This goes OVER your budget by $%.2f\n\n", (*d - *budget));
  }
  printf("Would you like to rebudget? 1 for yes, 2 for no: ");
  scanf("%d", &n);
  if(n==2)
  {
    printf("Bye!");
    return 0;
  }
  else if(n==1)
  {
    return n;
  }
}
