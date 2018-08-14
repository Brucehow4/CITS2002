#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	// q5 a
	printf("**********\n");
	
	// q5 b
	for(int i = 0; i < 10; i++) {
		printf("*\n");	
	}

	// q5 c
	for(int i = 0; i < 10; i++) {
		printf("*****\n");
	}

	// q6 a
	for(int r = 1; r <= 5; r++) {
		for(int j = 1; j <= r; j++) {
			printf("*");
		}	
		printf("\n");
	}

}
