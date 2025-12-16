PROG = main.exe

SRC = \
	main.cpp \
	filehandler/filehandler.cpp

CFLAGS = -g -std=c++17
CC = g++

all: $(PROG)

$(PROG): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f $(PROG)

.PHONY: all clean
