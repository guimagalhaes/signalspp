TARGET	 = teste
CC	 = g++
CFLAGS	 = -Wall -DLINUX
INCLUDES = -I..
LDLIBS	 = -lsignals++ -L..
OBJS	 = teste.o

ifdef RELEASE
CFLAGS += -O2
else
CFLAGS += -g -DDEBUG
endif

all:	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDLIBS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $*.o $*.cpp

clean:
	-rm -f $(OBJS) *~ core $(TARGET)

exec:
	LD_LIBRARY_PATH=../ ./$(TARGET)

leak_check:
	LD_LIBRARY_PATH=../ valgrind --leak-check=yes --show-reachable=yes -v ./$(TARGET)

debug:
	LD_LIBRARY_PATH=../ gdb ./$(TARGET)
