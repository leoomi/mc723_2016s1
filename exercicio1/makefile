CC=gcc
CFLAGS= -O3 -march=native -fopenmp -g

all: primo competicao

primo: main.o calc_primo.o
	$(CC) $(CFLAGS) calc_primo.o main.o -o primo

calc_primo.o: calc_primo.c
	$(CC) -c $(CFLAGS) calc_primo.c


main.o: main.c
	$(CC) -c $(CFLAGS) main.c

competicao: competicao.c
	$(CC) $(CFLAGS) competicao.c -o competicao -lm

clean:
	rm *o primo
