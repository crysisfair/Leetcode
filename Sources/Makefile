.PHONY:all
CC=g++
SRC=utils.cpp YanghuiTriangle.cpp Main.cpp
OBJ=$(SRC:.c=.o)
TARGET=leetcode
INC=-I ../Includes
CFLAGS=-Wall -lstdc++

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY:clean
clean:
	rm -f $(TARGET) *.o
