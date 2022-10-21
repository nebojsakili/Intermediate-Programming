#include <stdio.h>

int main(int argc, char **argv)
{
    char *french_words[] = {"amour","soleil","oiseau","coeur"};
    char **ptr_fr = french_words;

    int i;

    for(i=0; i < 4; i++)
    {
        printf("Word: %s  Address: %p\n", *ptr_fr, ptr_fr);
        ptr_fr++;
    }
}