/**************************************************************************
 File name:  stktester.c
 Author:     Computer Science, Pacific University
 Date:			 10.11.17
 Class:			 CS300
 Assignment: Static Generic Stack
 Purpose:    Test driver for a static stack of generic elements
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "../include/stk.h"

/****************************************************************************
 Function: 	 	success

 Description: print a success message

 Parameters:	pszStr - the message to print

 Returned:	 	none
 ****************************************************************************/
static void success(char *pszStr) {
	printf("SUCCESS: %s\n", pszStr);
}

/****************************************************************************
 Function: 	 	failure

 Description: print a failure message

 Parameters:	pszStr - the message to print

 Returned:	 	none
 ****************************************************************************/
static void failure(char *pszStr) {
	printf("FAILURE: %s\n", pszStr);
}

/****************************************************************************
 Function: 	 	assert

 Description: if the expression is true, assert success; otherwise, assert
 failure

 Parameters:	szStr - the message to print

 Returned:	 	none
 ****************************************************************************/
static void assert(bool bExpression, char *pTrue, char *pFalse) {
	if (bExpression) {
		success(pTrue);
	} else {
		failure(pFalse);
	}
}

/**************************************************************************
 Function: 	 	main

 Description: test all the functionality of the stack

 Parameters:	none

 Returned:	 	Exit Status
 *************************************************************************/

int main() {
	Stack sTheStack;
	char data;

	puts("Program Start\n");

	puts("SUCCESS TESTS:");

	stkLoadErrorMessages();
	success("Loaded Error Messages");

	stkCreate(&sTheStack);
	success("Stack Created");

	assert(stkSize(&sTheStack) == 0, "Stack size is 0", "Stack size is NOT 0");

	stkTerminate(&sTheStack);
	success("Stack Terminated");

	stkPush(&sTheStack, 'C');

	stkPop(&sTheStack, &data);

	printf("Data: %c\n", data);

	puts("\nProgram End");

	return EXIT_SUCCESS;
}
