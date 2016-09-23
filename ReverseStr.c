/* 
 * Author: Kevin Costello 
 * Date: 9/22/2016 
 */
 
#include <stdio.h>
#include <stdlib.h>

char *reverseStr(char *str) {
	char *left = str;
	char *right;
	char temp;

	while (*str != '\0') {
		str++;
	} // Move str to terminating '\0'
	
	// Set right to the last character in str
	right = str - 1;

	// Reset str to original value
	str = left;

	while (left < right) {
		temp = *left;
		*left = *right;
		*right = temp;
		//Move left pointer forward up string
		++left;
		// Right pointer moves backwards
		--right;
	}

	return str;
}

int main(int argc, char **args) {

	char *input = (char *) malloc(sizeof(char) * 20);
	printf("Enter a string less than 20 characters:\n");
	scanf("%s", input);

	reverseStr(input);

	printf("Done Reversing! Here is the result! :\n");
	printf("%s\n", input);

	return 0;
}
