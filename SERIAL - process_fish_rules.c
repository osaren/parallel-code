#include <stdio.h>

void processFishRules(int *current, int *neighbours, int amountOfNeighbours) {
  // process fish rules

  // Declare variables
  // These variables will count how many neighbors are fish/sharks
  int sharkNeighbours = 0;
  int fishNeighbours = 0;

  // Loop over the neighbors array
  // so we can count how many neighbors are sharks/fish
  for (int j = 0; j < amountOfNeighbours; j++){
    // if neighbour is shark
    if (neighbours[j] <= -1) { // neighbour is shark
      sharkNeighbours++;
    } else if (neighbours[j] >= 1) { // neighbour is fish
      fishNeighbours++;
    }
  }

  // is fish too old
  if (*current >= 10) {
    *current = 0; // kill fish due to age
  } else if (sharkNeighbours >= 5){
    //printf("fish is overcrowded");
    *current = 0; // kills the fish, due to predators
  } else if (fishNeighbours >= 8) {
    *current = 0; // kills the fish, due to overcrowding
  } else {
    *current = *current + 1;
  }
}

