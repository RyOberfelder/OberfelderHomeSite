/* Example: bubble sort values in array */

/* The bubble sort works by comparing values in adjacent
array positions. If the value in the "lower" position is 
greater than that in the "higher" position, the two are 
swapped. Thus the largest value "bubbles up" to the "top" 
of the array. When there are no more values to be swapped, 
sorting is complete. */

#include <stdio.h>

#define VALS 10 /* The number of values to be sorted */

main()
{
  int i, sorted; 
  int swaps = 0;
  int loops = 0;
  float x[VALS], temp;
  
  /* This is the start of the user friendly section  */
	printf("This program is a number sorting program\n");
	delay(2000);
	printf("Note that the program also counts the number of swaps perfomed in sort\n");
	delay(2000);
	printf("The loops mean the number of times the program looped through\n");
	delay(1000);
	printf("The program will stop after the %d values are entered then sorted\n", VALS);
	delay(1000);
	printf("enjoy\n");
	delay(1000);
	/* This is the end of the user friendly section  */
  
  /* Input values: */
  
  printf("Enter %i floating point values:\n", VALS);
  for (i = 0; i < VALS; i++)
  { printf("#%i: ", i + 1);
    scanf("%f", &x[i]);
  }
  
  /* Bubble sort: */
  
  do {
       for (i = 1, sorted = 1; i < VALS; i++)
       {
         if (x[i-1] > x[i])
         {
           sorted = 0;
           temp = x[i-1];
           x[i-1] = x[i];
           x[i] = temp;
           swaps++;
         }
       }
	   loops++;
     } while (!sorted);
  
  /* Output sorted values: */
  
  puts("\nIn ascending order, the values are:");     
  for (i = 0; i < VALS; i++)
    printf("%G\n", x[i]);
  printf("\n%d swaps and %d iterations were performed.\n", swaps, loops); 
}