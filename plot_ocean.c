// ------ GUI PROGRAM

// constant vars
#define NUM_COMMANDS 2
#define OCEAN_ROW_SIZE 1000
#define OCEAN_COLUMN_SIZE 1000

#include <stdlib.h>
#include <stdio.h>

extern int ocean[OCEAN_ROW_SIZE][OCEAN_COLUMN_SIZE];
//extern int futureOcean[OCEAN_ROW_SIZE][OCEAN_COLUMN_SIZE];

void plotOcean()
{
	// variables defined/declared
    char * commandsForGnuplot[] = {"set title \"Fishes And Sharks\"", "plot 'data.temp'"};
	int i;
	int j;
	
	// fopen() is chooing to store the data in a temp file
    FILE * temp = fopen("data.temp", "w");
    
    // popen() Opens any interface where you can send commands to it
    // "-persistent" keeps the plot open even after the c program terminates
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    
    // for loop to get the rows and cols of the ocean() copied off initial_population.c 
    for (i=0; i < OCEAN_ROW_SIZE; i++)
    {
    	for (j = 0; j < OCEAN_COLUMN_SIZE; j++) {
    		//store the data temporary file
    		fprintf(temp, "%d\n", ocean[i][j]);
   		}
    }
	
	/*/ repeating the same for future ocean
    for (i=0; i < OCEAN_ROW_SIZE; i++)
    {
    	for (j = 0; j < OCEAN_COLUMN_SIZE; j++) {
    		fprintf(temp, "%d\n", futureOcean[i][j]);
   		}
    }*/

    for (i=0; i < NUM_COMMANDS; i++)
    {
    	//Send commands to gnuplot one by one(2)
    	fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
    	fflush(gnuplotPipe);
    }
}
