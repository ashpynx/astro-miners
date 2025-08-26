CC = gcc
CFLAGS = -std=c11 -Wall
SRC = src/*.c
OUT = game

# Detect OS
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    LIBS = -lraylib -lm -lX11 -lpthread -ldl -lrt -lGL
endif

ifeq ($(UNAME_S),Darwin)
    CFLAGS += -I/opt/homebrew/Cellar/raylib/5.5/include
    LIBS = -L/opt/homebrew/Cellar/raylib/5.5/lib -lraylib \
           -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
endif

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)