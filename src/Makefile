CXX = clang++

run: bin/main.o bin/cir2.o bin/distributions.o bin/plots.o
	g++ bin/main.o bin/cir2.o bin/distributions.o bin/plots.o -o run -std=c++11

bin/main.o: main.cpp
	g++ -c main.cpp -o bin/main.o -std=c++11

bin/cir2.o: cir2.hpp cir2.cpp
	g++ -c cir2.cpp -o bin/cir2.o -std=c++11

bin/distributions.o: distributions.hpp distributions.cpp
	g++ -c distributions.cpp -o bin/distributions.o -std=c++11

bin/plots.o: plots.hpp plots.cpp
	g++ -c plots.cpp -o bin/plots.o -std=c++11

clean:
	rm -f bin/*.o
	rm -f paths_cir2.csv
	rm -f run
