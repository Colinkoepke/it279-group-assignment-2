#ifndef MY_MERGE_SORT_H_
#define MY_MERGE_SORT_H_

#include <vector>

void merge(std::vector<long> & myVector, std::vector<long> &  tempVector, int leftValue, int rightValue, int endOfRightVect);

void mergeSort(std::vector<long> & myVector);

#endif