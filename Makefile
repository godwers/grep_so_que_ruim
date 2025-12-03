CC=g++
CPPFLAGS=-O2 -lm
BINARY=bgrep

test: $(BINARY)
	echo 
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
build: 
	$(CC) $(CPPFLAGS) main.cpp -o $(BINARY)
