#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h> /* this is to allow malloc() */


int LEN = 20;  /* max input length */


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
	printf("This program is a string to number conversion program\n");
	delay(2000);
	printf("This will take in a type-string made numbers and output a type integer\n");
	delay(2000);
	printf("It might be usefully to get rid of this user friendly section for automoton use\n");
	delay(1000);
	printf("enjoy\n");
	delay(1000);
	/* This is the end of the user friendly section  */
		char* temp = malloc(LEN);
		int integer;
	do{
		fgets(temp, LEN, stdin);
		integer = a_to_i(temp);
		printf("%d\n",integer);
	} while(integer!=0);
}

