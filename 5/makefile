all:hw5
	./hw5

hw5: main.o gate.o input.o output.o And.o Or.o decoder.o flipflop.o Not.o writerClass.o
	g++ main.o gate.o input.o output.o And.o Or.o decoder.o flipflop.o Not.o writerClass.o -o hw5	
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
gate.o: gate.cpp
	g++ -std=c++11 -c gate.cpp
input.o: input.cpp
	g++ -std=c++11 -c input.cpp
output.o: output.cpp
	g++ -std=c++11 -c output.cpp
And.o: And.cpp
	g++ -std=c++11 -c And.cpp 
Or.o: Or.cpp
	g++ -std=c++11 -c Or.cpp 
decoder.o: decoder.cpp
	g++ -std=c++11 -c decoder.cpp
flipflop.o: flipflop.cpp
	g++ -std=c++11 -c flipflop.cpp
Not.o: Not.cpp
	g++ -std=c++11 -c Not.cpp 
writerClass.o:
	g++ -std=c++11 -c writerClass.cpp



