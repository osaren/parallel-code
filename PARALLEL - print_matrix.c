#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

extern int ocean[OCEAN_ROW_SIZE][OCEAN_COLUMN_SIZE];
/*-------------------------------------------------------------------
 * Function:   Print_matrix
 * Purpose:    Print a matrix to stdout
 * In args:    title:  title for output
 */
void Print_matrix(
                  char    title[]  /* in */) {
   int i, j;

   printf("\nThe matrix %s\n", title);
   for (i = 0; i < OCEAN_ROW_SIZE; i++) {
      for (j = 0; j < OCEAN_COLUMN_SIZE; j++) {
         printf("%d ", ocean[i][j]);
      }
      printf("\n");
   }
}  /* Print_matrix */
