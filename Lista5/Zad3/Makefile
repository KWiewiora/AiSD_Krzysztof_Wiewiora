main: main.o
	g++ -fno-stack-protector -o main main.o
	./main

main.o: main.cpp
	g++ -fno-stack-protector -std=c++17  -c -g -o main.o main.cpp 
