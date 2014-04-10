default:
	g++ -c -std=c++11 sfml_test.cpp
	g++ sfml_test.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
