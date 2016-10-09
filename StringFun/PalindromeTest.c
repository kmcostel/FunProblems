/* Author: Kevin Costello
 * Date: 9/23/2016
 * About: Tests if the inputted string is a palindrome
 */

 #include <stdio.h>

int isPalindrome(char *str) {
	char *leftPtr, *rightPtr;

	// At start of the string
	leftPtr = str;
	while (*str != '\0') {
		str++;
	}
	// At last non terminating character in string
	rightPtr = str - 1;

	// Test if a palindrome!
	while (leftPtr < rightPtr) {
		// If character on opposite side of string is not the same then
		// string is not a palindrome
		if (*leftPtr != *rightPtr) {
			return 0;
		}
		else {
			// Move left ptr forward and right pointer backwards
			leftPtr++;
			rightPtr--;
		}
	}

	// String is a palindrome if reached here
	return 1;
}


int main(int argc, char **argv) {
	// Holds user input
	char testStr[20];

	// Prompt and scan in user input
	printf("Enter a string!\n");
	scanf("%s", testStr);

	// Test input and tell user if it's a palindrome
	if (isPalindrome(testStr)) {
		printf("Yea that's a palindrome!\n");
	}
	else {
		printf("Sorry! Not a palindrome!\n");
	}

	return 0;
}