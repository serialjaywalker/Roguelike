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


int ack(int m, int n)
{
    if (m == 0){
        return n+1;
    }
    else if((m > 0) && (n == 0)){
        return ack(m-1, 1);
    }
    else if((m > 0) && (n > 0)){
        return ack(m-1, ack(m, n-1));
    }
}
void dispack(){
	int i, j;
	for(i=3;1;i++){
		for(j=1;j < i*10;j++){
			printf("ack of m=%d n=%d gives %d\n",i,j,ack(i,j));
		}
	}
}

int main()
{
	//test harness for modules/tasks
	printf("declaring map\n");
	map firstmap;
	printf("generating map\n");
	mapgen(&firstmap, 10, 10);
	printf("generating rooms\n");
	roomgen(&firstmap);
	printf("displaying map\n");
	showmap(&firstmap);
	printf("freeing map\n");
	mapfree(&firstmap);
	
	printf("Ackermann's for funsies when m>=3\n");
	dispack();
	
	return 0;
}

