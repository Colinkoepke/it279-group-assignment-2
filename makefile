CC = g++
CFLAG = -c
WFLAG = -w
C11FLAG = -std=c++11

default: myMergeSort.o shellsort.o
	$(CC) -g build/myMergeSort.o build/shellsort.o -o bin/out

# Consider a main.cpp file?

myMergeSort.o: src/myMergeSort.cpp
	$(CC) $(CFLAG) -g src/myMergeSort.cpp -o build/myMergeSort.o

shellsort.o: src/shellsort.cpp
	$(CC) $(CFLAG) -g src/shellsort.cpp -o build/shellsort.o

#TODO Insertion sort

clean:
	rm build/*.o #bin/out