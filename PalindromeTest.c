/* Author: Kevin Costello
 * Date: 9/23/2016
 */

 #include <stdio.h>

int isPalindrome(char *str) {

	return 0;
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