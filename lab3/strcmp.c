#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getVal(char input[]) {
	int val = 0;
	int i = 0;
	while(input[i] != '\0') {
		char ch = input[i];
		val += ch;
		i++;
	}
	return val;
}

int my_strcmp(char first[], char second[]) {
	int fvalue = getVal(first);
	int svalue = getVal(second);
	
	if(fvalue > svalue) {
		return 1;
	} else if (svalue > fvalue) {
		return -1;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf("Expected 2 argument but received %i\n", argc-1);
		return EXIT_FAILURE;
	}

	int compare = my_strcmp(argv[1], argv[2]);
	
	switch(compare) {
		case 1: 
			printf("%s is bigger than %s\n", argv[1], argv[2]);
			return EXIT_SUCCESS;
		case -1:
			printf("%s is smaller than %s\n", argv[1], argv[2]);
			return EXIT_SUCCESS;
		default:
			printf("%s is the same as %s\n", argv[1], argv[2]);
			return EXIT_SUCCESS;
	}
	return EXIT_SUCCESS;
}
