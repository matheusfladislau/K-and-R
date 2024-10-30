#include <stdio.h>
#define MAXLINE 1000

/* get the length of the line */
int my_getline(char line[], int maxlen);

/* copy 'from' to 'to' */
void copy(char to[], char from[]);


int main() {
	int max;
	int len;
	char longest[MAXLINE];
	char line[MAXLINE];

	max = 0;
	while ((len = my_getline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) {
		printf("Longest line: %s", longest);
	}
	return 0;
}

int my_getline(char line[], int maxlen) {
	int c, i;
	i = 0;
	while ((c = getchar()) != EOF && i < maxlen-1 && c != '\n') {
		line[i] = c;
		++i;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
