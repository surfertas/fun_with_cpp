CUR_DIR=.
SRC_DIR=../src
INC_DIR=../include

CC=/usr/bin/g++
CFLAGS=--std=c++11 -Wall -I$(INC_DIR)

OUT=largest_product

OBJS= main.o

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT)

main.o: $(CUR_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(CUR_DIR)/main.cpp

clean:
	rm -r *.o $(OUT)


