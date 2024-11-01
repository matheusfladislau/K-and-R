//1.17 Write a program to print all input lines that are longer than 80 characters.

#include <stdio.h>
#define MAXLINE 1000
#define MAXINPUTLINE 80

int my_getline(char line[], int maxlen);

int main() {
	int len;
	char line[MAXLINE];

	while ((len = my_getline(line, MAXLINE)) > 0) {
		if (len > MAXINPUTLINE) {
			printf("\nLine: %s", line);
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
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
