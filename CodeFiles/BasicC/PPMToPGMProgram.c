#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */

int PPM_MAX = 255;
int Gray_Value;
int collem, row, r, g, b;
int j, i;



void PPM(){
	printf("P2\n");
	scanf("%i %i",&collem, &row);
	printf("%i %i\n", collem, row);
	printf("%i\n", PPM_MAX);
	for(i = 0;i<row;i++){
		scanf("%i %i %i", &r, &g, &b);
		Gray_Value = ((r + g + b) * PPM_MAX) / (3 * PPM_MAX);
		printf("%3i", Gray_Value);
		
		for(j = 0; j<collem;j++){
			scanf("%i %i %i", &r, &g, &b);
			Gray_Value = ((r + g + b) * PPM_MAX) / (3 * PPM_MAX);
			printf(" %3i", Gray_Value);
		}
		printf("\n");
	}
}

void PGM(){
	printf("Since this is a grayscaler, this should not work");
}

main()
{  
	
	/* This is the start of the user friendly section  */
	printf("This program is a PGM Grey-Scaler program\n");
	delay(2000);
	printf("You might need to delete this user friendly section before use\n");
	delay(2000);
	printf("Otherwise, the program takes in PPM data and creates PGM images\n");
	delay(1000);
	printf("enjoy\n");
	delay(1000);
	/* This is the end of the user friendly section  */

  char temp[2]; 
  fgets(temp, 3, stdin);
  PPM();
  }
  
	//if(temp[1]=='2'){
		//PGM();
	//} else{
		//PPM();
	//}
  //}
 