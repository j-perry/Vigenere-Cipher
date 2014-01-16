#include <stdio.h>

#ifndef PROGRAM_EXECUTE
#define PROGRAM_EXECUTE
	int execute_program();
#endif;

#ifndef PROGRAM_TITLE
#define PROGRAM_TITLE
	void program_title();
#endif;
	
#ifndef PROGRAM_INSTRUCTIONS
#define PROGRAM_INSTRUCTIONS
	void program_menu();
#endif;

#ifndef PROGRAM_MENU_CHOICE
#define PROGRAM_MENU_CHOICE
	void program_menu_choice();
#endif;

#ifndef ENCRYPT_CIPHER
#define ENCRYPT_CIPHER
	int encrypt_cipher();
#endif;

#ifndef DECRYPT_CIPHER
#define DECRYPT_CIPHER
	int decrypt_cipher();
#endif;

#ifndef TERMINATE_PROGRAM
#define TERMINATE_PROGRAM
	void terminate_program();
#endif;