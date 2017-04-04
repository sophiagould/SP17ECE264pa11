#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pa11.h"
#include <ctype.h>


int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa11 <input file>\n");		
		return EXIT_FAILURE;
	}

	float result; //store the result of your calculation here.
	int error;

	StackNode ** stack = malloc(sizeof(StackNode));
	
	result = solver(argv[1], stack, &error);
	if(error == 1){
		fprintf(stderr, "Unsolvable list\n");
		return EXIT_FAILURE;
	}

	printf("%f\n", result);	
	return EXIT_SUCCESS;
}
