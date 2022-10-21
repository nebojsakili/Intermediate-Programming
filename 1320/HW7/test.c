#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char* name;
    int *age;
    struct node* left;
    struct node* right;
}BNODE;

BNODE* addNode(char *line)
{
    BNODE* temp = malloc(sizeof(BNODE));

    temp->name = malloc(20);
    char* token = strtok(line, ",");
    strcpy(temp->name, token);

    token = strtok(NULL, "\n");
    temp->age = malloc(sizeof(int));
    *temp->age = atoi(token);

    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void insert(BNODE* root, char* line)
{
    char* temp = malloc(50);
    strcpy(temp, line);
    char* token = strtok(temp, ",");
    token = strtok(NULL, "\n");
    int age;
    age = atoi(token);
    if(age <= *root->age)
    {
        if(!root->left)
        {
            root->left = addNode(line);
        }
        else
        {
            insert(root->left, line);
        }
    }
    else
    {
        if(!root->right)
        {
            root->right = addNode(line);
        }
        else
        {
            insert(root->right, line);
        }
    }

}

void inorder(BNODE* root)
{
    if(!root)
    {
        return;
    }
    inorder(root->left);
    printf("age of %s is %d\n", root->name, *root->age);
    inorder(root->right);
}

void preorder(BNODE* root)
{
    if(!root)
    {
        return;
    }
    printf("age of %s is %d\n", root->name, *root->age);
    preorder(root->left);
    preorder(root->right);
}

void postorder(BNODE* root)
{
    if(!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("age of %s is %d\n", root->name, *root->age);
}

int main(int argc, char** argv)
{
    char* line = malloc(50);
    char* token;
    FILE* fp = fopen(argv[1], "r");
    BNODE* root = NULL;

    while(fgets(line, 50, fp))
    {
        if(!root)
        {
            root=addNode(line);
        }
        else
        {
            insert(root, line);
        }
    }
    inorder(root);
    printf("\n\n");
    postorder(root);
    printf("\n\n");
    preorder(root);
    printf("\n\n");

}