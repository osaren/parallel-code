#include <stdlib.h>

void processSharkRules(int *current, int *neighbours, int amountOfNeighbours) {

  // process shark rules

  // Declare variables
  // These variables will count how many neighbors are fish/sharks
  int sharkNeighbours = 0;
  int fishNeighbours = 0;

  // Loop over the neighbors array
  // so we can count how many neighbors are sharks/fish
  for (int j = 0; j < amountOfNeighbours; j++) {
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
    *current = 0; // kills the shark randomly
  } else {
    if (*current <= -20) { // if shark is older than -20
      //printf("Shark is too old");
      *current = 0; // kills the shark, due to age
    } else if (sharkNeighbours >= 6 && fishNeighbours == 0){
      //printf("Shark is overcrowded");
      *current = 0; // kills the shark, due to starvation
    } else {
      // Age the shark, -19 -> -20
      *current = *current - 1;
    }
  }

  // we've processed the shark rules for current
  // and we know what value current will become in the next generation

}
