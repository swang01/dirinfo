all: dirinfo.o
	gcc -o program dirinfo.o

dirinfo.o: dirinfo.c
	gcc -c dirinfo.c

run:
	./program
