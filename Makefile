chec.o : chec.c
	gcc -g -o chec.o -c chec.c

registro.o : registro.c
	gcc -g -o registro.o -c registro.c

main.o : main.c
	gcc -g -o main.o -c main.c

ux.o : ux.c
	gcc -g -o ux.o -c ux.c

main : main.o registro.o chec.o ux.o
	gcc -g -o main *.o

all : main

run : main
	./main
