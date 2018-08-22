#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isSafe(char input[]) {

	int i = 0;	
	int upper = 0;
	int lower = 0;
	int digit = 0;

	while(input[i] != '\0') {
		char ch = input[i];
		if(isalpha(ch)) {
			if(islower(ch)) {
				lower++;
			} else {
				upper++;
			}
		} else {
			digit++;
		}
		i++;
	}
	return(lower >= 2 && upper >= 2 && digit >= 2); 
}

int main(int argc, char *argv[]) {
	
	if(argc != 2) {
		printf("Expected 1 argument but received %i\n", argc-1);
		return EXIT_FAILURE;
	}
	
	if(isSafe(argv[1])) {
		printf("This password is safe\n");
	} else {
		printf("This password is not safe\n");
	}
	return EXIT_SUCCESS;

}
