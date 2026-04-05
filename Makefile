CC = gcc

CFLAGS = -Wall -Wextra -g

TARGET = my_echo

all: $(TARGET)

$(TARGET): my_echo.c
	$(CC) $(CFLAGS) my_echo.c -o $(TARGET)

clean:
	rm -f $(TARGET)