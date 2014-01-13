#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "program.h"

#define NO_ALPHABETS 4
#define MAX_LETTERS 27

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
	program_menu();

	scanf("%d", &option);
	
	switch(option) {
		case ENCRYPT:
			encrypt_cipher();
			break;
		case DECRYPT:
			decrypt_cipher();
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
*	Program menu
*/
void program_menu() {
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
	char letter;
	char alphabet [NO_ALPHABETS][MAX_LETTERS];
	const char *cipher_title = "\n\nEncrypt Cipher \n\n";
	char *alphaFileDestination = "alphabet.txt";
	FILE *f_alphabet = fopen(alphaFileDestination, "r");
	char userInput [MAX_LETTERS]; 

	printf("%s", cipher_title);

	if(f_alphabet != NULL) {
		// read and store the alphabet text file
		for(i = 0; i < NO_ALPHABETS; i++) {
			for(j = 0; j < MAX_LETTERS; j++) {
				alphabet[i][j] = fgetc(f_alphabet);
				printf("%c", alphabet[i][j]);
			}
		}
	}
	else {
		perror("Unable to open file");
	}
	
	fclose(f_alphabet);

	// retrieve user input
	printf("%s", "\n\nEnter in word to be encrypted: ");
	scanf("%s", &userInput);
		
	printf("%s", "\n");
		
	return 0;
}

/*
*	Decrypts the cipher text
*/
int decrypt_cipher() {
	return 0;
}

/*
*	Terminates the program
*/
void terminate_program() {
	exit(0);
}