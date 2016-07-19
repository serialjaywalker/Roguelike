#ifndef MAP_H
#define MAP_H

enum celltypes { /*defines types of objects to fill map*/
		floor,
		wall,
		player_cell,
		item_drop,
		enemy_spawn,
};

typedef struct map {
	//Struct that holds game board
	int level;
	unsigned int xsize, ysize;
	char **content;
	unsigned int playerpos[2];
} map;


#endif
