#include <stdio.h>
#include "map.h"
#include "entities.h"

void display(map *curr, unsigned int region){
	//display region around the player
	
	//step 1: find player_pos
	
	//step 2: output +-region/2 around player
}

void showmap(map *curr){
	//simply display entire map
	unsigned int i, j;
	for(i=0;i<curr->ysize;i++){
		for(j=0;j<curr->xsize;j++){
			printf("%d",curr->content[i][j]);
		}
		printf("\n");
	}
}
