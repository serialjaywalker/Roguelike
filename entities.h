#ifndef ENTITIES_H
#define ENTITIES_H

typedef struct enemy {
	
} enemy;

typedef struct player {
	unsigned char health;
} player;


typedef struct item{
	unsigned char ID, stackability;
	unsigned short quantity;
} item;


typedef struct inventory{
	item slot[30];
	char numitems;
	char cap;
} inventory;

#endif
