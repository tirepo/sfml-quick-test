all:
	g++ main.cpp main.hpp -o compiled_lol -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm compiled_lol