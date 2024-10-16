#include <stdio.h>

int main() {
    int c, emespaco;
    emespaco = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            emespaco = 1;
        } else {
            if (emespaco == 1) {
                putchar(' ');
                emespaco = 0;
            }
            putchar(c);
        }
    }
    return 0;
}
