HEADERS = map.h entities.h display.h
OBJECTS = main.o map.o display.o engine.o

default: $(OBJECTS) $(HEADERS)
	gcc $(OBJECTS) -o rogue.exe

rogue: $(OBJECTS) $(HEADERS)
	gcc $(OBJECTS) -o rogue.exe
	rm -f *.o

main.o: main.c
	gcc -c main.c
	
map.o: map.c
	gcc -c map.c 
	
display.o: display.c
	gcc -c display.c 
	
engine.o: engine.c
	gcc -c engine.c


clean:
	-rm -f *.o
	-rm -f *.exe
