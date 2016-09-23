#include <stdio.h>
#include <stdlib.h>

char *reverseStr(char *str) {
	printf("%X", (unsigned int)str);
	char *left = str;
	char *right;
	char temp;

	while (*str++ != '\0'); // Move str past end of string
	// Set right to the last character in str

	right = str - 1;
	printf("%c", *right);
	// Reset str to original value
	str = left;
	printf("%s\n", str);

	while (left < right) {
		printf("%c", *left);
		temp = *left;
		*left = *right;
		*right = temp;
		++left;
		--right;
	}

	printf("%X", (unsigned int)str);
	return str;
}

int main(int argc, char **args) {

	char *input = (char *) malloc(sizeof(char) * 20);
	printf("Enter a string less than 20 characters:\n");
	scanf("%s", input);

	input = reverseStr(input);

	printf("Done Reversing! Here is the result! :");
	printf("%s\n", input);

	return 0;
}
