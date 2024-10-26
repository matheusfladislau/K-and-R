//1-14 Write a program to print a histogram of the frequencies of different characters in its input.

#include <stdio.h>

#define MAXWORDLEN 128 //We're gonna be using only 10 to make it simpler
		      
int main() {
    int c, i, j, words[MAXWORDLEN + 1], ndigit;
    ndigit = 0;
    
    for (i = 0; i <= MAXWORDLEN; ++i) {
        words[i] = 0;
    }

    while ((c = getchar()) != EOF) {
	    if (c != ' ' && c != '\n' && c != 't' && c <= MAXWORDLEN) {
		    ++words[c];
	    } 
    } 

    for (int i = 0; i <= MAXWORDLEN; i++) {
	    if (words[i] != 0) {
		    printf("%d - %c\n", words[i], i);
	    } 
    } 

    //Horizontal
    printf("\n");
    for (i = 1; i <= MAXWORDLEN; ++i) {
	    if (words[i] != 0) {
		    printf("%2c|", i);
		    for (j = 0; j < words[i]; ++j) {
			    printf("\u25A0  ");
		    }
		    printf("\n");
	    }
    }
    printf("C ");

    int maxnum = 0;
    for (i = 0; i <= MAXWORDLEN; ++i) {
	    if (words[i] > maxnum) {
		    maxnum = words[i];
	    }
    }

    for (i = 1; i <= maxnum; ++i) {
	    printf("---");
    }
    printf("\n N");
    for (i = 1; i <= maxnum; ++i) {
	    printf("%2d ", i);
    }
    printf("\n");


    //Vertical
    printf("\n");
    for (i = maxnum; i > 0; --i) {
	    printf("%2d|", i);
	    for (j = 1; j <= MAXWORDLEN; ++j) {
		    if (words[j] >= i) {
			    printf("\u25A0 ");
		    } else if (words[j] != 0) {
			    printf("  ");
		    }
	    }
	    printf("\n");
    }
    printf("N ");

    for (i = 1; i <= MAXWORDLEN; ++i) {
	    if (words[i] != 0) {
		    printf("--");
	    }
    }
    printf("\n C");
    for (i = 1; i <= MAXWORDLEN; ++i) {
	    if (words[i] != 0) {
		    printf("%2c", i);
	    }
    }
    printf("\n");
    return 0;
}
