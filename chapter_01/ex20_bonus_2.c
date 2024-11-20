//1-20 Write a program detab that that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?

//This is a much much better implementation from this exercise. I'll use it to make ex21 and I've done in response to ex20_bonus.c using the my_getline() function, as well as storing inputs inside an array.
//This one just prints the output, there's no storing. It's much simpler and it works as well.

#include <stdio.h>
#define TABSTOP 8

int main() {
    int c, position;
    position = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int amount_space = TABSTOP - (position % TABSTOP);
            int total = position + amount_space;

            while (position < total) {
                putchar(' ');
                ++position;
            }
        } else  {
            if (c == '\n') {
                position = 0;
            } else {
                ++position;
            }
            putchar(c);
        }
    }
	return 0;
}
