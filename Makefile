CC      := gcc
CFLAGS  := -std=gnu17 -Wall -Wextra -g -pthread -fsanitize=address,undefined
LDFLAGS := -pthread -fsanitize=address,undefined
LDLIBS  := -lrt -lm

# każdy plik .c to osobny program: lab1/zad1.c -> lab1/zad1
SRCS := $(shell find . -name '*.c' -not -path './.git/*')
BINS := $(SRCS:./%.c=%)

.PHONY: all clean

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(BINS)
