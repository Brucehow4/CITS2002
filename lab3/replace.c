#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void replace(char identifier[], char replace[], char input[]) {	
	char* sub = strstr(input, identifier);
	long int pos = sub - input;
	if(pos > strlen(input)) {
		printf("Could not find %s in %s\n", identifier, input);
	}

	int idenLen = strlen(identifier);
	int i = 0;
	while(input[i] != '\0') {
		if(i == pos) {
			printf("%s", replace);
			i += idenLen;
		} else {
			printf("%c", input[i]);
			i++;
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]) {

	if(argc != 4) {
		printf("Expected 3 argument but received %i\n", argc-1);
		return EXIT_FAILURE;
	}
	replace(argv[1], argv[2], argv[3]);
	return EXIT_SUCCESS;
}
