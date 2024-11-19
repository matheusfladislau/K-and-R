//1-20 Write a program detab that that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?

//This is a much better implementation from this exercise, and I've done in response to ex20.c using the copy() function. This one already changes the TAB with spaces while the user is typing the line - there's no copying or whatsoever.
#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 8

int detab_line(char line[], int maxlen);

int main() {
	int len;
	char line[MAXLINE];

	while ((len = detab_line(line, MAXLINE)) >= 0) {
		if (len >= 1) {
			printf("%s", line);
		}
	}
	return 0;
}

int detab_line(char line[], int maxlen) {
	int c, i;
	i = 0;

	while (i < maxlen-1 && (c = getchar()) != EOF && c != '\n') {
        if (c == '\t') {
            int amount_space = TABSTOP - (i % TABSTOP);
            int total = i + amount_space;

            while (i < total) {
                line[i] = ' ';
                ++i;
            }
        } else {
            line[i] = c;
            ++i;
        }
	}

	if (i > 0 && c == '\n') {
		line[i] = '\n';
		++i;
	}

	line[i] = '\0';
	return i;
}
