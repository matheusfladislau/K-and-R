//1-13 Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

#include <stdio.h>

#define MAXWORDLEN 10 //We're gonna be using only 10 to make it simpler
		      
int main() {
    int c, i, j, words[MAXWORDLEN + 1], ndigit;
    ndigit = 0;
    
    for (i = 0; i <= MAXWORDLEN; ++i) {
        words[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            ndigit++;
        } else {
            if (ndigit > 0 && ndigit <= MAXWORDLEN) {
                ++words[ndigit];
            }
            ndigit = 0;
        }
    }
    if (ndigit > 0 && ndigit <= MAXWORDLEN) {
        ++words[ndigit];
    }
    

    //Horizontal
    printf("\n");
    for (i = 1; i <= MAXWORDLEN; ++i) {
        printf("%2d|", i);
            for (j = 0; j < words[i]; ++j) {
                printf("\u25A0 ");
        }
        printf("\n");
    }
    printf("N ");

    for (i = 1; i <= MAXWORDLEN; ++i) {
        printf("--");
    }
    printf("\n W");
    for (i = 1; i < MAXWORDLEN; ++i) {
        printf("%2d", i);
    }
    printf(" %d\n", MAXWORDLEN);


    //Vertical
    printf("\n");
    for (i = MAXWORDLEN; i > 0; --i) {
        printf("%2d|", i);
	for (j = 1; j <= MAXWORDLEN; ++j) {
	    if (words[j] >= i) {
   	       printf("\u25A0 ");
	    } else {
   	       printf("  ");
	    }
	}
	printf("\n");
    }
    printf("W ");

    for (i = 1; i <= MAXWORDLEN; ++i) {
        printf("--");
    }
    printf("\n N");
    for (i = 1; i < MAXWORDLEN; ++i) {
        printf("%2d", i);
    }
    printf(" %d\n", MAXWORDLEN);
    return 0;
}
