/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h> /* this is to allow malloc() */

char* assign(char *s1, const char *s2){
    char *s = s1; //this is the noted 1 step
	/* this assigns memory, starting at the reference of s1(noted 1)
	and assigns it the memory location of s2 until it gets to the end
	character 0. this is why there is a 0 in the while. \0 */
    while ((*s++ = *s2++) != 0); 
	return (s1); //this is where it returns the locations of effectly s1
}
int NUM = 25;   /* number of strings */
int LEN = 1000;  /* max length of each string */

main()
{
  int i,j,k, sorted;
  char* Strings[NUM];
  
  /* Start of people friendly section */
  printf("This currently sorts %d Strings with a max length of %d alphabetically\n", NUM, LEN);
  delay(1000);
  printf("Programming beginning shortly\n");
  delay(2000);
  
  printf("Please enter %d strings, one per line:\n", NUM);

  for(i=0;i<NUM;i++){  // where there is 5 put in a NUM
    char *temp = malloc(LEN); 
	fgets(temp, LEN, stdin);
	Strings[i] = temp;
  }
  
  puts("\nHere are the strings in the order you entered:");
  
  for(i=0;i<NUM;i++){// where there is 5 put in a NUM
	printf("%s",Strings[i]);
  }

  puts("\nIn alphabetical order, the strings are:");
  

do {
	sorted=1;
	for (i=1;i<NUM;i++){
		if (strcmp((Strings[i]),(Strings[i-1]))<0){
			sorted = 0;
			char* temp;
			temp= Strings[i];
			Strings[i] = Strings[i-1];
			Strings[i-1]=temp;
			break;
		}
		else if (strcmp((Strings[i]),(Strings[i-1]))==0){
		}
	}		
} while (sorted!=1);

  for(i=0;i<NUM;i++){
	printf("%s",Strings[i]);
  }
  
	return 0;
}