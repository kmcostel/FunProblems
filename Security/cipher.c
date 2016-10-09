/* Program #1
   Class: CPE321
   Written by: Kevin Costello
   Due Date: 10/6/2016
 */
// stdio needed for scanf(), printf()
#include <stdio.h>
// stdlib needed for malloc()
#include <stdlib.h>
// string.h needed for strlen()
#include <string.h>

// Prompt the user for a string, malloc space to hold it,
// and return the pointer to the string
char* strPrompt() {
   char *prompt = "Enter a string to encrypt OR\nPress 'Control + c' to exit the program";
   // Entered data to be 30 characters long
   char *enteredStr = (char *) malloc(sizeof(char) * 30);

   // Check error message of these!!!
   printf("\n%s\n\n> ", prompt);
   scanf("%s", enteredStr);

   return enteredStr;
}

int getCipherSize() {
   int size;

   printf("\nPlease enter number to cipher your text with:\n\n> ");
   scanf("%d", &size);

   return size;
}

// str is a pointer to the user's entered string
// encryptSize is guaranteed to be in range of [0,25]
void encrypt(char* str, int encryptSize) {
   int strLength;
   int diff;

   strLength = strlen(str);

   // The current character being ciphered
   char c;
   for (int i = 0; i < strLength; i++) {
      c = str[i];
      if (c >= 'a' && c <= 'z') {
         str[i] = c + encryptSize;
         if (c + encryptSize > 'z') {
            diff = c + encryptSize - 'z';
            // Subtract 1 because going from z -> a counts as a shift of 1
            str[i] = 'a' + diff - 1;
         }
      }
      else if (c >= 'A' && c <= 'Z') {
         str[i] = c + encryptSize;
         //Check if past the end of alphabet after shifting
         if (c + encryptSize > 'Z') {
            //If so, find out how far past
            diff = str[i] - 'Z';
            // Use diff as an offset from the start of the alphabet
            // Subtract 1 because going from 'Z' -> 'A' counts as a shift of 1
            str[i] = 'A' + diff - 1;
         }
      }

   }

}

void run() {
	// Holds the user's inputted string
	char *str;
   int cipherSize;

	// Run until the user presses 'control + c'
	while (1) {
	   str = strPrompt();
      cipherSize = getCipherSize();
      // Modding by 26 in case of shift sizes > 26. 26 chars in alphabet
      // Want to keep alphabetic characters in same realm
      // ie. turn lower case letters into other lower case letters
      // and turn upper case letters into other upper case letters
	   encrypt(str, cipherSize % 26);
      printf("\nEncrypted string = %s\n", str);

      // Free the malloced memory that holds the user's entered string
      free(str);
	}

}


int main (int argc, char **argv) {
   printf("*****Basic Cipher text program*****\n");
   run();

   return 0;
}
