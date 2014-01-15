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
	
	program_menu_choice(option);

	return 0;
}

/*
*	Parses the user's menu choice
*/
void program_menu_choice(int option) {
	if(option == ENCRYPT) {
		encrypt_cipher();
	}
	else if(option == DECRYPT) {
		decrypt_cipher();
	}
	else if(option == CLOSE_PROGRAM) {
		terminate_program();
	}
	else {
		printf("%s", "\n");
		printf("%s", "Invalid. Enter a valid option:");
		printf("%s", "\n\n");

		program_menu();
		scanf("%d", &option);
		program_menu_choice(option);
	}		
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
	int i, j, k;
	char letter;
	char alphabet [NO_ALPHABETS][MAX_LETTERS];
	const char *cipher_title = "\n\nEncrypt Cipher \n\n";
	char *alphaFileDestination = "alphabet.txt";
	char *encryptedFile = "encrypted.txt";
	FILE *f_alphabet = fopen(alphaFileDestination, "r");
	FILE *f_encryptedContents = fopen(encryptedFile, "w+");
	char userInput [MAX_LETTERS]; 
	//char encryptedInput [MAX_LETTERS];
	char encryptedLetter;

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
	scanf("%s", userInput);
		
	printf("%s", "You entered: ");
	printf("%s", userInput);
	printf("%s", "\n\n");

	i = 0;
	j = 0; // alphabet no.
	k = 0; // alphabet letters
	
	// encrypt the user input
	while(i != strlen(userInput)) {
		letter = userInput[i];	

		// reset the counters
		if(j == NO_ALPHABETS) {
			j = 0;
		}
		else if(k == MAX_LETTERS) {
			k = 0;
		}

		switch(letter) {
			case 'a':
				encryptedLetter = alphabet[j][k];
				break;
			case 'b':
				encryptedLetter = alphabet[j][k];
				break;
			case 'c':
				encryptedLetter = alphabet[j][k];
				break;
			case 'd':
				encryptedLetter = alphabet[j][k];
				break;		
			case 'e':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'f':
				encryptedLetter = alphabet[j][k];
				break;
			case 'g':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'h':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'i':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'j':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'k':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'l':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'm':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'n':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'o':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'p':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'q':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'r':
				encryptedLetter = alphabet[j][k];
				break;	
			case 's':
				encryptedLetter = alphabet[j][k];
				break;	
			case 't':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'u':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'v':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'w':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'x':
				encryptedLetter = alphabet[j][k];
				break;	
			case 'y':
				encryptedLetter = alphabet[j][k];
				break;
			case 'z':
				encryptedLetter = alphabet[j][k];
				break;	
			default: 
				break;
		}
		
		// write contents to .txt file
		fprintf(f_encryptedContents, "%c", encryptedLetter);
		i++; 
		j++;
		k++;
	}
	
	printf("%s", "\n");
	printf("%s", "-----------------------");
	printf("%s", "\n\n");
	printf("%s", "Encryption succcessful!");
	printf("%s", "\n\n");

	fclose(f_encryptedContents);
		
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