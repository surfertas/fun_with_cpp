CUR_DIR=.

CC=/usr/bin/g++
CFLAGS=--std=c++11 -Wall

OUT=smallest_multiple

OBJS= main.o

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT)

main.o: $(CUR_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(CUR_DIR)/main.cpp

clean:
	rm -r *.o $(OUT)


