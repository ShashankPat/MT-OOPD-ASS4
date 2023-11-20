all: debug optimize

debug: main_debug

main_debug: main.cpp
	g++ -g -o main_debug main.cpp
	./main_debug

optimize: main_optimize

quart_optimize: main.cpp
	g++ -O3 -o main_optimize main.cpp
	./main_optimize

clean:
	rm -f main_debug main_optimize