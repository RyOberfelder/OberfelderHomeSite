#include <stdio.h>

int facVal;
factorial(int val){
	if (val!=0){
		facVal=val;
		val--;
		while (val>1){
			facVal=facVal*val;
			val--;
		}
	}
	else {
		facVal=1;
	}
}

main(){
	int input;
	/* This is the start of the user friendly section  */
	printf("This program is a factorial program\n");
	delay(2000);
	printf("While you enter a positive integer number greater then 0, the program loops\n");
	delay(2000);
	printf("entering negative numbers is beyond current scope\n");
	delay(1000);
	printf("entering 0 stops the program\n");
	delay(1000);
	printf("enjoy\n");
	delay(1000);
	/* This is the end of the user friendly section  */
	
	do {
		printf("Enter a number:");
		scanf("%d", &input);
		printf(" %d! = ",input);
		factorial(input);
		printf("%d\n",facVal);
	} while(input!=0);
}