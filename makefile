CC = gcc
CFLAGS = -Wall -g
OBJS = hw7Main.c register7.o print7.o search7.o delete7.o sort7.o
main7 : $(OBJS)
	$(CC) -o main7 $(OBJS)
%.0 : %.c
	$(CC) -c -o $@ $(CFLAGS) $<
clean :
	rm *.o main7

