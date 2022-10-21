#include <stdio.h>

struct puppy{
        char color[20];
        int age_months;
        char gender;
        char breed[20];
    };
    typedef struct puppy P;

typedef struct Candy{
    char name[20];
    int calories;
}cnd;     

int main () 
{
    struct puppy p1={"brown", 4, 'f', "boxer"};

    P p2={"white", 6, 'm', "unknown"};

    printf("%s\n", p1.color);
    printf("%c\n", p2.gender);
    printf("%d %d\n", p1.age_months, p2.age_months);
    printf("%s %s\n", p1.breed, p2.breed);

    cnd candy_array[2] = {{"Snickers", 340}, {"Mars", 320}};

    printf("%s %d\n", candy_array[0].name, candy_array[1].calories);
}