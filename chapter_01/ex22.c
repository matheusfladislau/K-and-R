//1-22 Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. 
#include <stdio.h>

#define COLUMN 8

int main() {
    int c, i = 0;
    int blank_space;
    int arr[COLUMN];

    while ((c = getchar()) != EOF) {
        if (i == COLUMN) {
            i = 0;
            for (int y = 0; y < COLUMN; ++y) {
                if (y == blank_space) {
                    putchar('\n');
                } else {
                    printf("%c", arr[y]);
                }
            }
        } else {
            if (c == ' ' || c == '\t') {
                blank_space = i;
            }
        }
        arr[i] = c;
        ++i;
    }
    return 0;
}
