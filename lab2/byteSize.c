#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

void calcByteSize(long long byte) {

	if(byte / GB >= 1) {
		printf("%lldGByte", byte/GB);
	} else if(byte / MB >= 1) {
		printf("%lldMByte", byte/MB);
	} else if(byte / KB >= 1) {
		printf("%lldKByte", byte/KB);
	} else {
		printf("%lldByte", byte);
	}
	return;
}

int main(int argc, char *argv[]) {

	if(argc < 2) {
		printf("Expected at least 2 arguments but none was given\n");
		return EXIT_FAILURE;
	}

	for(int i = 1; i < argc; i++) {
		// To support larger int, long long is used
		calcByteSize(atoll(argv[i]));
		printf("\n");
	}
	
	return EXIT_SUCCESS;
}
