CC=gcc
CFLAGS=-g -O0



eksamen: kvdb.c kvh.h
	$(CC) -o eksamen kvdb.c 

clean:
	rm -f *.o kvdb
