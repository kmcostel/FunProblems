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
		if (*leftPtr != *rightPtr) {
			return 0;
		}
		else {
			leftPtr++;
			rightPtr--;
		}
	}


	return 1;
}


int main(int argc, char **argv) {
	char testStr[20];

	printf("Enter a string!\n");
	scanf("%s", testStr);

	if (isPalindrome(testStr)) {
		printf("Yea that's a palindrome!\n");
	}
	else {
		printf("Sorry! Not a palindrome!\n");
	}

	return 0;
}