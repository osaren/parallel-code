#include <stdio.h>
#include <stdlib.h>

// Header files for time output
#include <time.h>
#include <string.h>
// END
 
#include "functions.h"

int main(int argc, char *argv[]) {
  printf("Welcome to fishes and sharks.\n");

  /*
   * Populate array with initial data (empty cells, fishes and sharks).
   *
   * 50% Fish
   * 25% Shark
   * 25% Empty
   * 1st step -> [0, 0, 0, 0, 0, 0, 0, 0] (Set all cells to be empty)
   * 2nd step -> [0, 1, 0, 1, 0, 1, 0, 1] (Every 2nd cell, set to be a fish)
   * 3rd step -> [-1, 1, 0, 1, -1, 1, 0, 1] (Every 4th cell, set to be a shark)
   */
  printf("numberOfRows: %d.\n", OCEAN_ROW_SIZE);
  printf("numberOfColumns: %d.\n", OCEAN_COLUMN_SIZE);

  initialPopulation();
  
  time_t mytime = time(NULL);
  char * time_str = ctime(&mytime);
  time_str[strlen(time_str) - 1] = '\0';
  printf("Current time: %s\n", time_str);

  // Loop through each generation
  for (int currentGeneration = 0; currentGeneration < TARGET_GENERATIONS; currentGeneration++) {
    printf("Processing generation: %d.\n", currentGeneration);

    // Loop through each cell, in order to process rules
    // Dont process boundary cells (for now)
    for (int currentRow = 0; currentRow < OCEAN_ROW_SIZE; currentRow++) {
      for (int currentColumn = 0; currentColumn < OCEAN_COLUMN_SIZE; currentColumn++) {

    // get current
    int current = ocean[currentRow][currentColumn];

    // get all the current cells neighbours
    int *neighbours; // Populated inside getNeighbours()
    int amountOfNeighbours; // Populated inside getNeighbours()

    int* getNeighbours(long currentRow, int currentColumn, int *neighbours, int *amountOfNeighbours) {
    // Based on my_row and currentColumn
    // Determine if boundary or not
    if (currentRow == 0) { // its a boundary cell - Row 0 (top row)

    // [0][0] Top Left Corner cell
    // [0][OCEAN_COLUMN_SIZE - 1] Top Right Corner Cell
    // - only 3 neighbours
    if (currentColumn == 0 || currentColumn == (OCEAN_COLUMN_SIZE - 1)) {

      *amountOfNeighbours = 3;
      neighbours = malloc(*amountOfNeighbours * sizeof(int));

      if(currentColumn == 0) { // gets the neighbors for the top left cell

        neighbours[0] = ocean[currentRow][currentColumn + 1];
        neighbours[1] = ocean[currentRow + 1][currentColumn];
        neighbours[2] = ocean[currentRow + 1][currentColumn + 1];

      } else if(currentColumn == (OCEAN_COLUMN_SIZE - 1)) { // gets the neighbors for the top right cell

        neighbours[0] = ocean[currentRow][currentColumn - 1];
        neighbours[1] = ocean[currentRow + 1][currentColumn];
        neighbours[2] = ocean[currentRow + 1][currentColumn - 1];

      }
    } else {

      *amountOfNeighbours = 5;  // rest of the cells on row 0 have 5 neighbors
      neighbours = malloc(*amountOfNeighbours * sizeof(int));

      // gets the 5 neighbours for the rest of the cells on row 0
      neighbours[0] = ocean[currentRow][currentColumn - 1];
      neighbours[1] = ocean[currentRow][currentColumn + 1];
      neighbours[2] = ocean[currentRow + 1][currentColumn - 1];
      neighbours[3] = ocean[currentRow + 1][currentColumn];
      neighbours[4] = ocean[currentRow + 1][currentColumn + 1];
    }

  } else if (currentRow == (OCEAN_ROW_SIZE - 1)) { // its a boundary cell - Bottom Row

    // [OCEAN_ROW_SIZE - 1][0] Bottom Left Corner cell.
    // [OCEAN_ROW_SIZE - 1][OCEAN_COLUMN_SIZE - 1] Bottom Right Corner cell
    // - only 3 neighbours
    if (currentColumn == 0 || currentColumn == (OCEAN_COLUMN_SIZE - 1)) {

      *amountOfNeighbours = 3;
      neighbours = malloc(*amountOfNeighbours * sizeof(int));

      // gets the neighbours for the bottom left corner cell
      if (currentColumn == 0) {

        neighbours[0] = ocean[currentRow - 1][currentColumn];
        neighbours[1] = ocean[currentRow - 1][currentColumn + 1];
        neighbours[2] = ocean[currentRow][currentColumn + 1];

      } else if(currentColumn == (OCEAN_COLUMN_SIZE - 1)) {
        // gets the neighbours for the bottom right corner cell
        neighbours[0] = ocean[currentRow][currentColumn - 1];
        neighbours[1] = ocean[currentRow - 1][currentColumn];
        neighbours[2] = ocean[currentRow - 1][currentColumn - 1];
      }

    } else {
      // rest of the cells on row OCEAN_ROW_SIZE - 1, have 5 neighbours
      *amountOfNeighbours = 5;
      neighbours = malloc(*amountOfNeighbours * sizeof(int));

      neighbours[0] = ocean[currentRow][currentColumn - 1];
      neighbours[1] = ocean[currentRow][currentColumn + 1];
      neighbours[2] = ocean[currentRow - 1][currentColumn - 1];
      neighbours[3] = ocean[currentRow - 1][currentColumn];
      neighbours[4] = ocean[currentRow - 1][currentColumn + 1];
    }

  } else if(currentColumn == 0 && currentRow != 0 && currentRow != (OCEAN_ROW_SIZE - 1)) {

    // its  a boundary cell -
    // Left most column AND not the top left or bottom left corner cell
    *amountOfNeighbours = 5;
    neighbours = malloc(*amountOfNeighbours * sizeof(int));

    neighbours[0] = ocean[currentRow - 1][currentColumn];
    neighbours[1] = ocean[currentRow - 1][currentColumn + 1];
    neighbours[2] = ocean[currentRow][currentColumn + 1];
    neighbours[3] = ocean[currentRow + 1][currentColumn];
    neighbours[4] = ocean[currentRow + 1][currentColumn + 1];

  } else if (currentColumn == (OCEAN_COLUMN_SIZE - 1) && currentRow != 0 && currentRow != (OCEAN_ROW_SIZE - 1)) {

    // its a boundary cell -
    // Right most column AND not the top right or bottom right corner cell
    *amountOfNeighbours = 5;
    neighbours = malloc(*amountOfNeighbours * sizeof(int));

    neighbours[0] = ocean[currentRow - 1][currentColumn - 1];
    neighbours[1] = ocean[currentRow - 1][currentColumn];
    neighbours[2] = ocean[currentRow][currentColumn - 1];
    neighbours[3] = ocean[currentRow + 1][currentColumn - 1];
    neighbours[4] = ocean[currentRow + 1][currentColumn];

  } else { // its not a boundary cell

    *amountOfNeighbours = 8;
    neighbours = malloc(*amountOfNeighbours * sizeof(int));

    neighbours[0] = ocean[currentRow - 1][currentColumn - 1];
    neighbours[1] = ocean[currentRow - 1][currentColumn];
    neighbours[2] = ocean[currentRow - 1][currentColumn + 1];
    neighbours[3] = ocean[currentRow][currentColumn - 1];
    neighbours[4] = ocean[currentRow][currentColumn + 1];
    neighbours[5] = ocean[currentRow + 1][currentColumn - 1];
    neighbours[6] = ocean[currentRow + 1][currentColumn];
    neighbours[7] = ocean[currentRow + 1][currentColumn + 1];
  }

  return neighbours;
}

        // process rules
        if (current <= -1) {
	  processSharkRules(&current, neighbours, amountOfNeighbours);
	} else if(current >= 1){
	  processFishRules(&current, neighbours, amountOfNeighbours);
	} else if(current == 0){
	  processBreedingRules(&current, neighbours, amountOfNeighbours);
	}
     
          
        // put new value into futureOcean, at the same position
        futureOcean[currentRow][currentColumn] = current;
      }
    }

    // all cells have been processed for current generation

    // overwrite ocean values with futureOcean values

    //updateOceanFromFuture();
    for (int k = 0; k < OCEAN_ROW_SIZE; k++) {
      for (int l = 0; l < OCEAN_COLUMN_SIZE; l++) {
        ocean[k][l] = futureOcean[k][l];
      }
    }
  }

  mytime = time(NULL);
  time_str = ctime(&mytime);
  time_str[strlen(time_str) - 1] = '\0';
  printf("Current time: %s\n", time_str);
  
  return 0;
}
