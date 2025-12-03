CC=g++
CPPFLAGS=-O2 -lm
BINARY=bgrep

build: main.cpp 
	$(CC) $(CPPFLAGS) main.cpp -o $(BINARY)

test: $(BINARY)
	./$(BINARY) "amigos" testando.txt
	echo 
	./$(BINARY) "dia" testando.txt
	echo 
	./$(BINARY) "a" testando.txt
	echo 
	./$(BINARY) "Diabo" igrejadodiabo.txt
	echo 
	./$(BINARY) "Deus" igrejadodiabo.txt
	echo 
