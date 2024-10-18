//1-4 Write a program to print the corresponding Celsius to Fahrenheit table.

#include <stdio.h>

int main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;

	printf("CELSIUS\tFAHRENHEIT\n");
	while (celsius <= upper) {
		fahr = (celsius * 1.8) + 32.0;
		printf("%7.0f %4.1f\n", celsius, fahr);
		celsius += step;
	}
	return 0;
}
