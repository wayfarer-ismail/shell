CC = gcc
CFLAGS = -g -Wall
LIBS = -lm

all: main ls head sleep pwd mkdir rmdir echo cat whoami

main: main.o util.o
	$(CC) $(LIBS) $^ -o $@

util.o: util.c util.h
	$(CC) -c $(CFLAGS) $< -o $@


ls: ls.o
	$(CC) $(LIBS) $^ -o $@

sleep: sleep.o
	$(CC) $(LIBS) $^ -o $@

pwd: pwd.o
	$(CC) $(LIBS) $^ -o $@

mkdir: mkdir.o
	$(CC) $(LIBS) $^ -o $@

rmdir: rmdir.o
	$(CC) $(LIBS) $^ -o $@

head: head.o
	$(CC) $(LIBS) $^ -o $@

echo: echo.o
	$(CC) $(LIBS) $^ -o $@

cat: cat.o
	$(CC) $(LIBS) $^ -o $@

whoami: whoami.o
	$(CC) $(LIBS) $^ -o $@


main.o: main.c util.h
	$(CC) -c $(CFLAGS) $< -o $@

ls.o: ls.c
	$(CC) -c $(CFLAGS) $^ -o $@

sleep.o: sleep.c
	$(CC) -c $(CFLAGS) $^ -o $@

pwd.o: pwd.c
	$(CC) -c $(CFLAGS) $^ -o $@

mkdir.o: mkdir.c
	$(CC) -c $(CFLAGS) $^ -o $@

rmdir.o: rmdir.c
	$(CC) -c $(CFLAGS) $^ -o $@

echo.o: echo.c
	$(CC) -c $(CFLAGS) $^ -o $@

cat.o: cat.c
	$(CC) -c $(CFLAGS) $^ -o $@

whoami.o: whoami.c
	$(CC) -c $(CFLAGS) $^ -o $@

head.o: head.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o main ls head sleep pwd mkdir rmdir echo cat whoami
