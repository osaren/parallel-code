void processBreedingRules(int *current, int *neighbours) {
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
    *current = -1;
  } else if (fishNeighbours >= 4 && sharkNeighbours < 4 && fishesOfBreedingAge >= 3) {
    // breed a fish
    *current = 1;
  }
}
