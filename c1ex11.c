#include <stdio.h>

#define IN 1
#define OUT 0

//se não tiver nenhum espaço entre as palavras, mesmo com o uso de , ou . dá erro - ( [ { , . ! sinais etc contam como palavras se estiverem entre espaços

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
        } else if (estado == OUT) {
            estado = IN;
            cw++;
        }
    }

    printf("Número de newline: %d, Número de palavras: %d", cnl, cw);
    return 0;
}
