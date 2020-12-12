#include <stdlib.h>
#include "functions.h"

int* getNeighbours(long my_row, int currentColumn, int *neighbours, int *amountOfNeighbours) {
  // Based on my_row and currentColumn
  // Determine if boundary or not
  if (my_row == 0) { // its a boundary cell - Row 0 (top row)

    // [0][0] Top Left Corner cell
    // [0][OCEAN_COLUMN_SIZE - 1] Top Right Corner Cell
    // - only 3 neighbours
    if (currentColumn == 0 || currentColumn == (OCEAN_COLUMN_SIZE - 1)) {

      *amountOfNeighbours = 3;
      neighbours = malloc(*amountOfNeighbours * sizeof(int));

      if(currentColumn == 0) { // gets the neighbors for the top left cell

        neighbours[0] = ocean[my_row][currentColumn + 1];
        neighbours[1] = ocean[my_row + 1][currentColumn];
        neighbours[2] = ocean[my_row + 1][currentColumn + 1];

      } else if(currentColumn == (OCEAN_COLUMN_SIZE - 1)) { // gets the neighbors for the top right cell

        neighbours[0] = ocean[my_row][currentColumn - 1];
        neighbours[1] = ocean[my_row + 1][currentColumn];
        neighbours[2] = ocean[my_row + 1][currentColumn - 1];

      }
    } else {

      *amountOfNeighbours = 5;  // rest of the cells on row 0 have 5 neighbors
      neighbours = malloc(*amountOfNeighbours * sizeof(int));

      // gets the 5 neighbours for the rest of the cells on row 0
      neighbours[0] = ocean[my_row][currentColumn - 1];
      neighbours[1] = ocean[my_row][currentColumn + 1];
      neighbours[2] = ocean[my_row + 1][currentColumn - 1];
      neighbours[3] = ocean[my_row + 1][currentColumn];
      neighbours[4] = ocean[my_row + 1][currentColumn + 1];
    }

  } else if (my_row == (OCEAN_ROW_SIZE - 1)) { // its a boundary cell - Bottom Row

    // [OCEAN_ROW_SIZE - 1][0] Bottom Left Corner cell.
    // [OCEAN_ROW_SIZE - 1][OCEAN_COLUMN_SIZE - 1] Bottom Right Corner cell
    // - only 3 neighbours
    if (currentColumn == 0 || currentColumn == (OCEAN_COLUMN_SIZE - 1)) {

      *amountOfNeighbours = 3;
      neighbours = malloc(*amountOfNeighbours * sizeof(int));

      // gets the neighbours for the bottom left corner cell
      if (currentColumn == 0) {

        neighbours[0] = ocean[my_row - 1][currentColumn];
        neighbours[1] = ocean[my_row - 1][currentColumn + 1];
        neighbours[2] = ocean[my_row][currentColumn + 1];

      } else if(currentColumn == (OCEAN_COLUMN_SIZE - 1)) {
        // gets the neighbours for the bottom right corner cell
        neighbours[0] = ocean[my_row][currentColumn - 1];
        neighbours[1] = ocean[my_row - 1][currentColumn];
        neighbours[2] = ocean[my_row - 1][currentColumn - 1];
      }

    } else {
      // rest of the cells on row OCEAN_ROW_SIZE - 1, have 5 neighbours
      *amountOfNeighbours = 5;
      neighbours = malloc(*amountOfNeighbours * sizeof(int));

      neighbours[0] = ocean[my_row][currentColumn - 1];
      neighbours[1] = ocean[my_row][currentColumn + 1];
      neighbours[2] = ocean[my_row - 1][currentColumn - 1];
      neighbours[3] = ocean[my_row - 1][currentColumn];
      neighbours[4] = ocean[my_row - 1][currentColumn + 1];
    }

  } else if(currentColumn == 0 && my_row != 0 && my_row != (OCEAN_ROW_SIZE - 1)) {

    // its  a boundary cell -
    // Left most column AND not the top left or bottom left corner cell
    *amountOfNeighbours = 5;
    neighbours = malloc(*amountOfNeighbours * sizeof(int));

    neighbours[0] = ocean[my_row - 1][currentColumn];
    neighbours[1] = ocean[my_row - 1][currentColumn + 1];
    neighbours[2] = ocean[my_row][currentColumn + 1];
    neighbours[3] = ocean[my_row + 1][currentColumn];
    neighbours[4] = ocean[my_row + 1][currentColumn + 1];

  } else if (currentColumn == (OCEAN_COLUMN_SIZE - 1) && my_row != 0 && my_row != (OCEAN_ROW_SIZE - 1)) {

    // its a boundary cell -
    // Right most column AND not the top right or bottom right corner cell
    *amountOfNeighbours = 5;
    neighbours = malloc(*amountOfNeighbours * sizeof(int));

    neighbours[0] = ocean[my_row - 1][currentColumn - 1];
    neighbours[1] = ocean[my_row - 1][currentColumn];
    neighbours[2] = ocean[my_row][currentColumn - 1];
    neighbours[3] = ocean[my_row + 1][currentColumn - 1];
    neighbours[4] = ocean[my_row + 1][currentColumn];

  } else { // its not a boundary cell

    *amountOfNeighbours = 8;
    neighbours = malloc(*amountOfNeighbours * sizeof(int));

    neighbours[0] = ocean[my_row - 1][currentColumn - 1];
    neighbours[1] = ocean[my_row - 1][currentColumn];
    neighbours[2] = ocean[my_row - 1][currentColumn + 1];
    neighbours[3] = ocean[my_row][currentColumn - 1];
    neighbours[4] = ocean[my_row][currentColumn + 1];
    neighbours[5] = ocean[my_row + 1][currentColumn - 1];
    neighbours[6] = ocean[my_row + 1][currentColumn];
    neighbours[7] = ocean[my_row + 1][currentColumn + 1];
  }

  return neighbours;
}
