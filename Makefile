CC=gcc
CFLAGS=-g -O0



eksamen: kvdb.c getSet.c kvdbFunctions.c kvh.h
	$(CC) -o eksamen kvdb.c kvdbFunctions.c getSet.c 

clean:
	rm -f *.o kvdb getSet kvdbFunctions.c eksamen
