#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, cw, cnl, ct, estado;
    cw = cnl = ct = 0;

    estado = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            cnl++;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            estado = OUT;
            putchar('\n');
        } else {
            putchar(c);
            if (estado == OUT) {
                estado = IN;
                cw++;
            }
        }
    }
    return 0;
}
