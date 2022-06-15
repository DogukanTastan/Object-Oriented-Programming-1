all:hw4
	./hw4

hw4: main.o robot.o humanic.o optimusprime.o bulldozer.o robocop.o roomba.o 
	g++ main.o robot.o humanic.o optimusprime.o bulldozer.o robocop.o roomba.o -o hw4	
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
robot.o: robot.cpp
	g++ -std=c++11 -c robot.cpp
humanic.o: humanic.cpp
	g++ -std=c++11 -c humanic.cpp
optimusprime.o: optimusprime.cpp
	g++ -std=c++11 -c optimusprime.cpp
bulldozer.o: bulldozer.cpp
	g++ -std=c++11 -c bulldozer.cpp
robocop.o: robocop.cpp
	g++ -std=c++11 -c robocop.cpp
roomba.o: roomba.cpp
	g++ -std=c++11 -c roomba.cpp