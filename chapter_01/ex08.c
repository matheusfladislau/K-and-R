//1-8 Write a program to count blanks, tabs and newlines.

#include <stdio.h>

int main() {
    int c, nl, nt, nb;
    nl = nt = nb = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++nb;
        }

        if (c == '\t') {
            ++nt;
        }
        
        if (c == '\n') {
            ++nl;
        }
    }

    printf("Número de newlines: %d, tabs: %d, espaços: %d\n", nl, nt, nb);
    return 0;
}
