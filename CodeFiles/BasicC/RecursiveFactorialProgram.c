#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h> /* this is to allow malloc() */


int LEN = 20;  /* max input length */

int factorial(int n){
	if(n==0){
		return 1;
	} else {
	return n*factorial(n-1);
	}
}

int a_to_i(char* str){
	int integer = 0;
	int i;
	for(i = strlen(str)-1;i>0;i--){
		integer = integer*10;
		integer = integer + *str-48;
		str++;
	}
	return integer;
}

main()
{
	/* This is the start of the user friendly section  */
	printf("This program is a Recursive Factorial program\n");
	delay(2000);
	printf("This will in possitive integers to factorial until you input a 0\n");
	delay(2000);
	printf("Note: 0 halts the program\n");
	delay(1000);
	printf("Do not enter negative integers or greater then 2 digit numbers\n");
	delay(1000);
	printf(" Otherwise, enjoy\n");
	delay(1000);
	/* This is the end of the user friendly section  */
		char* temp = malloc(LEN);
		int integer,ourFac;
	do{
		fgets(temp, LEN, stdin);
		integer = a_to_i(temp);
		ourFac = factorial(integer);
		printf("%d\n",ourFac);
	} while(integer!=0);
}

