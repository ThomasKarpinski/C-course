main: main.o trade-stocks.o
    gcc -o main main.o trade-stocks.o

main.o: main.c trade-stocks.h
    gcc -c main.c

trade-stocks.o: trade-stocks.c trade-stocks.h
    gcc -c trade-stocks.c

clean:
    rm -f *.o main