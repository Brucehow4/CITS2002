#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void letterMap(int val) {
	switch(val) {
		case 1:
			printf("I");
			return;
		case 5:
			printf("V");
			return;
		case 10:
			printf("X");
			return;
		case 50:
			printf("L");
			return;
		case 100:
			printf("C");
			return;
		case 500:
			printf("D");
			return;
		default:
			printf("M");
	}
	return;
}

void getLetter(int num, int mp) {
	
	// mp is the multiplyer, indicates digit position
	// handles I/X
	if(num <= 3 * mp) {
		for(int i = 0; i < num / mp; i++) {
			letterMap(1 * mp);				
		}
	} else if(num <= 5 * mp) {
		for(int i = 0; i * mp < (5*mp - num) / mp; i++) {
			letterMap(1 * mp);
		}
		letterMap(5 * mp);
	} else if(num <= 7 * mp) {
			letterMap(5 * mp);
		for(int i = 0; i * mp < (num - 5*mp); i++) {
			letterMap(1 * mp);
		}
	} else {
		for(int i = 0; i * mp < (10*mp - num); i++) {
			letterMap(1 * mp);		
		}
		letterMap(10 * mp);
	}
}	

void convert(int num) {

	int accumulatedSum = 0;
	// Get each digit
	int ones = num % 10;
	accumulatedSum += ones;
	int tens = (num % 100) - accumulatedSum;
	accumulatedSum += tens;
	int hundreds = (num % 1000) - accumulatedSum;
	accumulatedSum += hundreds;
	int thousands = (num % 10000) - accumulatedSum;
	accumulatedSum += thousands;

	if(num >= 10000) {
		for(int i = 1000; i <= num - accumulatedSum; i+= 1000) {
		       printf("M");	
		}
	}

	getLetter(thousands, 1000);
	getLetter(hundreds, 100);
	getLetter(tens, 10);
	getLetter(ones, 1);
	return;
}

int main(int argc, char *argv[]) {

	// Argument handler
	if(argc != 2) {
		printf("Expected 1 argument but %i was supplied\n", argc-1);
		return EXIT_FAILURE;
	}
	if(atoi(argv[1]) < 1) {
		printf("Provided argument must be at least 1\n");
		return EXIT_FAILURE;
	}

	convert(atoi(argv[1]));
	printf("\n");

	return EXIT_SUCCESS;
}
