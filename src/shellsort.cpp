#include <iostream>
#include <vector>

/**
 * Inefficient hibbards gap calculation
 */
int calculateGap(const int size) {
    int gap = 0;
    int i = 1;
    while (gap < size) {
        gap = (2 << i) - 1;
        i++;
    }
    gap /= 2;
    return gap;
}

/**
 * Shell sort using Hibbard's gap
 * Time complexity O(n^1.5)
 */
void shellsort(std::vector<int> &arr) {
    for (int gap = calculateGap(arr.size()); gap > 0; gap /= 2) {
        for (int i = gap; i < arr.size(); ++i) {
            int temp = arr.at(i);
            int j;
            for (j = i; j >= gap && arr.at(j - gap) > temp; j -= gap) {
                arr.at(j) = arr.at(j - gap);
            }
            arr.at(j) = temp;
        }
    }
}
