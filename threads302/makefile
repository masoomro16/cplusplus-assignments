# Make file

CC	= g++ -Wall -pedantic -std=c++11 -pthread

all: primes

primes: primes.o
	$(CC) -o primes primes.o

primes.o: primes.cpp
	$(CC) -c primes.cpp

# clean by removing object files.

clean:
	rm primes.o primes

