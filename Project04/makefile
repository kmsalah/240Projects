CC = g++
CCFLAG = -g -w
exec:   main.o PQ.o
	$(CC) $(CCFLAG) -o Project4 main.o PQ.o
	
main.o: main.C
	$(CC) $(CCFLAG) -c main.C

PQ.o: PQ.C PQ.h
	$(CC) $(CCFLAG) -c PQ.c
