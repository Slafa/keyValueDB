CC=gcc
CFLAGS=-g -O0



eksamen: kvdb.c getSet.c kvh.h
	$(CC) -o eksamen kvdb.c getSet.c 

clean:
	rm -f *.o kvdb getSet eksamen
