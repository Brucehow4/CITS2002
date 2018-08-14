#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Compile this program with:
//      cc -std=c99 -Wall -Werror -pedantic -o rot rot.c

int ROT = 13;

//  The rotate function returns the character ROT positions further along the
//  alphabetic character sequence from c, or c if c is not lower-case

char rotate(char c)
{
        // Check if c is lower-case or not
        if (islower(c))
        {
                // The ciphered character is ROT positions beyond c,
                // allowing for wrap-around
		return ('a' + (c - 'a' + ROT) % 26);
        }
	else if (isupper(c)) {
		return ('A' + (c - 'A' + ROT) % 26);
	}
        else
        {
                return c;
        }
}

//  Execution of the whole program begins at the main function

int main(int argc, char *argv[])
{
        // Exit with an error if the number of arguments (including
        // the name of the executable) is not precisely 2
        if(argc < 2)
        {
                fprintf(stderr, "%s: program expected at least 2 argument, but instead received %d\n", argv[0], argc-1);
                exit(EXIT_FAILURE);
        }
        else
        {
		// Allows for different argument types
		for (int i = 1; i < argc; i++) {
			
			// Check for numeric inputs
			if(atoi(argv[i])) {
				ROT = atoi(argv[i]);
				continue;
			}	

			// Check for file inputs
			FILE *file;
			file = fopen(argv[i], "r");
			if (file != NULL) {
				char c = getc(file);
				while (c != EOF) {
					if (isspace(c)) {	
						printf(" ");		
					} else {
						printf("%c", rotate(c));
					}
					c = getc(file);
				}
				
				fclose(file);
				continue;
			}

			// Calculate the length of the first argument
			int length = strlen(argv[i]);

			// Loop for every character in the text
			for(int j = 0; j < length; j++)
			{
				// Determine and print the ciphered character
				printf("%c", rotate(argv[i][j]));
			}
			printf(" ");
		}
                printf("\n");

		// Exit indicating success
                exit(EXIT_SUCCESS);
        }
        return 0;
}
