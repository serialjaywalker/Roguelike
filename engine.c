#include "map.h"
volatile unsigned char buttflag=0;
enum directions {up, left, right, down, LU, LD, RU, RD, stay};

unsigned char readflags(){
	unsigned char w, a, s, d;
	w=(buttflag&0x01)==0x01; s=(buttflag&0x04)==0x04;
	a=(buttflag&0x02)==0x02; d=(buttflag&0x08)==0x08;
	buttflag=0;
	//takes in flags for buttons then clears them
	//TODO: simplify code
	if( w && !s ){ 
		if(a && !d ){ 
			return LU; //diag left up
		}
		else if( d && !a ){ 
			return RU; //diag right up
		}
		else{
			return up; 
		}
	}
	else if( s && !w ){ 
		if( a && !d ){ 
			return LD; //diag left down
		}
		else if( d && !a ){ 
			return RD; //diag right down
		}
		else{
			return down;
		}
	}
	else if( a && !d ){ 
		return left;
	}
	else if( d && !a ){ 
		return right;
	}
	
	return stay;
}


void movechar(map* curr){
	char direction = readflags();
	unsigned int y = curr->playerpos[0], x = curr->playerpos[1];
	switch(direction){
		case stay:
			break;
		case up:
			if(curr->content[y-1][x]==floor){
				curr->content[y-1][x]=player_cell;
				curr->content[y][x]=floor;
				curr->playerpos[0]=y-1; curr->playerpos[1]=x;
			}
			break;
		case left:
			if(curr->content[y][x-1]==floor){
				curr->content[y][x-1]=player_cell;
				curr->content[y][x]=floor;
				curr->playerpos[0]=y; curr->playerpos[1]=x-1;
			}
			break;
		case right:
			if(curr->content[y][x+1]==floor){
				curr->content[y][x+1]=player_cell;
				curr->content[y][x]=floor;
				curr->playerpos[0]=y; curr->playerpos[1]=x+1;
			}
			break;
		case down:
			if(curr->content[y+1][x]==floor){
				curr->content[y+1][x]=player_cell;
				curr->content[y][x]=floor;
				curr->playerpos[0]=y+1; curr->playerpos[1]=x;
			}
			break;
		case LU:
			if(curr->content[y-1][x-1]==floor){
				curr->content[y-1][x-1]=player_cell;
				curr->content[y][x]=floor;
				curr->playerpos[0]=y-1; curr->playerpos[1]=x-1;
			}
			break;
		case LD:
			if(curr->content[y+1][x-1]==floor){
				curr->content[y+1][x-1]=player_cell;
				curr->content[y][x]=floor;
				curr->playerpos[0]=y+1; curr->playerpos[1]=x-1;
			}
			break;
		case RU:
			if(curr->content[y-1][x+1]==floor){
				curr->content[y-1][x+1]=player_cell;
				curr->content[y][x]=floor;
				curr->playerpos[0]=y-1; curr->playerpos[1]=x+1;
			}
			break;
		case RD:
			if(curr->content[y+1][x+1]==floor){
				curr->content[y+1][x+1]=player_cell;
				curr->content[y][x]=floor;
				curr->playerpos[0]=y+1; curr->playerpos[1]=x+1;
			}
			break;
		default:
			break;
	}
	
}

static enum statetick {board_update, get_input, display_board,init} 
gamestate;
void gametick(){
		switch(gamestate){
			default:
			break;
		}//transitions
		
		switch(gamestate){
			default:
			break;
		}//actions
	
	
}
