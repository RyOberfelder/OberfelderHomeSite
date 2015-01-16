/* Example: matrices represented by 2-dimensional arrays */

#include <stdio.h>

int A[3][3];
int B[3][3];
int C[3][3];
void scannerLoop(int M[3][3]){
int v2v, h2h;
	for (v2v=0;v2v<3;v2v++){
        for (h2h=0;h2h<3;h2h++){
			scanf("%d",&M[v2v][h2h]);
		}		
	}
}

void matrixPrinter(int M[3][3]){
int v, h;
   for (v=0;v<3;v++){
        for (h=0;h<3;h++){
            printf("%6d", M[v][h]);
		}
		printf("\n");
	}
} 	

main(){

	/* This is the start of the user friendly section  */
	printf("This program is a 3 by 3 matrix printing and multiplying program\n");
	delay(2000);
	printf("The program takes in values, prints them, muliplies them, and prints again \n");
	delay(2000);
	printf("Be sure to follow the instructions and you will be fine\n");
	delay(1000);
	printf("enjoy\n");
	delay(1000);
	/* This is the end of the user friendly section  */

	printf("Please enter the values for A[0..2][0..2], one row per line:\n");
    scannerLoop(A);
	printf("Please enter the values for B[0..2][0..2], one row per line:\n");
	scannerLoop(B);
	printf("A=\n");
	matrixPrinter(A);
	printf("B=\n");
	matrixPrinter(B);
  int i, j, k;
  /* multiply C = A.B: */
  
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			C[i][j] = 0;
			for (k =0; k < 3; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

  printf("C=A.B=\n");
  matrixPrinter(C);
  /* multiply C = B.A: */
  
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			C[i][j] = 0;
			for (k =0; k < 3; k++){
				C[i][j] += B[i][k] * A[k][j];
			}
		}
    }
  printf("C=B.A=\n");
  matrixPrinter(C);
}

