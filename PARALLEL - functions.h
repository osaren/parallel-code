// Global variables
#define THREAD_COUNT 1
#define OCEAN_ROW_SIZE 400
#define OCEAN_COLUMN_SIZE 400
#define TARGET_GENERATIONS 10000
#define EMPTY_CELL 0

extern int ocean[OCEAN_ROW_SIZE][OCEAN_COLUMN_SIZE]; // Declares an array, without any values
extern int futureOcean[OCEAN_ROW_SIZE][OCEAN_COLUMN_SIZE]; // Declares an array, without any values
// int ocean[2][2] = { // Example, of declaring a 2D array, and setting values
  // {1, 2}
  // {3, 4}
//   };

// Function declarations
void Print_matrix(char *title);
void initialPopulation();
void processSharkRules(int *current, int *neighbours, int amountOfNeighbours);
void processFishRules(int *current, int *neighbours, int amountOfNeighbours);
void processBreedingRules(int *current, int *neighbours, int amountOfNeighbours);
int* getNeighbours(long my_row, int currentColumn, int *neighbours, int *amountOfNeighbours);
void* processOceanRow(void *row);
