CC = gcc
CFLAGS = -Wall -std=c99
LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11

SRC = main.c
OBJ = $(SRC:.c=.o)
EXEC = game_of_life

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean