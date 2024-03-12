CC = g++
CFLAGS = -Wall -Wextra -pedantic
LIBS = -lczmq

arnold: main.cpp
	$(CC) $(CFLAGS) -o arnold main.cpp $(LIBS)

clean:
	rm -f arnold