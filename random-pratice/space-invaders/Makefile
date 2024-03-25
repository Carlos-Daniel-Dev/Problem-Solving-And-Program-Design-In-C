CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LDFLAGS=-lSDL2 -lSDL2_ttf

SRC=spacev.c
OBJ=$(SRC:.c=.o)
EXEC=spacev

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJ)