CC = gcc 
CFLAGS = -O2 -lm

test: main.cpp
	g++ main.cpp -O2
	./a.out "penis" testando.txt
	./a.out "p" testando.txt
	./a.out "a" testando.txt
	./a.out "Diabo" igrejadodiabo.txt
