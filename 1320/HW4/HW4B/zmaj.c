#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DRAGON
{
	char name[100]; // to hold the name
	char colors[3]; // to hold the colors
	int heads;
	int tails;
}dragon;

void dragon_info(dragon *d);
void color(char *color, dragon *d);

int main(int argc, char **argv)
{
	dragon total[4];
	dragon_info(total);
	char c = 'b';
	color(&c, total);

	return 0;
}

void dragon_info(dragon *d)
{
	char input;
	int i = 0;
	while ((input = getchar()) != EOF) // until the end of file is reached
	{
		int j = 0;
		while (input != ',') // to read the name of the dragon, until ',' is found
		{
			d[i].name[j] = input;
			j++; // carry on with the next
			input = getchar(); // put the returned char into input value
		}

		d[i].name[j] = '\0';
		d[i].colors[0] = getchar(); // first char = first color
		input = getchar(); // to ignore the next ','
		d[i].colors[1] = getchar(); // to get the next color
		input = getchar(); // to ignore the next ','
		d[i].colors[2] = getchar(); // to get the next color
		input = getchar(); // to ignore the next ','
		scanf("%d", &(d->heads)); // reading the input as type cast int -> # of heads 
		input = getchar(); // to ignore the next ','
		scanf("%d", &(d->tails)); // reading the input as type cast int -> # of tails 
		input = getchar(); // to ignore the next ','
		
		i++; // to move on to the next dragon
	}
	return;
}

char *colorName(char *color)
{
    if(*color == 'r') return "red"; 
    else if(*color == 'g') return "green"; 
    else if(*color == 'b') return "blue"; 
    else if(*color == 'w') return "white"; 
    else if(*color == 'y') return "yellow"; 

	return NULL;
}

void color(char *color, dragon *d)
{
    // format output
	printf("***All the %s dragons:***\n", colorName(color));

	for (int i = 0; i < 4; i++)
	{
		// if the color of the dragon is the same as the one from the input file --> print the name of that dragon
		if ((d[i].colors[0] == *color) || (d[i].colors[1] == *color) || (d[i].colors[2] == *color))
		{
			printf("%s is %s.\n", d[i].name, colorName(color)); // print the name of the dragon and its color
		}
	}
	return;
}