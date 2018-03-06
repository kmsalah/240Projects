CC = g++
CCFLAG = -g -w
exec:   main.o xArray.o
	$(CC) $(CCFLAG) -o Project2 main.o xArray.o
	
main.o: main.C
	$(CC) $(CCFLAG) -c main.C

xArray.o: xArray.C xArray.h
	$(CC) $(CCFLAG) -c xArray.c	
