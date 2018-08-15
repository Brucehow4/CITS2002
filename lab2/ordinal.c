#include <stdio.h>
#include <stdlib.h>

void getOrdinal(int value) {

	// Use mod 10 to get the value in the "ones" place
	int digit = value % 10;

	// Switch over if-statements for better run-time
	switch(digit) {	
		case 1:
			printf("%ist", value);
			return;
		case 2:
			printf("%ind", value);
			return;
		case 3:
			printf("%ird", value);
			return;
		default:
			printf("%ith", value);
			return;
	}
}


int main(int argc, char *argv[]) {

	if(argc < 2) {
		printf("Expected at least 2 arguments but %i was given\n", argc-1);
		return EXIT_FAILURE;
	}

	for(int i = 1; i < argc; i++) {
		getOrdinal(atoi(argv[i]));
		printf("\n");
	}
	
	return EXIT_SUCCESS;
}
