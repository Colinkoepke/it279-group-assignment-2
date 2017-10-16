#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void merge(vector<long> & myVector, vector<long> &  tempVector, int leftValue, int rightValue, int endOfRightVect){

    int frontOfVect = rightValue - 1;
    int index = leftValue;
    int numElements = endOfRightVect - leftValue + 1;

    while(leftValue <= frontOfVect && rightValue <= endOfRightVect)
        if(myVector[leftValue] <= myVector[rightValue])
            tempVector[index++] = move(myVector[leftValue++]);
        else
            tempVector[index++] = move(myVector[rightValue++]);

    while(leftValue <= frontOfVect)
        tempVector[index++] = move(myVector[leftValue++ ]);

    while(rightValue <= endOfRightVect)
        tempVector[index++] = move(myVector[rightValue++]);

    for(int i=0; i < numElements; ++i, --endOfRightVect)
        myVector[endOfRightVect] = move(tempVector[endOfRightVect]);
}

void mergeSort(vector<long> & myVector){
    int currArraySize;
    int leftIndex;

    //start with the curr array size and then every iteration double the array size
    //this is because with bottom up, you assume the arrays are of size 1 and keep doubling
    for (currArraySize=1; currArraySize< myVector.size(); currArraySize = 2*currArraySize){

        //create a temporary vector
        vector<long> tempvect(myVector.size());
        for (leftIndex=0; leftIndex<myVector.size()-1; leftIndex += 2*currArraySize){

            int mid = leftIndex + currArraySize - 1;
            int rightIndex;

            //check to see if the left index is smaller than right, if so then swap
            if(leftIndex + 2 * currArraySize - 1 < myVector.size() -1)
                rightIndex = leftIndex + 2*currArraySize - 1;
            else
                rightIndex = myVector.size()-1;

            merge(myVector, tempvect, leftIndex, mid, rightIndex);
        }
    }
}

//main function to call sort and take command line arguments
int main(int argc, char* argv[]){

    vector<long> myvect;

    string filename = argv[1];
    ifstream inFile;
    inFile.open(filename);

    if(!inFile)
        cout << "error opening file";
    else{
        long readLong;
        while(!inFile.eof()){
            inFile >> readLong;
            myvect.push_back(readLong);
        }
    }

    cout << "List of numbers before sorting:" << endl;
    for (int i=0; i < myvect.size(); i++)
        cout << myvect.at(i) << endl;

    mergeSort(myvect);

    cout << "List numbers after sorting:" << endl;
    for (int i=0; i < myvect.size(); i++)
        cout << myvect.at(i) << endl;
    return 0;
}