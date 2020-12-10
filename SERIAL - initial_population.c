#define OCEAN_ROW_SIZE 1000
#define OCEAN_COLUMN_SIZE 1000
#define TARGET_GENERATIONS 20000

#include <stdio.h>
#include <stdlib.h>

extern int ocean[OCEAN_ROW_SIZE][OCEAN_COLUMN_SIZE];
extern int futureOcean[OCEAN_ROW_SIZE][OCEAN_COLUMN_SIZE];
extern int shark;
extern int fish;
extern int empty;

void initialPopulation() {
  // Outter for loop, responible for walking down the rows in the 2D array
  // from top to bottom
  // 50% empty
  printf("Populating ocean with empty cells.\n");
  for (int i = 0; i < OCEAN_ROW_SIZE; i++) {
    // Inner for loop, responible for walking across columns in the 2D array
    // from left to right
    for (int j = 0; j < OCEAN_COLUMN_SIZE; j++) {
      ocean[i][j] = empty;
    }
  }

  // 25% fish
  printf("Populating ocean with fishes.\n");
  for(int i = 0; i < OCEAN_ROW_SIZE; i++) {
    for(int j = 1; j < OCEAN_COLUMN_SIZE; j += 2) {
      float min = 1.0;
      float max = 10.0;
      float scale = (float) rand() / (float) RAND_MAX;
      ocean[i][j] = (int) min + scale * (max - min);
    }
  }

  // 25% sharks
  printf("Populating ocean with sharks.\n");
  for(int i = 0; i < OCEAN_ROW_SIZE; i++) {
    for(int j = 0; j < OCEAN_COLUMN_SIZE; j += 4) {
      float min = -20.0;
      float max = -1.0;
      float scale = (float) rand() / (float) RAND_MAX;
      ocean[i][j] = (int) min + scale * (max - min);
    }
  }
  printf("Finished populating initial state of ocean.\n");
  // ocean has been populated with empty cells, fishes and sharks.
}
