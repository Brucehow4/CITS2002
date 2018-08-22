#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool luhn(char card[]) {
	int s1 = 0;
	int s2 = 0;

	int count = 1;

	int len = strlen(card);
	for(int i = len-1; i >= 0; i--) {
		int val = card[i] - '0'; // convert to actual int value
		if(count % 2 == 1) {
			s1 += val;
		} else {
			int valMod = val*2;
			if(valMod > 9) {
				int ones = valMod % 10;
				int tens = (valMod - ones) / 10;
				int total = ones + tens;
				s2 += total;
			} else {
				s2 += valMod;
			}	
		}
		count++;
	}
	return ((s1 + s2) % 10 == 0);
}

int main(int argc, char *argv[]) {

	if(argc != 2) {
		printf("Expected 1 argument but received %i\n", argc-1);
		return EXIT_FAILURE;
	}

	if(luhn(argv[1])) {
		printf("%s is a valid credit card\n", argv[1]);
	} else {
		printf("Invalid credit card!\n");
	}
	return EXIT_SUCCESS;
}
