#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	// Checks that there is a provided argument
	if(argc < 2) {
		printf("Expected at least 2 arguments but %i was given\n", argc-1); 
		return EXIT_FAILURE;
	}

	int max = atoi(argv[1]);

	for(int i = 1; i < argc; i++) {
		if(atoi(argv[i]) >= max) {
			max = atoi(argv[i]);
		}
	}
	printf("Largest number: %i\n", max);

	return EXIT_SUCCESS;

}
