#Program Name: Save Grandma
#Name: Helen Jiang
#Date: 3/15/18
#Program Description: makefile for all the classes, and main file for final project

output: main.o Board.o Car.o Game.o GrandmaHome.o Ground.o House.o Sally.o Space.o Start.o Tree.o Utility.o Menu.o
	g++ -std=c++11 main.o Board.o Car.o Game.o GrandmaHome.o Ground.o House.o Sally.o Space.o Start.o Tree.o Utility.o Menu.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Board.o: Board.cpp Board.hpp
	g++ -std=c++11 -c Board.cpp

Car.o: Car.cpp Car.hpp
	g++ -std=c++11 -c Car.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

GrandmaHome.o: GrandmaHome.cpp GrandmaHome.hpp
	g++ -std=c++11 -c GrandmaHome.cpp

Ground.o: Ground.cpp Ground.hpp
	g++ -std=c++11 -c Ground.cpp

House.o: House.cpp House.hpp
	g++ -std=c++11 -c House.cpp

Sally.o: Sally.cpp Sally.hpp	
	g++ -std=c++11 -c Sally.cpp

Space.o: Space.cpp Space.hpp 
	g++ -std=c++11 -c Space.cpp

Start.o: Start.cpp Start.hpp
	g++ -std=c++11 -c Start.cpp

Tree.o: Tree.cpp Tree.hpp
	g++ -std=c++11 -c Tree.cpp 

Utility.o: Utility.cpp Utility.hpp
	g++ -std=c++11 -c Utility.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp

clean:
	rm *.o output