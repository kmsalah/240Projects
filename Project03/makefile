CC = g++
CCFLAG = -g -w
exec:   main.o DList.o
	$(CC) $(CCFLAG) -o Project3 main.o DList.o
	
main.o: main.C
	$(CC) $(CCFLAG) -c main.C

DList.o: DList.C DList.h
	$(CC) $(CCFLAG) -c DList.c
