#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "program.h"

#define NO_ALPHABETS 4
#define MAX_LETTERS 25

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
			terminate_program();
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

/*
*	Encrypts an inputted cipher against an alphabet text file
*/
int encrypt_cipher() {
	int i, j;
	int alphabet [NO_ALPHABETS][MAX_LETTERS];
	const char *cipher_title = "Encrypt Cipher \n\n";
	FILE *alphabetFile = fopen("alphabet.txt", "%r");

	printf("%s", cipher_title);

	// read and store the alphabet text file
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 25; j++) {
			//alphabet[i][j] = fgetc(alphabetFile);
			//printf("%d", alphabet[i][j]);
		}
	}

	fclose(alphabetFile);

	return 0;
}

void terminate_program() {
	exit(0);
}