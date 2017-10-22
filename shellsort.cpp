#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "shellsort.h"
using namespace std;

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

void readFile(const string fileName, vector<long> &arr) {
    ifstream inFile;
    inFile.open(fileName);

    if(!inFile)
        cout << "error opening file" << endl;
    else{
        long readLong;
        while(!inFile.eof()){
            inFile >> readLong;
            arr.push_back(readLong);
        }
    }
}

void writeFile(const string outFileName, vector<long> &arr) {
    ofstream outfile (outFileName);

    cout << "List numbers after sorting:" << endl;
    if (outfile.is_open()){
        for (int i=0; i < arr.size(); i++){
            outfile << arr.at(i) << endl;
        }
    }
    else
        cout << "Unable to open file";

    outfile.close();
}

int main(int argc, char* argv[]) {
    vector<long> shellSortVector;

    string filename = argv[1];
    readFile(filename, shellSortVector);

    shellsort(shellSortVector);

    string outfilename = argv[2];

    writeFile(outfilename, shellSortVector);
    
    return 0;
}