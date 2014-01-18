#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "program.h"

#define NO_ALPHABETS 5
#define MAX_LETTERS 27

const char *NEW_LINE = "\n";

enum MenuOptions { 
	ENCRYPT = 1, 
	DECRYPT = 2, 
	CLOSE_PROGRAM = 3
} menu_options;

/*
*	Executes the main body of our program
*/
int execute_program() {
	int option = 0;

	program_title();
	program_menu();
	program_menu_choice();

	return 0;
}

/*
*	Parses the user's menu choice
*/
void program_menu_choice() {
	int option = 0;
		
	scanf("%d", &option);

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
		program_menu_choice();
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
	const char *cipher_title = "\n-------------------\n\nEncrypt Cipher";
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
		
		switch(letter) {
			case 'a':
				encryptedLetter = alphabet[j][0];
				break;
			case 'b':
				encryptedLetter = alphabet[j][1];
				break;
			case 'c':
				encryptedLetter = alphabet[j][2];
				break;
			case 'd':
				encryptedLetter = alphabet[j][3];
				break;		
			case 'e':
				encryptedLetter = alphabet[j][4];
				break;	
			case 'f':
				encryptedLetter = alphabet[j][5];
				break;
			case 'g':
				encryptedLetter = alphabet[j][6];
				break;	
			case 'h':
				encryptedLetter = alphabet[j][7];
				break;	
			case 'i':
				encryptedLetter = alphabet[j][8];
				break;	
			case 'j':
				encryptedLetter = alphabet[j][9];
				break;	
			case 'k':
				encryptedLetter = alphabet[j][10];
				break;	
			case 'l':
				encryptedLetter = alphabet[j][11];
				break;	
			case 'm':
				encryptedLetter = alphabet[j][12];
				break;	
			case 'n':
				encryptedLetter = alphabet[j][13];
				break;	
			case 'o':
				encryptedLetter = alphabet[j][14];
				break;	
			case 'p':
				encryptedLetter = alphabet[j][15];
				break;	
			case 'q':
				encryptedLetter = alphabet[j][16];
				break;	
			case 'r':
				encryptedLetter = alphabet[j][17];
				break;	
			case 's':
				encryptedLetter = alphabet[j][18];
				break;	
			case 't':
				encryptedLetter = alphabet[j][19];
				break;	
			case 'u':
				encryptedLetter = alphabet[j][20];
				break;	
			case 'v':
				encryptedLetter = alphabet[j][21];
				break;	
			case 'w':
				encryptedLetter = alphabet[j][22];
				break;	
			case 'x':
				encryptedLetter = alphabet[j][23];
				break;	
			case 'y':
				encryptedLetter = alphabet[j][24];
				break;
			case 'z':
				encryptedLetter = alphabet[j][25];
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

	// re-display the menu
	program_menu();
	program_menu_choice();
		
	return 0;
}

/*
*	Decrypts the cipher text
*/
int decrypt_cipher() {	
	int c;
	int size = 0;
	char decryptedLetter;
	char encryptedLetter;
	char alphabet [NO_ALPHABETS][MAX_LETTERS];
	char encryptedContents[MAX_LETTERS];
	char *alphaFileDestination = "alternative_alphabet.txt";
	char *encryptedFile = "encrypted.txt";
	char *decryptedFile = "decrypted.txt";
	int i, j, k = 0;
	
	FILE *f_alphabet = fopen(alphaFileDestination, "r");
	FILE *f_encryptedContents = fopen(encryptedFile, "r");
	FILE *f_decryptedContents = fopen(decryptedFile, "w+");

	if(f_alphabet != NULL) {
		// read and store the alphabet text file
		for(i = 0; i < NO_ALPHABETS; i++) {
			for(j = 0; j < MAX_LETTERS; j++) {
				alphabet[i][j] = fgetc(f_alphabet);
			}
		}
	}
	else {
		perror("Unabled to open alphabet.txt");
	}

	fclose(f_alphabet);

	i = 0;
	j = 0;
	//k = 0;

	// now read the encrypted.txt file
	if(f_encryptedContents != NULL) {
		// get the number of characters in the encrypted text file
		fseek(f_encryptedContents, 0, SEEK_END); // seek end of file
		size = ftell(f_encryptedContents); // get current file pointer
		fseek(f_encryptedContents, 0, SEEK_SET); // seek back to the beginning of file
				
		printf("\n");
		printf("Size: ");
		printf("%i", size);
		printf("\n");
		
		while(!feof(f_encryptedContents)) {
			// prevents the last index from being written twice
			if(i != size) {
				encryptedLetter = fgetc(f_encryptedContents);
					
				printf("\n");
				printf("%c", encryptedLetter);
				printf(" [i] ");
				printf("%i", i);
				printf(", ");
			
				// reset the counters
				if(j == NO_ALPHABETS) {
					j = 0;
				}
				
				switch(encryptedLetter) {
					case 'a':
						decryptedLetter = alphabet[j][0];
						break;
					case 'b':
						decryptedLetter = alphabet[j][1];
						break;
					case 'c':
						decryptedLetter = alphabet[j][2];
						break;
					case 'd':
						decryptedLetter = alphabet[j][3];
						break;		
					case 'e':
						decryptedLetter = alphabet[j][4];
						break;	
					case 'f':
						decryptedLetter = alphabet[j][5];
						break;
					case 'g':
						decryptedLetter = alphabet[j][6];
						break;	
					case 'h':
						decryptedLetter = alphabet[j][7];
						break;	
					case 'i':
						decryptedLetter = alphabet[j][8];
						break;	
					case 'j':
						decryptedLetter = alphabet[j][9];
						break;	
					case 'k':
						decryptedLetter = alphabet[j][10];
						break;	
					case 'l':
						decryptedLetter = alphabet[j][11];
						break;	
					case 'm':
						decryptedLetter = alphabet[j][12];
						break;	
					case 'n':
						decryptedLetter = alphabet[j][13];
						break;	
					case 'o':
						decryptedLetter = alphabet[j][14];
						break;	
					case 'p':
						decryptedLetter = alphabet[j][15];
						break;	
					case 'q':
						decryptedLetter = alphabet[j][16];
						break;	
					case 'r':
						decryptedLetter = alphabet[j][17];
						break;	
					case 's':
						decryptedLetter = alphabet[j][18];
						break;	
					case 't':
						decryptedLetter = alphabet[j][19];
						break;	
					case 'u':
						decryptedLetter = alphabet[j][20];
						break;	
					case 'v':
						decryptedLetter = alphabet[j][21];
						break;	
					case 'w':
						decryptedLetter = alphabet[j][22];
						break;	
					case 'x':
						decryptedLetter = alphabet[j][23];
						break;	
					case 'y':
						decryptedLetter = alphabet[j][24];
						break;
					case 'z':
						decryptedLetter = alphabet[j][25];
						break;	
					default: 
						break;
				}

				
				printf("\n");
				printf("Decrypted Letter: ");
				printf("%c", decryptedLetter);
				
				// write contents to .txt file
				fprintf(f_decryptedContents, "%c", decryptedLetter);

				i++;
				j++;
			}
			else {
				break;
			}						
		}

		fclose(f_decryptedContents);
		
		printf("\n\n");

		// re-display the menu
		program_menu();
		program_menu_choice();

		return 0;
	}
	else {
		printf("%s", "\nCan't open 'encrypted.txt'.\nYou haven't yet encrypted any contents!\n\n");

		// re-display the menu
		program_menu();
		program_menu_choice();
		return 0;
	}
}

/*
*	Terminates the program
*/
void terminate_program() {
	exit(0);
}