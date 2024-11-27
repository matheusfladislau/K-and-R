//1-21 Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

#include <stdio.h>
#define TABSTOP 8

#define OUT 0
#define IN 1

void entab(int initialpos, int position);

int main() {
    int c, position, state, initialpos;
    position = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && state == OUT) {
            state = IN;
            initialpos = position;
            ++position;
        } else {
            if (state == IN && c != ' ') {
                entab(initialpos, position);
                state = OUT;
            }

            if (c == '\n') {
                position = 0;
            } else {
                ++position;
            }


            if (c != ' ') {
                putchar(c);
            }
        }
    }
	return 0;
}

void entab(int initialpos, int position) {
    int amount_space_tabstop = TABSTOP - (initialpos % TABSTOP);
    int amount_space = position - initialpos;

    while (amount_space >= amount_space_tabstop) {
        putchar('\t');
        amount_space -= amount_space_tabstop;
        amount_space_tabstop = TABSTOP;
    }
    while (amount_space > 0) {
        putchar(' ');
        --amount_space;
    }
}
