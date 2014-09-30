CC=g++
CFLAGS=-Wall

main: main.cpp
	$(CC) main.cpp $(CFLAGS) -o main
run: main
	clear
	./main

clean:
	rm main
