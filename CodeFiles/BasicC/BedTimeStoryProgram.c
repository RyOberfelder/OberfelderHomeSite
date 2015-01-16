#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h> /* this is to allow malloc() */

void bedtimestory(char words[20][15], int current, int number) {
	int i;
	if(strcmp(words[0],"END\n")==0){
		printf("Stories were told and songs were written.\n");
		return;
	}
	if(strcmp(words[1],"END\n")==0){
		printf("A ");
		i=0;
		while(words[current][i]!='\n'){
			printf("%c",words[current][i]);
			i++;
		}
		printf(" couldn't sleep, so her mother told a story and the ");
		i=0;
		while(words[current][i]!='\n'){
			printf("%c",words[current][i]);
			i++;
		}
		printf(" fell asleep.\n");
		return;
	}
	if(strcmp(words[current+1],"END\n")==0){
		for(i = 0; i<current;i++){
			printf("  ");
		}
		printf("... who fell asleep.\n");
		return;
	}
	if(current==0){
		printf("A ");
		i=0;
		while(words[current][i]!='\n'){
			printf("%c",words[current][i]);
			i++;
		}
		printf(" couldn't sleep, so her mother told a story about a little ");
		i=0;
		while(words[current+1][i]!='\n'){
			printf("%c",words[current+1][i]);
			i++;
		}
		printf(",\n");
		bedtimestory(words, current+1, number);
	}else{
		for(i = 0; i<current;i++){
			printf("  ");
		}
		printf("who couldn't sleep, so the ");
		i=0;
		while(words[current][i]!='\n'){
			printf("%c",words[current][i]);
			i++;
		}
		printf("'s mother told a story about a little ");
		i=0;
		while(words[current+1][i]!='\n'){
			printf("%c",words[current+1][i]);
			i++;
		}
		printf(",\n");
		bedtimestory(words, current+1, number);
	}
	if(current==0){
		printf("... and then the ");
		i=0;
		while(words[current][i]!='\n'){
			printf("%c",words[current][i]);
			i++;
		}
		printf(" fell asleep.\n");
	}else {
		for(i = 0; i<current;i++){
			printf("  ");
		}
		printf("... and then the little ");
		i=0;
		while(words[current][i]!='\n'){
			printf("%c",words[current][i]);
			i++;
		}
		printf(" fell asleep;\n", words[current]);
	}
}


main() {
  int nameNumber = 20;
  int maxLength = 15;
  char names[nameNumber][maxLength];  
  int num;
  
  	/* This is the start of the user friendly section  */
	printf("This program is a recursive Bedtime Story Fabricator\n");
	delay(2000);
	printf("It will take in strings and recursively put them in to create structured story\n");
	delay(2000);
	printf("you'll see what I mean shortly\n");
	delay(1000);
	printf("enjoy\n");
	delay(1000);
	/* This is the end of the user friendly section  */

  for(num=0;num<nameNumber;num++){ 
	fgets(names[num], maxLength, stdin);
	if(strcmp(names[num],"END\n")==0){
		break;
	}
  }
  
  bedtimestory(names, 0, num);
}