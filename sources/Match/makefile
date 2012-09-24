all: match

match: main.o
	g++ main.o -o ../../Match

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *o ../../Match
