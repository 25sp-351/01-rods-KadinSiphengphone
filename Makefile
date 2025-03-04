all: main

OBJS = main.o cut.o cutlist.o
CC = gcc
CFLAGS = -Wall

main: $(OBJS)
	gcc -o main $(CFLAGS) $(OBJS)

main.o: main.c cut.h cutlist.h

cut.o: cut.c cut.h

cutlist.o: cutlist.c cutlist.h cut.h

clean:
	rm -f main $(OBJS)

