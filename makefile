CC = g++
CFLAG = -c
WFLAG = -w
C11FLAG = -std=c++11

default: run_sorts.o myMergeSort.o shellsort.o
	$(CC) -g build/run_sorts.o build/myMergeSort.o build/shellsort.o -o bin/out

run_sorts.o: src/run_sorts.cpp
	$(CC) $(C11FLAG) $(CFLAG) -g src/run_sorts.cpp -o build/run_sorts.o

myMergeSort.o: src/myMergeSort.cpp
	$(CC) $(C11FLAG) $(CFLAG) -g src/myMergeSort.cpp -o build/myMergeSort.o

shellsort.o: src/shellsort.cpp
	$(CC) $(C11FLAG) $(CFLAG) -g src/shellsort.cpp -o build/shellsort.o

#TODO Insertion sort

clean:
	rm build/*.o #bin/out