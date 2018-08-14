#include <stdio.h>
#include <stdlib.h>


void checkLeap(int year) {

	if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
		printf("%i is a leap year\n", year);
	} else {
		printf("%i is NOT a leap year\n", year);
	}
}

int main(int argc, char *argv[]) {

	// Check for 1 cmd line argument
	if(argc != 2) {
		printf("Expected 1 argument but received %i argument(s)\n", argc-1);
		return EXIT_FAILURE;
	}

	checkLeap(atoi(argv[1]));
	return EXIT_SUCCESS;
}

