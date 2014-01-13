#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "program.h"

const char *NEW_LINE = "\n";
enum Options { 
	ENCRYPT = 1, 
	DECRYPT = 2, 
	CLOSE_PROGRAM = 3
} options;

/*
*	Executes the main body of our program
*/
int execute_program() {
	//options menu_option;
	int option = 0;

	program_title();
	program_instructions();

	scanf("%d", &option);
	
	switch(option) {
		case ENCRYPT:
			encrypt_cipher();
			break;
		case DECRYPT:
			break;
		case CLOSE_PROGRAM:	
			break;
		default:
			break;
	}

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

/*
*	Program instructions
*/
void program_instructions() {
	char instructions [150] = "";

	strcat(instructions, "------------------");	
	strcat((char *) instructions, NEW_LINE);
	strcat((char *) instructions, "       Menu  ");
	strcat((char *) instructions, NEW_LINE);
	strcat((char *) instructions, "------------------");
	strcat((char *) instructions, NEW_LINE);
	strcat((char *) instructions, NEW_LINE);
	strcat((char *) instructions, "Option 1: Encrypt");
	strcat((char *) instructions, NEW_LINE);
	strcat((char *) instructions, "Option 2: Decrypt");
	strcat((char *) instructions, NEW_LINE);
	strcat((char *) instructions, "Option 3: Close Program");
	strcat((char *) instructions, NEW_LINE);
	strcat((char *) instructions, NEW_LINE);
	strcat((char *) instructions, "Enter your choice: ");

	printf("%s", instructions);
}

int encrypt_cipher() {
	exit(0);

	return 0;
}