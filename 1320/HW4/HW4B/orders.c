#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order{ //to hold the information from the file
    char *name; //to hold the name
    char payment_type; //to hold the payment type
    int total_orders; //to hold the total number of orders
    float amount_spent; //to hold the total amount spent by the customer
    int *fullfilled; //to indicate whether or not the order has been fulfilled
}order;

void menu(); //call to print options menu
void input_orders(order *o, int size, char*filename); //call to read file into structs
void print_out(int status, order*o, int size); //call to print out all orders
int pick_next(order *o, int size_order); //call to pick the next highest priced order
void output_file(char *filename, order *o, int size_order); //outputs the current info to customer.txt
void free_order(order *o, int size);

int main(int argc, char** argv)
{
    int run = 1, next = 0;
    int num = atoi(argv[1]);
    int choice = 0;
    char *answer = malloc(20);
    char *ans = malloc(5);
    //to allocate memory based on the # of orders provided
    order *o = malloc(sizeof(order)*num);

    //checking if memory was successfully allocated
    if(o==NULL) 
    {
        printf("Memory not allocated, exiting...\n");
    }

    printf("***Buongiorno chef Bartolomeo!***\n");
    input_orders(o, num, argv[2]); //calls input_orders function which copies contents of file into struct array
    while(run)
    {
        menu(); //prints the options menu
        scanf("%d", &choice);
        if(choice == 1)
        {
            printf("Do you want to see all orders to fill or orders already completed? Type fill or completed\n");
            scanf("%s", answer);
            if(!strcmp(answer, "fill"))
            {
                print_out(2, o, num);
            }
            else if(!strcmp(answer, "completed"))
            {
                print_out(1, o, num);
            }
        }
        else if(choice == 2)
        {
            next = pick_next(o, num);
            printf("Next order to fill: %s\n", o[next].name);
            printf("Go ahead and fulfill this order? y or n\n");
            scanf("%s", ans);
            if(ans[0] == 'y')
            {
                printf("Fulfilled!\n");
                *(o[next].fullfilled) = 1;
            }
            else if(ans[0] == 'n')
            {
                printf("Not fulfilled.\n");
            }
        }
        else if(choice == 3)
        {
            printf("Saving information...Ciao!\n");
            output_file(argv[2], o, num);
            run = 0;
        }
        
    }
    free(answer);
    free(ans);
    free_order(o, num); //freeing memory inside the structs
    free(o); //freeing the dynamically allocated structs themselves
}


//to read file info into structs
void input_orders(order *o, int size, char *filename)
{
    FILE *fp = fopen(filename, "r");
    int i;
    char *line = malloc(40); //dynamically allocating memory to read line of file
    char *token;

    for (i = 0; i < size; i++)
    {
        fgets(line, 40, fp);
        token = strtok(line, ",");
        o[i].name = malloc(20);
        strcpy(o[i].name, token);

        token = strtok(NULL, ",");
        o[i].payment_type = token[0];

        token = strtok(NULL, ",");
        o[i].total_orders = atoi(token);

        token = strtok(NULL, ",");
        o[i].amount_spent = atof(token);

        token = strtok(NULL, "\n");
        o[i].fullfilled = malloc(sizeof(int));
        *(o[i].fullfilled) = atoi(token);
    }
    free(line); //freeing memory
    fclose(fp); //closing the file
}

//to print the name of the customer based on their fulfillment status
void print_out(int status, order*o, int size)
{
    int i;
    if(status == 1) //status is passed based on users choice
    {
        printf("Already filled:\n");
    }
    else if(status == 2) //status is passed based on users choice
    {
        printf("Need to fill:\n");
    }
    for(i = 0; i < size; i++)
    {
        if(*(o[i].fullfilled) == status)
        printf("%s\n", o[i].name);
    }
}

//call to pick the next order based on the highest price
int pick_next(order *o, int size_order)
{
    int index = 0, i;
    char *ans;
    float current = 0, hold = o[0].amount_spent;
    for(i = 0; i < size_order; i++)
    {
        current = o[i].amount_spent;
        if(current>hold && *(o[i].fullfilled) == 2)
        {
            hold = o[i].amount_spent;
            index = i;
        }
    }
    return index;
}

//call to output current status of all the orders to customer.txt
void output_file(char *filename, order *o, int size_order)
{
    int i;
    FILE *fp = fopen(filename, "w+");
    for(i = 0; i < size_order; i++)
    {
        fprintf(fp, "%s,%c,%d,%2.f,%d\n", o[i].name, o[i].payment_type, o[i].total_orders, o[i].amount_spent, *(o[i].fullfilled));
    }
    fclose(fp);
}

//prints the initial menu for chef Bartolomeo
void menu()
{
    printf("\nWhat to do?\n");
    printf("1.print out orders\n");
    printf("2.pick next order to fulfill\n");
    printf("3.exit\n");
}

//to free all the dynamically allocated memory within the structs
void free_order(order *o, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        free(o[i].name);
        free(o[i].fullfilled);
    }
    return;
}