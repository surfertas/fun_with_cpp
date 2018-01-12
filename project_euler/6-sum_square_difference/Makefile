SRC_DIR=.

CC=/usr/bin/g++
CFLAGS=--std=c++11 -Wall

OUT=difference

OBJS= main.o

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT)

main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp

clean:
	rm -r *.o $(OUT)
