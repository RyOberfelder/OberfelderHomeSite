#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h> /* this is to allow malloc() */

int fibonacci(int n){
	if(n<=0){
		return 0;
	} 
	if(n==1){
		return 1;
	}
	else {
	return fibonacci(n-1)+ fibonacci(n-2);
	}
}


main()
{
	/* This is the start of the user friendly section  */
	printf("This program returns the Fibonacci sequence starting at a positive integer\n");
	delay(2000);
	printf("The program will end when you input a 0\n");
	delay(2000);
	printf("If you need this automated, make sure to delete the user friendly section\n");
	delay(1000);
	printf("enjoy\n");
	delay(1000);
	/* This is the end of the user friendly section  */
		int ourFib, temp;
	do{
		scanf("%u", &temp);
		ourFib = fibonacci(temp);
		printf("%u\n",ourFib);
	}while(ourFib!=0);
}