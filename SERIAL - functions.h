// Global variables
#define OCEAN_ROW_SIZE 400
#define OCEAN_COLUMN_SIZE 400
#define TARGET_GENERATIONS 200
#define EMPTY_CELL 0


int ocean[OCEAN_ROW_SIZE][OCEAN_COLUMN_SIZE]; // Declares an array, without any values
int futureOcean[OCEAN_ROW_SIZE][OCEAN_COLUMN_SIZE]; // Declares an array, without any values
// int ocean[2][2] = { // Example, of declaring a 2D array, and setting values
  // {1, 2}
  // {3, 4}
//   };

// Function declarations
void initialPopulation();
void Print_matrix(char *title);
void processSharkRules(int *current, int *neighbours, int amountOfNeighbours);
void processFishRules(int *current, int *neighbours, int amountOfNeighbours);
void processBreedingRules(int *current, int *neighbours, int amountOfNeighbours);
int* getNeighbours(long currentRow, int currentColumn, int *neighbours, int* amountOfNeighbours);
