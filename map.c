#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "map.h"
#include "entities.h"



void mapgen(map *curr, unsigned int x, unsigned int y){
	unsigned int i=0;
	if( (x == 0) || (y == 0) ){
		fprintf(stderr, "Error: called generation of size 0\n");
		exit(EXIT_FAILURE);
	}
	
	//allocate dynamic array
	curr->content = malloc(y * sizeof(char *));
	for(i=0; i<y; i++){
		curr->content[i] = malloc(x * sizeof(char));
	}
	
	//set size variables in struct
	curr->xsize = x;
	curr->ysize = y;
}

void mapfree(map *curr){
	unsigned int i=0;
	
	//free dynamic array
	for(i=0; i<curr->ysize; i++){
		free(curr->content[i]);
	}
	free(curr->content);
	
	//set size variables in struct
	curr->xsize = 0;
	curr->ysize = 0;
}


void roomgen(map *curr){
	srand(time(NULL)); //replace with time(NULL) later
	unsigned int i=0, j=0;
	
	//make sure each tile is a floor
	for(i=1;i<curr->ysize;i++){
		for(j=1;j<curr->xsize;j++){
			curr->content[i][j] = floor;
		}
	}
	//fill borders with walls
	for(i=0; i<curr->xsize; i++){
		curr->content[0][i]=wall; //top
		curr->content[curr->ysize-1][i]=wall; //bottom
	}
	for(i=1; i<curr->ysize-1; i++){ 
		curr->content[i][0]=wall; //left
		curr->content[i][curr->xsize-1]=wall; //right
	}
	
	//step 3: do smart things to put rooms 
	//step 4: place player randomly, but only on floor cells
	do {
		curr->playerpos[0] = (rand() % (curr->ysize-2))+1; //set player y
		curr->playerpos[1] = (rand() % (curr->xsize-2))+1; //set player x
	} while(curr->content[curr->playerpos[0]][curr->playerpos[1]] != floor);
	curr->content[curr->playerpos[0]][curr->playerpos[1]] = player_cell;
	
}
