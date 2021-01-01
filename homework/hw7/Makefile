#ChrisWilhelm cwilhel8
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)


cQueueTest:: CQueueTest.o CQueue.o
	g++ -o cQueueTest CQueueTest.o CQueue.o

CQueusTest.o:: CQueueTest.cpp CQueue.h
	g++ -c CQueueTest.cpp $(CFLAGS)

CQueue.o:: CQueue.cpp CQueue.h
	g++ -c CQueue.cpp $(CFLAGS)

tQueueTest:: TQueueTest.o
	g++ -o tQueueTest TQueueTest.o

TQueueTest.o:: TQueueTest.cpp Queue.inc Queue.h
	g++ -c TQueueTest.cpp $(CFLAGS)

.PHONY:: clean
clean:
	rm -f *.o main?  *~ cQueueTest tQueueTest
