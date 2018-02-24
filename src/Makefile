CXX = clang++

run: bin/main.o bin/cir2.o bin/distributions.o bin/plots.o
	g++ bin/main.o bin/cir2.o bin/distributions.o bin/plots.o -o run

bin/main.o: main.cpp
	g++ -c main.cpp -o bin/main.o

bin/cir2.o: cir2.hpp cir2.cpp
	g++ -c cir2.cpp -o bin/cir2.o

bin/distributions.o: distributions.hpp distributions.cpp
	g++ -c distributions.cpp -o bin/distributions.o

bin/plots.o: plots.hpp plots.cpp
	g++ -c plots.cpp -o bin/plots.o
