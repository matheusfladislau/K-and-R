//1-20 Write a program detab that that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?

//This one's been a real pain, but I get it now.
//First, It is important do understand how tab and tabstops work at all. Tabstops are fixed column numbers that appears in a text. When pressing TAB, there's no FIXED JUMP (ex: always jump 8 chars), instead, the TAB jumps to the NEXT TABSTOP. (ex: if TABSTOP is 8, and TAB is done at 4, there's only 4 jumps.)

// . . . . . . . 8 . . . . . . . . 8
//       t - - - |
//           4

//Thinking about that, the code is really easy. You should just make a mod TABSTOP in a current char position (to make it stay between 0-8) and subtract to the total amount of TABSTOP (refering to the next jump).
//Next step was to make two char arrays, one would be the original and the other without the TABs. I've used two counters to put one char into the other, considering that the spaces would occupy much more fields into the array than a simple \t.


#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 8

int my_getline(char line[], int maxlen);
void detab(char line[], char dtb[]);

int main() {
	int len;
	char line[MAXLINE];

	while ((len = my_getline(line, MAXLINE)) >= 0) {
		if (len >= 1) {
			char dtb[MAXLINE];
			detab(line, dtb);
			printf("%s", dtb);
		}
	}
	return 0;
}

int my_getline(char line[], int maxlen) {
	int c, i;
	i = 0;

	while (i < maxlen-1 && (c = getchar()) != EOF && c != '\n') {
		line[i] = c;
		++i;
	}

	if (i > 0 && c == '\n') {
		line[i] = '\n';
		++i;
	}

	line[i] = '\0';
	return i;
}

void detab(char line[], char dtb[]) {
	int i, y;
	i = y = 0;

	while (line[i] != '\0') {
		if (line[i] == '\t') {
			int amount_space = TABSTOP - (y % TABSTOP);
			int total = y + amount_space;

			while (y < total) {
				dtb[y] = ' ';
				++y;
			}
		} else {
			dtb[y] = line[i];
			++y;
		} 
		++i;
	}
	dtb[y] = '\0';
}
