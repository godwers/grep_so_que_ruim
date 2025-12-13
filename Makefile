CC=g++
CPPFLAGS=-O2 -lm
BINARY=bgrep

build: main.cpp 
	$(CC) $(CPPFLAGS) main.cpp -o $(BINARY)

test: $(BINARY)
	./$(BINARY) "amigos" testando.txt
	./$(BINARY) "dia" testando.txt
	./$(BINARY) "a" testando.txt
	./$(BINARY) "Diabo" igrejadodiabo.txt
	./$(BINARY) "Deus" igrejadodiabo.txt
