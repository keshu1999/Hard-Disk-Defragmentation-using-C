all : 	MenuOps.o OtherOps.o Main.o
	gcc -g Main.o MenuOps.o OtherOps.o -o output
	./output

Main.o :	Main.c
	gcc -c -g Main.c

MenuOps.o :	MenuOps.c
	gcc -c -g MenuOps.c

OtherOps.o :	OtherOps.c
	gcc -c -g OtherOps.c
