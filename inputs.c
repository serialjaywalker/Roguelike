#include <ncurses.h>

//external variable from engine
extern volatile unsigned char buttflag;

void pollbutts(){
		unsigned char currchar=0;
		unsigned char i=0;
		
		for(i=0; i<10; i++)	{
			timeout(20);
			currchar = getch();
					//using "wasd" because arrow key codes vary between systems
			switch(currchar){
				case 'w': //up
					buttflag |= 0x01;
					break;
				case 'a': //left
					buttflag |= 0x02;
					break;
				case 's': //down
					buttflag |= 0x04;
					break;
				case 'd': //right
					buttflag |= 0x08;
					break;
				case ' ': //"action 1"
					buttflag |= 0x10;
					break;
				case 'f': //"action 2"
					buttflag |= 0x20;
					break;
				default:
					break;
			}
		}
}
