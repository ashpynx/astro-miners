CC = gcc
CFLAGS = -std=c11 -Wall
LIBS= -lraylib -lm -lX11 -lpthread -ldl -lrt -lGL

SRC = src/*.c
OUT = game

$(OUT) :  $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean :
	rm -f $(OUT)	
