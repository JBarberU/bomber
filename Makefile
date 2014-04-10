default:
	g++ -c -std=c++11 bomber.cpp
	g++ bomber.o -o bomber -lsfml-graphics -lsfml-window -lsfml-system
