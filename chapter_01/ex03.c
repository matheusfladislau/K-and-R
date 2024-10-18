//1-3 Modify the temperature cnversion program to print a heading above the table.

#include <stdio.h>

int main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	printf("CELSIUS\tFAHRENHEIT\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%7.0f %4.1f\n", celsius, fahr);
		fahr += step;
	}
	return 0;
}
