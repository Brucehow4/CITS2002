#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char mystr[]) {
	int len = strlen(mystr);
	for(int i = 0; i < len; i++) {
		if(tolower(mystr[i]) != tolower(mystr[len-1-i])) {
			return false;
		}
	}	
	return true;
}

int main(int argc, char *argv[]) {

	if(argc != 2) {
		printf("Expected 1 argument but received %i\n", argc-1);
		return EXIT_FAILURE;
	}
	
	if(isPalindrome(argv[1])) {
		printf("%s is a palindrome\n", argv[1]);		
	} else {
		printf("%s is not a palindrome\n", argv[1]);
	}
	
	return EXIT_SUCCESS;
}
