#define OCEAN_ROW_SIZE 1000
#define OCEAN_COLUMN_SIZE 1000
#define TARGET_GENERATIONS 20000

#include <stdio.h>
#include <stdlib.h>
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
  plotOcean();


  // Loop through each generation
  for (int currentGeneration = 0; currentGeneration < TARGET_GENERATIONS; currentGeneration++) {
    printf("Processing generation: %d.\n", currentGeneration);

    // Loop through each cell, in order to process rules
    // Dont process boundary cells (for now)
    for (int currentRow = 1; currentRow < OCEAN_ROW_SIZE - 1; currentRow++) {
      for (int currentColumn = 1; currentColumn < OCEAN_COLUMN_SIZE - 1; currentColumn++) {

        // TODO create a new thread
        // each thread, will process a single row from the ocean
        // only 5 threads running at a time

        // get current
        int current = ocean[currentRow][currentColumn];

        // get all the current cells neighbours
        // Doesn't take into consideration boundary cells (for now)
        int neighbours[8];
        neighbours[0] = ocean[currentRow - 1][currentColumn - 1];
        neighbours[1] = ocean[currentRow - 1][currentColumn];
        neighbours[2] = ocean[currentRow - 1][currentColumn + 1];
        neighbours[3] = ocean[currentRow][currentColumn - 1];
        neighbours[4] = ocean[currentRow][currentColumn + 1];
        neighbours[5] = ocean[currentRow + 1][currentColumn - 1];
        neighbours[6] = ocean[currentRow + 1][currentColumn];
        neighbours[7] = ocean[currentRow + 1][currentColumn + 1];
        // neighbours = {1, 5, 0, 6, -8, 2, -5, 1}

        // process rules
        if (current <= -1) {

          // process shark rules

          // Declare variables
          // These variables will count how many neighbors are fish/sharks
          int sharkNeighbours = 0;
          int fishNeighbours = 0;

	        // Loop over the neighbors array
          // so we can count how many neighbors are sharks/fish
          for (int j = 0; j < 8; j++){
            // if neighbour is shark
            if (neighbours[j] <= -1) { // neighbour is shark
              sharkNeighbours++;
            } else if (neighbours[j] >= 1) { // neighbour is fish
              fishNeighbours++;
            }
          }
          // sharkNeighbours = 6
          // fishNeighbours = 0

          // should randomly die (0.031 chance of dying)
          float min = 0.0;
          float max = 100.0;
          float scale = (float) rand() / (float) RAND_MAX;
          float randomChanceOfDeath = min + scale * (max - min);
          if (randomChanceOfDeath < 0.031) {
            current = 0; // kills the shark randomly
          } else {
            if (current <= -20) { // if shark is older than -20
              //printf("Shark is too old");
              current = 0; // kills the shark, due to age
            } else if (sharkNeighbours >= 6 && fishNeighbours == 0){
              //printf("Shark is overcrowded");
              current = 0; // kills the shark, due to starvation
            } else {
              current++;
            }
          }

          // we've processed the shark rules for current
          // and we know what value current will become in the next generation

        } else if(current >= 1){ // this is a fish
          // process fish rules

          // Declare variables
          // These variables will count how many neighbors are fish/sharks
          int sharkNeighbours = 0;
          int fishNeighbours = 0;

	        // Loop over the neighbors array
          // so we can count how many neighbors are sharks/fish
          for (int j = 0; j < 8; j++){
            // if neighbour is shark
            if (neighbours[j] <= -1) { // neighbour is shark
              sharkNeighbours++;
            } else if (neighbours[j] >= 1) { // neighbour is fish
              fishNeighbours++;
            }
          }

          // is fish too old
          if (current >= 10) {
            current = 0; // kill fish due to age
          } else if (sharkNeighbours >= 5){
            //printf("fish is overcrowded");
            current = 0; // kills the fish, due to predators
          } else if (fishNeighbours >= 8) {
            current = 0; // kills the fish, due to overcrowding
          } else {
            current++;
          }

        } else if(current == 0) { // this is empty
          // process breeding rules

          // Declare variables
          // These variables will count how many neighbors are fish/sharks
          int sharkNeighbours = 0;
          int sharksOfBreedingAge = 0;
          int fishNeighbours = 0;
          int fishesOfBreedingAge = 0;

	        // Loop over the neighbors array
          // so we can count how many neighbors are sharks/fish
          for (int j = 0; j < 8; j++){
            // if neighbour is shark
            if (neighbours[j] <= -1) { // neighbour is shark
              sharkNeighbours++;

              // check if shark neighbour is of a breeding age
              if (neighbours[j] <= -3) {
                // if so, increment counter
                sharksOfBreedingAge++;
              }

            } else if (neighbours[j] >= 1) { // neighbour is fish
              fishNeighbours++;

              // check if fish neighbour is of a breeding age
              if (neighbours[j] >= 2) {
                fishesOfBreedingAge++;
              }
            }
          }

          if (sharkNeighbours >= 4 && fishNeighbours < 4 && sharksOfBreedingAge >= 3) {
            // breed a shark
            current = -1;
          } else if (fishNeighbours >= 4 && sharkNeighbours < 4 && fishesOfBreedingAge >= 3) {
            // breed a fish
            current = 1;
          }
        }

        // put new value into futureOcean, at the same position
        futureOcean[currentRow][currentColumn] = current;
      }
    }

    // all cells have been processed for current generation

    // overwrite ocean values with futureOcean values

    //updateOceanFromFuture();
    for (int k = 1; k < OCEAN_ROW_SIZE - 1; k++) {
      for (int l = 1; l < OCEAN_COLUMN_SIZE - 1; l++) {
        ocean[k][l] = futureOcean[k][l];
      }
    }
  }

  return 0;
}
