#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// header files for time output
#include <time.h>
#include <string.h>
// END

#include "functions.h"

int main(int argc, char *argv[]) {
  printf("Welcome to fishes and sharks.\n");

  // Create pointer to thread array
  pthread_t *thread_handles;
  thread_handles = malloc(THREAD_COUNT * sizeof(pthread_t));

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

  // Run initial population on main thread (single threaded)
  initialPopulation();
  //Print_matrix("O");


  time_t mytime = time(NULL);
  char * time_str = ctime(&mytime);
  time_str[strlen(time_str) - 1] = '\0';
  printf("Current time: %s\n", time_str);

  // Loop through each generation
  for (int currentGeneration = 0; currentGeneration < TARGET_GENERATIONS; currentGeneration++) {
    printf("Processing generation: %d.\n", currentGeneration);

    // Loop through each cell, in order to process rules
    // Dont process boundary cells (for now)
    // Start a block of threads (10)
    for (int currentRow = 1; currentRow < OCEAN_ROW_SIZE - 1; currentRow = currentRow + THREAD_COUNT) {

    // TODO, uncomment when boundary rows are being processed
    // for (int currentRow = 0; currentRow < OCEAN_ROW_SIZE; currentRow = currentRow + THREAD_COUNT) {

      // Start all 10 threads
      for (long i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&thread_handles[i], NULL, processOceanRow, (void *) (i + currentRow));
      }

      // Wait for all 10 threads to finish
      for (long i = 0; i < THREAD_COUNT; i++) {
        pthread_join(thread_handles[i], NULL);
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

  mytime = time(NULL);
  time_str = ctime(&mytime);
  time_str[strlen(time_str) - 1] = '\0';
  printf("Current time: %s\n", time_str);

  free(thread_handles);

  //Print_matrix("O");
  return 0;
}
