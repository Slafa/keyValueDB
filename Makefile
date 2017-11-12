CC=gcc
CFLAGS=-g -O0



main: kvdb.c getSet.c kvdbFunctions.c kvh.h
	$(CC) -o main kvdb.c kvdbFunctions.c getSet.c 

clean:
	rm -f *.o kvdb getSet kvdbFunctions eksamen
