CC = g++
CCFLAG = -g -w
exec:   main.o UnsignedLargeInt.o
	$(CC) $(CCFLAG) -o Project5 main.o UnsignedLargeInt.o
	
main.o: main.C
	$(CC) $(CCFLAG) -c main.C

UnsignedLargeInt.o: UnsignedLargeInt.C UnsignedLargeInt.h
	$(CC) $(CCFLAG) -c UnsignedLargeInt.c 
