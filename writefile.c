/**
 * C program to create a file and write data into file.
 */

#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 1000

int main()
{
    /* Variable to store user content */
    char data[DATA_SIZE];

    /* File pointer to hold reference to our file */
    FILE * fPtr;


    /*
     * Open file in w (write) mode.
     */
    fPtr = fopen("data/fishes_and_sharks.c.txt", "w");


    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }


/*-------------------------------------------------------------------*/


    /* Input contents from user to store in file */
    printf("Enter contents to store in file : \n");
    fgets(data, DATA_SIZE, stdin);

    for(int i = 0; i < 200; i++)
    {

		for (int k = 1; k < OCEAN_ROW_SIZE - 1; k++) {
		  for (int l = 1; l < OCEAN_COLUMN_SIZE - 1; l++) {
			/* Write data to file */
			fputs(ocean[k],fptr);
			fputs(ocean[l],fptr);

		  }
		}
	 }



	{

    /* Close file to save file data */
    fclose(fPtr);

    return 0;
}
