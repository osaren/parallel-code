#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void* processOceanRow(void *row) {

  // Cast provided row to a long
  long my_row = (long) row;

  // Start to walk across all the columns in ocean, for provided row
  for (int currentColumn = 0; currentColumn < OCEAN_COLUMN_SIZE; currentColumn++) {

    // get current
    int current = ocean[my_row][currentColumn];

    // get all the current cells neighbours
    int *neighbours; // Populated inside getNeighbours()
    int amountOfNeighbours; // Populated inside getNeighbours()

    // getNeighbours returns the populated neighbours pointer
    // assign that returned neighbours to our local neighbours pointer
    neighbours = getNeighbours(my_row, currentColumn, neighbours, &amountOfNeighbours);

    // process rules
    if (current <= -1) { // this is a shark
      // processSharkRules(-20, [20, 10, 0, -5, -3 ..]);
      processSharkRules(&current, neighbours, amountOfNeighbours);
      // processSharkRules(&current, neighbours, amountOfNeighbours);
    } else if(current >= 1){ // this is a fish
      processFishRules(&current, neighbours, amountOfNeighbours);
    } else if(current == 0) { // this is empty
      processBreedingRules(&current, neighbours, amountOfNeighbours);
    }


    // put new value into futureOcean, at the same position
    futureOcean[my_row][currentColumn] = current;
  }

  return NULL;
}








