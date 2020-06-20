chec.o : chec.c
	gcc -o chec.o -c chec.c

registro.o : registro.c
	gcc -o registro.o -c registro.c

main.o : main.c
	gcc -o main.o -c main.c

ux.o : ux.c
	gcc -o ux.o -c ux.c

adm.o : adm.c
	gcc -o adm.o -c adm.c

apagar_post.o: apagar_post.c
	gcc -o apagar_post.o -c apagar_post.c

apagar_usuario.o : apagar_usuario.c
	gcc -o apagar_usuario.o -c apagar_usuario.c

main : main.o registro.o chec.o ux.o apagar_usuario.o apagar_post.o adm.o
	gcc -o main *.o

all : main

run : main
	./main
