#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char mystr[]) {
	int i = 0;
	while(mystr[i] != '\0') {
		i++;	
	}
	return i;
}

int main(int argc, char *argv[]) {

	if(argc != 2) {
		printf("Expected 1 argument but received %i\n", argc-1);
		return EXIT_FAILURE;
	}
	int len = my_strlen(argv[1]);
	printf("String length is %i\n", len);

	return EXIT_SUCCESS;
}
