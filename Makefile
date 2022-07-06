CC = gcc
CFLAGS = -Wall -O2
OBJS = main.o tree.o window.o cmd.o

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS) -lncurses

main.o: main.c tree.h
tree.o: tree.c tree.h
window.o: window.c window.h
cmd.o: cmd.c cmd.h

clean:
	rm -f *~ *.o main
