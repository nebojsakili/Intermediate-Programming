#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{ 
   char *singer_name; 
    int *albums_sold; 
    int number_tour_cities; 
    char** tour_cities_name; 
    struct node *left; 
    struct node *right; 
 
}Node;



Node* read_file(char* filename)
{
    Node *root = NULL;
    Node *temp = NULL;
    int i;
    FILE *fp;
    fp = fopen(filename, "r");
    char *token;
    char *line = malloc(50);
    char delimit[] = ",\n";
    int *value;
    while(fgets(line, 50, fp))
    {
        temp = malloc(sizeof(Node));
        temp->singer_name = malloc(20);
        token = strtok(line, delimit);
        strcpy(temp->singer_name, token);
        printf("%s\t",temp->singer_name);

        token = strtok(NULL, delimit);
        temp->albums_sold = malloc(sizeof(int));
        *temp->albums_sold = atoi(token);
        printf("%d\t",*temp->albums_sold);

        token = strtok(NULL, delimit);
        temp->number_tour_cities = atoi(token);
        printf("%d\t", temp->number_tour_cities);


        // temp->tour_cities_name = malloc(temp->number_tour_cities * sizeof(char*));
        temp->tour_cities_name = malloc(sizeof(char*) * temp->number_tour_cities);
        for(i=0;i<temp->number_tour_cities;i++)
        {
            temp->tour_cities_name[i] = malloc(20);
            token = strtok(NULL, delimit);
            strcpy(temp->tour_cities_name[i],token);
            printf("%s\t",temp->tour_cities_name[i]);
        }
        //*temp->tour_cities_name = malloc(10);


        printf("\n");
        // if(!root)
        // {
        //     root = temp;
        // }
        // else if(!root->left && (*root->left->albums_sold < *temp->albums_sold))
        // {
        //     root->left = temp;
        // }
        // else if(!root->right && (*root->right->albums_sold > *temp->albums_sold))
        // {
        //     root->right = temp;
        // }
    }
}

/*
You will be creating a binary tree (same style as in class-the first value will be the root) and traversing 
it.  
1. Create a function that can read the following sample file (given as a parameter) into a binary tree 
BASED ON the number of albums sold (this means the way the nodes-node structure given below-are 
added in the tree depends on the numerical value of the number of albums sold).  The function 
should return the address of the root of the tree. 
*/



int main()
{
    read_file("file.txt");
}