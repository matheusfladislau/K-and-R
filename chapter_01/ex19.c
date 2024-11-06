//1.19 Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.

//Sice the book says reverse(s), I assumed char s[] is the only parameter. Is this way, we need to get the size of the string and also reverse the same s[] string that is being passed. So I've made another char og[] to copy the contents of s[], and then reverse the s[] based on the content of og[]. This could be much simpler if the size of the string was being passed on the reverse(s) method, but since the book don't actually says that, I've opted for my approach explained above.

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
	

	int i = 0, copy = len;
	while (len >= 0) {
		if (og[len] != '\n' && og[len] != '\0') {
			s[i] = og[len];
			++i;
		}
		--len;
	}
	if (og[copy-1] == '\n') {
		s[i] == '\n';
		++i;
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
