  
fishes_and_sharks: fishes_and_sharks.c initial_population.o plot_ocean.o
	gcc fishes_and_sharks.c initial_population.o plot_ocean.o -o fishes_and_sharks

initial_population.o: initial_population.c
	gcc -c initial_population.c
	
plot_ocean.o: plot_ocean.c
	gcc -c plot_ocean.c
