p01_stringsCC=g++ -std=c++20
CFLAGS=-O0 -g -Wall
DEPS = alphabet.h chain.h symbol.h 
OBJ = main.o

SRC = './src/'

compilar:
	g++ $(CFLAGS) $(SRC)*.cc -o p01_strings


%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
all: chain

chain: main.o
	g++ -o chain main.cc alphabet.cc chain.cc symbol.cc

clean:
	rm -f *.o
