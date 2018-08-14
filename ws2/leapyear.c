#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkLeap(int year) {

	if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
		return true;
	} else {
		return false;
	}
}

