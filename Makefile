HEADERS = map.h entities.h display.h
OBJECTS = main.o map.o display.o engine.o inputs.o

default: $(OBJECTS) $(HEADERS)
	gcc $(OBJECTS) -lncurses -o  rogue.exe

rogue: $(OBJECTS) $(HEADERS)
	gcc $(OBJECTS) -lncurses -o  rogue.exe
	rm -f *.o

main.o: main.c
	gcc -c main.c
	
map.o: map.c
	gcc -c map.c 
	
display.o: display.c
	gcc -c display.c 
	
engine.o: engine.c
	gcc -c engine.c

inputs.o: inputs.c
	gcc -c inputs.c 


clean:
	-rm -f *.o
	-rm -f *.exe
