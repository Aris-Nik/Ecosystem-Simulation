all: Project

Project : main.o Animal.o Ecosystem.o Plant.o Terrain.o Tile.o Herbivore.o Carnivore.o
	g++ main.o Animal.o Ecosystem.o Plant.o Terrain.o Tile.o Herbivore.o Carnivore.o -o Project
main.o : main.cpp class.h
	g++ -c main.cpp
Animal.o : Animal.cpp class.h
	g++ -c Animal.cpp
Ecosystem.o : Ecosystem.cpp class.h
	g++ -c Ecosystem.cpp
Plant.o : Plant.cpp class.h
	g++ -c Plant.cpp
Terrain.o : Terrain.cpp class.h
	g++ -c Terrain.cpp
Tile.o : Tile.cpp class.h
	g++ -c Tile.cpp
Herbivore.o : Herbivore.cpp class.h
	g++ -c Herbivore.cpp
Carnivore.o : Carnivore.cpp class.h
	g++ -c carnivore.cpp

clean:
	rm -rf *o Project

