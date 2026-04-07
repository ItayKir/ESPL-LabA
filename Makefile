CC = gcc

CFLAGS = -Wall -Wextra -g

TARGET = encoder

all: $(TARGET)

$(TARGET): encoder.c
	$(CC) $(CFLAGS) encoder.c -o $(TARGET)

clean:
	rm -f $(TARGET)