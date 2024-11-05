//1.19 Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
int my_getline(char line[], int maxlen);
void copy(char from[], char to[]);

int main() {
	int len;
	char line[MAXLINE];

	while ((len = my_getline(line, MAXLINE)) >= 0) {
		if (len >= 1) {
			reverse(line);
			printf("%s", line);
		}
	}
	return 0;
}

void reverse(char s[]) {
	int len = 0;
	while (s[len] != '\0') {
		++len;
	}

	char og[len+1];
	copy(s, og);
	

	int i = 0;
	while (len >= 0) {
		if (og[len] != '\n' && og[len] != '\0') {
			s[i] = og[len];
			++i;
		}
		--len;
	}
	s[i] = '\0';
}

int my_getline(char line[], int maxlen) {
	int c, i;
	i = 0;

	while (i < maxlen-1 && (c = getchar()) != EOF && c != '\n') {
		if (i > 0 || (c != '\t' && c != ' ')) {
			line[i] = c;
			++i;
		}
	}

	while (i > 0 && (line[i-1] == '\t' || line[i-1] == ' ')) {
		--i;
	}

	if (i > 0 && c == '\n') {
		line[i] = '\n';
		++i;
	}

	line[i] = '\0';
	return i;
}

void copy(char from[], char to[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
