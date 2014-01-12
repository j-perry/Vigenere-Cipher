#include <stdlib.h>
#include <stdio.h>

#include "program.h"

const char *NEW_LINE = "\n";

/*
*	Executes the main body of our program
*/
int execute_program() {
	program_title();

	return 0;
}

/*
*	Prints the program title
*/
void program_title() {
	const char *program_title = "Vigenere Cipher";

	printf("%s", program_title);
	printf("%s %s", NEW_LINE, NEW_LINE);
}