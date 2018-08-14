#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "first_day_of_month.c"
#include "leapyear.c"

int main(int argc, char *argv[]) {

	// Get current dates
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int CURRENT_YEAR = tm.tm_year+1900;
	int CURRENT_MONTH = tm.tm_mon;
	int CURRENT_DAY = tm.tm_mday;

	// Set defaults
	int year = CURRENT_YEAR;
	int month = CURRENT_MONTH;

	// Checking for optional arguments
	// Arguments order, Month - Day
	if (argc == 3) {
		month = atoi(argv[1])-1;
		year = atoi(argv[2]);
		if (month > 11 || month < 0) {
			printf("Invalid month argument. Please enter the month then the year\n");
			return EXIT_FAILURE;
		}
	} else if (argc != 1) {
		printf("Expected 2 arguments but %d was provided", argc-1);
		return EXIT_FAILURE;
	}

	int MAX_DAY = 31;
	if(month != 0 && month % 2 != 0) {
		MAX_DAY = 30;
	}
	if(month == 1) {
		if(checkLeap(year)) {
			MAX_DAY = 29;
		} else {
			// Not leap
			MAX_DAY = 28;
		}
	}

	// Invokes function from external c to identify first day of month
	int first_day = first_day_of_month(month+1, year);
	int day = 1;
	const char *month_num[] = {"January", "Feburary", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"};
	printf("     %s %d\n", month_num[month], year);
	printf("Su Mo Tu We Th Fr Sa\n");
	for(int wk = 0; wk < 6; wk++) {
		for(int i = 0; i < 7; i++) {
			if(wk == 0 && i < first_day) {
				printf("   ");
			} else {
				if (month == CURRENT_MONTH && year == CURRENT_YEAR
						&& day == CURRENT_DAY) {
					printf("\033[31;1m%*d\033[0m ", 2, day++);
				} else {
					printf("%*d ", 2, day++);
				}
			}
			if(day > MAX_DAY) {
				printf("\n");
				return EXIT_SUCCESS;
			}
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
