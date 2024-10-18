//1-10 Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.

#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            c = 't';
        }
        if (c == '\b') {
            putchar('\\');
            c = 'b';
        }
        if (c == '\\') {
            putchar('\\');
            c = '\\';
        }
        putchar(c);
    }
    return 0;
}
