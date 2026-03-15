CC=g++
CPPFLAGS=-Ofast -lm -march=native -Wall -Wextra -Wpedantic -funroll-loops 
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
install: $(BINARY)
	@cp $(BINARY) /usr/bin
uninstall: $(BINARY)
	@rm -i /usr/bin/$(BINARY)
