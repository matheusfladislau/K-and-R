//1-20 Write a program detab that that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?

//This one's been a real pain, but I get it now.
//First, It is important do understand how tab and tabstops work at all. Tabstops are fixed column numbers that appears in a text. When pressing TAB, there's no FIXED JUMP (ex: always jump 8 chars), instead, the TAB jumps to the NEXT TABSTOP. (ex: if TABSTOP is 8, and TAB is done at 4, there's only 4 jumps.)

// . . . . . . . 8 . . . . . . . . 8
//       t - - - |
//           4

//Thinking about that, the code is really easy. You should just make a mod TABSTOP in a current char position (to make it stay between 0-8) and subtract to the total amount of TABSTOP (refering to the next jump).

#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 8

int my_getline(char line[], int maxlen);
void detab(char line[]);
void copy(char from[], char to[]);

int main() {
	int len;
	char line[MAXLINE];

	while ((len = my_getline(line, MAXLINE)) >= 0) {
		if (len >= 1) {
      detab(line);
			printf("%s", line);
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

void detab(char line[]) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == '\t') {
      int amount_space = TABSTOP - (i % TABSTOP);
      printf("espaço para próximo tab: %d\n", amount_space);
      int total = i + amount_space;
      printf("total de caracteres = %d\n", total);

      for (int y = i; y < total; ++y) {
        line[y] = 'y';
      }
    }
    ++i;
  }
}

void copy(char from[], char to[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
