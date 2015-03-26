CC = gcc

ODIR = ../obj

CFLAGS = -std=c99

TARGET = main

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(TARGET).c -o $(ODIR)/$(TARGET).o

run:
	./$(ODIR)/$(TARGET).o

clean:
	rm -rf *o
