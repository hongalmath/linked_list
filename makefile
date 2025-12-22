CC = gcc
CFLAGS = -Iinc -Wall -g -Iinc/main

# Link validation library installed in /usr/local
LDFLAGS =validate/src/
LDLIBS  = validation

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=src/%.o)

TARGET = bin/main

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -L$(LDFLAGS) -l$(LDLIBS) -o $(TARGET)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
