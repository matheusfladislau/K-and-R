//1-14 Write a program to print a histogram of the frequencies of different characters in its input.

//We'll be counting the percentage of: Letters (L), Numbers (N) and Others (O), that is: \n, \t, and spaces, relative to the total amount of words 
#include <stdio.h>

#define MAXTYPES 3 // It needs to be three, just putting here to let it have more sense

int main() {
    int c, i, j, nletter, nnumber, nother;
    float percent[MAXTYPES];
    
    nletter = nnumber = nother = 0;
    
    for (i = 0; i < MAXTYPES; ++i) {
        percent[i] = 0;
    }

    while ((c = getchar()) != EOF) {
	if (c >= '0' && c <= '9') {
	    ++nnumber;
	} else if (c == ' ' || c == '\n' || c == '\t') {
	    ++nother;
	} else {
	    ++nletter;
	}
    }
    float totalnum = nnumber + nother + nletter;

    percent[0] = (nletter / totalnum) * 100;
    percent[1] = (nnumber / totalnum) * 100;
    percent[2] = (nother  / totalnum) * 100;
    
    printf("\n");
    printf("TOTAL: %0.0f \n", totalnum);
    printf("LETTERS: %0.2f%% \n", percent[0]);
    printf("NUMBERS: %0.2f%% \n", percent[1]);
    printf("OTHERS: %0.2f%% \n", percent[2]);

    //Horizontal (print with percentages)
    printf("\n");
    for (i = 0; i < 3; ++i) {
       if (i == 0) {
          printf(" L|");
       } else if (i == 1) {
          printf(" N|");
       } else {
          printf(" O|");
       }

       for (j = percent[i]; j >= 10; j-=10) {
         printf("\u25A0  ");
       }
       //round it up
       // if (j > 5) {
       //   printf("\u25A0  ");
       // }
       printf("\n");
    }
    printf("N ");
    for (i = 10; i <= 100; i+=10) {
        printf("---");
    }

    printf("\n %% ");
    for (i = 10; i <= 100; i+=10) {
        printf("%d ", i);
    }
    printf("\n");

    //Vertical    
    printf("\n");
    for (i = 100; i >= 10; i-=10) {
       printf("%3d|", i);

       for (j = 0; j < 3; ++j) {
	  if (percent[j] >= i) {
            printf("\u25a0 ");
	  } else {
            printf("  ");
	  }
       }
       printf("\n");
    }
    printf("%%  ");
    for (i = 0; i < 3; ++i) {
        printf("--");
    }

    printf("\n N  ");
    for (i = 0; i < 3; ++i) {
       if (i == 0) {
          printf("L ");
       } else if (i == 1) {
          printf("N ");
       } else {
          printf("O");
       }
    }
    printf("\n");
    return 0;
}
