CUR_DIR=.
SRC_DIR=../src
INC_DIR=../include

CC=/usr/bin/g++
CFLAGS=--std=c++11 -Wall -I$(INC_DIR)

OUT=10001_prime

OBJS= main.o libprime.o

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT)

main.o: $(CUR_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(CUR_DIR)/main.cpp

libprime.o: $(SRC_DIR)/libprime.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/libprime.cpp

clean:
	rm -r *.o $(OUT)


