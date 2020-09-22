/**************************************************************************
 File name:  stkdriver.c
 Author:     Computer Science, Pacific University
 Date:			 10.11.17
 Class:			 CS300
 Assignment: Static Generic Stack
 Purpose:    Test driver for a static stack of generic elements
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "../include/stk.h"

/**************************************************************************
 Function: 	 	main

 Description: test all the functionality of the stack

 Parameters:	none

 Returned:	 	Exit Status
 *************************************************************************/

int main() {
	Stack sTheStack;
	const int MAX_INPUT_STR_LEN = (STK_MAX_ELEMENTS * 2) + 1;
	char inputString[MAX_INPUT_STR_LEN];

	printf("Enter a string: ");
	scanf("%s", inputString);
	printf("\n");

	int inputLen = strlen(inputString);
	if (inputLen > MAX_INPUT_STR_LEN) {
		printf("Input too long");
		exit(EXIT_SUCCESS);
	}

	stkCreate(&sTheStack);

	for (int i = 0; i < inputLen / 2; i++) {
		stkPush(&sTheStack, inputString[i]);
	}

	int secondStartIndex = inputLen / 2;

	if (0 != inputLen % 2) {
		secondStartIndex++;
	}

	char buffer;
	bool bIsPalindrome = true;

	for (int i = secondStartIndex; i < inputLen && bIsPalindrome; i++) {
		stkPop(&sTheStack, &buffer);
		if (inputString[i] != buffer) {
			bIsPalindrome = false;
		}
	}

	if (bIsPalindrome) {
		printf("%s is a palindrome\n", inputString);
	}
	else {
		printf("%s is not a palindrome\n", inputString);
	}

	return EXIT_SUCCESS;
}
