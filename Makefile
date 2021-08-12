CC = gcc
CFLAGS = -IInc -g
DEPS = Inc/minHeap.h Inc/sortedValuesList.h Inc/queue.h Inc/lastValuesList.h Inc/main.h
OBJS = Src/minHeap.o Src/sortedValuesList.o Src/queue.o Src/lastValuesList.o Src/main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dataSort: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
