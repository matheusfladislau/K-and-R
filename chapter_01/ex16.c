//1.16 Revise the main routine of the longest-line program so that it will correctly print the length of arbitrarily long input lines and as much as possible of the text.

//Phew! that was a tough one to understand. Basically it wants me to print the length of the text even if the char length is above the MAXLINE limit. 'As much as possible of the text' means that the text length MUST follow the MAXLINE constant.

//Since it says 'main routine' ig it's the main() function?

#include <stdio.h>
#define MAXLINE 10

int my_getline(char line[], int maxlen);
void copy(char to[], char from[]);

int main() {
	int max;
	int len;
	char longest[MAXLINE];
	char line[MAXLINE];

	max = 0;
	while ((len = my_getline(line, MAXLINE)) > 0) {
		if (line[len-1] != '\n') {
			int c;
			while ((c = getchar()) != EOF && c != '\n') {
				++len;
			}
		}
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) {
		printf("\nLongest line: %s", longest);
		printf("\nLength: %d", max);
		printf("\n");
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

void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
