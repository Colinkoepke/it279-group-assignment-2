#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "myMergeSort.h"
#include "shellsort.h"
using namespace std;

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
            cout << arr.at(i) << endl; // temp
            outfile << arr.at(i) << endl;
        }
    }
    else
        cout << "Unable to open file";

    outfile.close();
}

//main function to call sort and take command line arguments
int main(int argc, char* argv[]){
    vector<long> shellSortVector;
    vector<long> mergeSortVector;

    string filename = argv[1];
    cout << filename << endl;
    readFile(filename, mergeSortVector);

    cout << "List of numbers before sorting:" << endl;
    for (int i=0; i < mergeSortVector.size(); i++)
        cout << mergeSortVector.at(i) << endl;

    mergeSort(mergeSortVector);

    cout << endl << "After sorting" << endl;
    for (int i = 0; i < mergeSortVector.size(); i++) {
        cout << mergeSortVector.at(i) << endl;
    }
    //shellsort(mergeSortVector);

    string outfilename = argv[2];

    writeFile(outfilename, mergeSortVector);
    
    return 0;
}