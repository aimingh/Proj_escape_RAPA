TARGET = main
OBJS = main.o memory.o

CC = c++
CFLAGS = -c -W -Wall
LD = c++
LDFLAGS = -o $(TARGET)
LIBS = -lcurses

all : $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $<

clean:
	rm *.o
	rm $(TARGET)
