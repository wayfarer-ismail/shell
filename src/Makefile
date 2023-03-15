CC = gcc
CFLAGS = -g -Wall
LIBS = -lm

all: main ls head

main: main.o
	$(CC) $(LIBS) $^ -o $@

ls: ls.o
	$(CC) $(LIBS) $^ -o $@

head: head.o
	$(CC) $(LIBS) $^ -o $@


main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

ls.o: ls.c
	$(CC) -c $(CFLAGS) $^ -o $@

head.o: head.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o main ls head
