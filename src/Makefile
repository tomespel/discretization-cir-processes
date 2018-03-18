CXX = clang++

run: bin/main.o bin/cir2.o bin/distributions.o bin/plots.o bin/heston.o bin/monte_carlo.o bin/exact_values.o bin/schemes.o
	g++ bin/main.o bin/cir2.o bin/distributions.o bin/plots.o bin/heston.o bin/monte_carlo.o bin/exact_values.o bin/schemes.o -o run -std=c++11

bin/main.o: main.cpp
	g++ -c main.cpp -o bin/main.o -std=c++11

bin/cir2.o: cir2.hpp cir2.cpp
	g++ -c cir2.cpp -o bin/cir2.o -std=c++11

bin/distributions.o: distributions.hpp distributions.cpp
	g++ -c distributions.cpp -o bin/distributions.o -std=c++11

bin/plots.o: plots.hpp plots.cpp
	g++ -c plots.cpp -o bin/plots.o -std=c++11

bin/heston.o: heston.hpp heston.cpp
	g++ -c heston.cpp -o bin/heston.o -std=c++11

bin/monte_carlo.o: monte_carlo.hpp monte_carlo.cpp
	g++ -c monte_carlo.cpp -o bin/monte_carlo.o -std=c++11

bin/exact_values.o: exact_values.hpp exact_values.cpp
	g++ -c exact_values.cpp -o bin/exact_values.o -std=c++11

bin/schemes.o: schemes.hpp schemes.cpp
	g++ -c schemes.cpp -o bin/schemes.o -std=c++11

clean:
	rm -f bin/*.o
	rm -f paths_cir2.csv
	rm -f run
