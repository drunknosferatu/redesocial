chec.o : chec.c
	gcc -o chec.o -c chec.c

registro.o : registro.c
	gcc -o registro.o -c registro.c

main.o : main.c
	gcc -o main.o -c main.c

main : main.o registro.o chec.o
	gcc -o main *.o

all : main

run : main
	./main
