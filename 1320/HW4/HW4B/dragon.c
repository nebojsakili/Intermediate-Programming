#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dragon{
    char *name;
    char color[3];
    int heads;
    int tails;
}dragon;

void dragon_info(dragon *d);
void color(char *color, dragon *d);

int main(int argc, char** argv)
{
    dragon total[4];
    dragon_info(total);
    char c='b';
    // color(&c, total);
}

void dragon_info(dragon *d)
{
    char line[100];
    char *token;

    fgets(line, 100, stdin);
    token = strtok(line, ",");
    strcpy(d->name,token);

    for(int i = 0; i < 3; i++)
    {
        token = strtok(NULL, ",");
        d->color[i] = token[0];
    }

    token = strtok(NULL, ",");
    d->heads = atoi(token);
    token = strtok(NULL, ",");
    d->tails = atoi(token);
}