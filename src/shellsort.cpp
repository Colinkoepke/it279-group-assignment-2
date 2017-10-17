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
void shellsort(std::vector<long> &arr) {
    for (int gap = calculateGap(arr.size()); gap > 0; gap /= 2) {
        for (int i = gap; i < arr.size(); ++i) {
            long temp = arr.at(i);
            int j;
            for (j = i; j >= gap && arr.at(j - gap) > temp; j -= gap) {
                arr.at(j) = arr.at(j - gap);
            }
            arr.at(j) = temp;
        }
    }
}

int main() {
    std::vector<long> v;
    v.push_back(33);
    v.push_back(15);
    v.push_back(17);
    v.push_back(3);
    v.push_back(7);
    shellsort(v);
    for (int i = 0; i < v.size(); i++)
        std::cout << v.at(i) << ",";
    
    std::cout << std::endl;
    return 0;
}