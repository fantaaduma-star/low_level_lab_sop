CC      := gcc
CFLAGS  := -std=gnu17 -Wall -Wextra -g -pthread -fsanitize=address,undefined
LDFLAGS := -pthread -fsanitize=address,undefined
LDLIBS  := -lrt -lm

.PHONY: all clean

all: exec

exec: copyFile.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f exec
