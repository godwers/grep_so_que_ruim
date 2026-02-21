CC=g++
CPPFLAGS=-O3 -lm -march=native -Wall -Wextra
BINARY=bgrep

build: 
	$(CC) $(CPPFLAGS) src/main.cpp -o $(BINARY)

test: $(BINARY)
	./$(BINARY) "amigos" test/testando.txt
	./$(BINARY) "dia" test/testando.txt
	./$(BINARY) "a" test/testando.txt
	./$(BINARY) "Diabo" test/igrejadodiabo.txt
	./$(BINARY) "Deus" test/igrejadodiabo.txt
clear: $(BINARY)
	@rm -rf ./$(BINARY)
