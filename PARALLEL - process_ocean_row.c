#include <stdlib.h>
#include "functions.h"

void* getNeighbors(long my_row, currentColumn)
{   
     int *neighbours;
     int amountOfNeighbours;

    // inside getNeighbours
    // Based on my_row and currentColumn
    // Determine if boundary or not
    if(my_row == 1) // its a boundary cell - Row 1 (top row)
    {
      if(currentColumn == 1 || currentColumn = 20000)// [1][1] Top Left Corner cell [1][20000] Top Right Corner Cell - only 3 neighbors
      {
        amountOfNeighbours = 3; 
        *neighbors = malloc(sizeof(int[amountOfNeighbours]));
        if(currentColumn == 1) // gets the neighbors for the top left cell
        {
          *neighbours = {extern ocean[my_row][currentColumn+1], extern ocean[my_row+1][currentColumn], extern ocean[my_row+1][currentColumn+1]};
        }
        else if(currentColumn == 20000) // gets the neighbors for the top right cell
        {
          *neighbours = {extern ocean[my_row][currentColumn-1], extern ocean[my_row-1][currentColumn], extern ocean[my_row-1][currentColumn-1]};
        }
       }
      else 
      {
       amountOfNeighbours = 5;  // rest of the cells on row 1 have 5 neighbors
       *neighbours = malloc(sizeof(int[amountOfNeighbours]));
       *neighbours = {extern ocean[my_row][currentColumn-1], extern ocean [my_row][currentColumn+1], extern ocean [my_row+1][currentColumn-1], 
                      extern ocean [my_row+1][currentColumn], extern ocean[my_row+1][currentColumn+1]}; // gets the 5 neighbours for the rest of the cells on row 1
                      
      }
    }
    else if(my_row == 20000) // its a boundary cell - Bottom Row
    {
      if(currentColumn == 1 || currentColumn = 20000) // [20000][1] Bottom Left Corner cell. [20000][20000] Bottom Right Corner cell - only 3 neighbours
      {
        amountOfNeighbours = 3;
        *neighbours = malloc(sizeof(int[amountOfNeighbours]));
      }
      else 
      {
        amountOfNeighbours = 5; // rest of the cells on row 20000 have 5 neighbours
        *neighbours = malloc(sizeof(int[amountOfNeighbours]));
      }
    }
    else if(currentColumn == 1) // its  a boundary cell - Left most column
    {
     *amountOfNeighbours = 5; 
      *neighbours = malloc(sizeof(int[amountOfNeighbours]));
    }
    else if(currentColumn == 20000) // its a boundary cell - Right most column
    {
      amountOfNeighbours =5;
      *neighbours = malloc(sizeof(int[amountOfNeighbours]));
    }
    else // its not a boundary cell
    {
      amountOfNeighbours = 8;
      *neighbours = malloc(sizeof(int[amountOfNeighbours]));
    }
    // e.g has 3 neighbours, malloc on the pointer
    // so that neighbours becomes an array which can store 3 ints
    // and then get those neighbours and put into the array
  // TODO remove neighbours array that is hardcoded to 8 elements,
    // in favour of pointer
    // int *neighbours;
    // int *amountOfNeighbours;

  
}

void* processOceanRow(void *row) {

  // Cast provided row to a long
  long my_row = (long) row;

  // Start to walk across all the columns in ocean, for provided row
  for (int currentColumn = 1; currentColumn < OCEAN_COLUMN_SIZE - 1; currentColumn++) {

  // TODO, uncomment when boundary columns are being handled
  // for (int currentColumn = 0; currentColumn < OCEAN_COLUMN_SIZE; currentColumn++) {

    // get current
    int current = ocean[my_row][currentColumn];
    // ..
    // get all the current cells neighbours
    // Doesn't take into consideration boundary cells (for now)
    int neighbours[8];
    // TODO remove neighbours array that is hardcoded to 8 elements,
    // in favour of pointer
    // int *neighbours;
    // int *amountOfNeighbours;

    // TODO, remove once boundaries are being handled
    neighbours[0] = ocean[my_row - 1][currentColumn - 1];
    neighbours[1] = ocean[my_row - 1][currentColumn];
    neighbours[2] = ocean[my_row - 1][currentColumn + 1];
    neighbours[3] = ocean[my_row][currentColumn - 1];
    neighbours[4] = ocean[my_row][currentColumn + 1];
    neighbours[5] = ocean[my_row + 1][currentColumn - 1];
    neighbours[6] = ocean[my_row + 1][currentColumn];
    neighbours[7] = ocean[my_row + 1][currentColumn + 1];

    // neighbours = {1, 5, 0, 6, -8, 2, -5, 1}
    // TODO, replace code above
    // with a function
    // getNeighbours(my_row, currentColumn, neighbours, amountOfNeighbours)

    // inside getNeighbours
    // Based on my_row and currentColumn
    // Determine if boundary or not
    // e.g has 3 neighbours, malloc on the pointer
    // so that neighbours becomes an array which can store 3 ints
    // and then get those neighbours and put into the array








    // process rules
    if (current <= -1) { // this is a shark
      // processSharkRules(-20, [20, 10, 0, -5, -3 ..]);
      processSharkRules(&current, neighbours);
      // processSharkRules(&current, neighbours, amountOfNeighbours);
    } else if(current >= 1){ // this is a fish
      processFishRules(&current, neighbours);
    } else if(current == 0) { // this is empty
      processBreedingRules(&current, neighbours);
    }


    // put new value into futureOcean, at the same position
    futureOcean[my_row][currentColumn] = current;
  }

  return NULL;
}
