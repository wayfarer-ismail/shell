CC = gcc
CFLAGS = -g -Wall
LIBS = -lm

all: main ls head sleep pwd

main: main.o
	$(CC) $(LIBS) $^ -o $@

ls: ls.o
	$(CC) $(LIBS) $^ -o $@

sleep: sleep.o
	$(CC) $(LIBS) $^ -o $@

pwd: pwd.o
	$(CC) $(LIBS) $^ -o $@

head: head.o
	$(CC) $(LIBS) $^ -o $@


main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

ls.o: ls.c
	$(CC) -c $(CFLAGS) $^ -o $@

sleep.o: sleep.c
	$(CC) -c $(CFLAGS) $^ -o $@

pwd.o: pwd.c
	$(CC) -c $(CFLAGS) $^ -o $@

head.o: head.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o main ls head sleep pwd
