#include <stdio.h>

#define MAXWORDLEN 10 //We'll make it 10 to make it more simple

int main() {
    int c, i, words[MAXWORDLEN + 1], ndigit;
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

    for (i = 1; i <= MAXWORDLEN; ++i) {
        printf("%2d|", i);
            for (int j = 0; j < words[i]; ++j) {
                printf("\u25A0 ");
        }
        printf("\n");
    }
    printf("  ");

    for (i = 1; i <= MAXWORDLEN; ++i) {
        printf("--");
    }
    printf("\n  ");
    for (i = 1; i < MAXWORDLEN; ++i) {
        printf("%2d", i);
    }
    printf(" %d\n", MAXWORDLEN);
    
    return 0;
}
