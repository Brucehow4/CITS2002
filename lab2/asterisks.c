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
	// q6 b
	for(int i = 4; i >= 0; i--) {
		for(int j = 0; j < i; j++) {
			printf(" ");
		}
		for(int k = 0; k < 5-i; k++) {
			printf("*");
		}
		printf("\n");
	}

	// q6 c
	for(int i = 5; i > 0; i--) {
		for(int k = i; k > 0; k--) {
			printf("*");
		}
		printf("\n");
	}

	// q6 d
	int count = 1;
	for(int i = 4; i >= 0; i--) {
		for(int k = 0; k < i; k++) {
			printf(" ");
		}
		for(int m = 0; m < count; m++) {
			printf("*");
		}
		printf("\n");
		count += 2;
	}

}
