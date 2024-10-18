//1-9 Write a program to copy its input to output, replacing each string of one or more blanks by a single blank.

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    int c, emespaco;
    emespaco = FALSE;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            emespaco = TRUE;
        } else {
            if (emespaco == TRUE) {
                putchar(' ');
                emespaco = FALSE;
            }
            putchar(c);
        }
    }
    return 0;
}
