/*
 * main.c
 * 
 * Copyright 2016 Joseph <joseph@cyborg>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include "map.h"
#include "entities.h"
#include "display.h"
#include "ncurses.h"


int main()
{
	
	initscr();
	raw();
	cbreak();
	noecho();
	
	//test harness for modules/tasks
	printw("declaring map\n"); refresh();
	map firstmap;
	printw("generating map\n"); refresh();
	mapgen(&firstmap, 20, 10);
	printw("generating rooms\n"); refresh();
	roomgen(&firstmap);
	printw("Press key to display map\n"); refresh();
	getch();
	clear();
	show_map(&firstmap);
	printw("\nplayer pos: x=%d y=%d\n", firstmap.playerpos[1],firstmap.playerpos[0]);
	refresh();
	
	while(1){
		pollbutts();
		movechar(&firstmap);
		show_map(&firstmap);
		printw("\nplayer pos: x=%d y=%d\n", firstmap.playerpos[1],firstmap.playerpos[0]);
		
	}
	//printf("Ackermann's for funsies when m>=3\n");
	//dispack();
	
	printw("freeing map\n");
	mapfree(&firstmap);
	endwin();
	return 0;
}

