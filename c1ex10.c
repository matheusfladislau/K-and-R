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
