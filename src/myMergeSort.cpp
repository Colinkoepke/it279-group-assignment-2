#include "myMergeSort.h"
using namespace std;

/**
 * merge function takes 4 params
 * 1st param - takes array of numbers read from file
 * 2nd param - current left index of sub array
 * 3rd param - splitting point of left sub array and right sub array
 * 4th param - beginning right index of right sub array
 */
void merge(long array[], int leftIndex, int middleOfArray, int rightIndex){
  
    int leftSubIndex = 0;
    int rightSubIndex = 0;
    
    int sizeOfLeftSubArray = middleOfArray - leftIndex + 1;
    int sizeOfRightSubArray =  rightIndex - middleOfArray;
    
    long leftSubArray[sizeOfLeftSubArray];
    long rightsubArray[sizeOfRightSubArray];
 
    //copy the contents from the left of the array to the temp left sub array
    for (int i = 0; i < sizeOfLeftSubArray; i++){
       leftSubArray[i] = array[leftIndex + i];
    }
    
    //copy the contents from the right of the array to the temp right sub array
    for (int i = 0; i < sizeOfRightSubArray; i++){
        rightsubArray[i] = array[middleOfArray + 1 + i];
    }
    
    //increment the index until the index is at the size of the array
    //check to see if the value in the left array is smaller thanthe right
    //if left is smaller, then copy from temp left sub array to actual array
    //else swap values because right is bigger
    while (leftSubIndex < sizeOfLeftSubArray && rightSubIndex < sizeOfRightSubArray){
        if (leftSubArray[leftSubIndex] <= rightsubArray[rightSubIndex]){
            array[leftIndex] = leftSubArray[leftSubIndex];
            leftSubIndex++;
        }
        else{
            array[leftIndex] = rightsubArray[rightSubIndex];
            rightSubIndex++;
        }
        leftIndex++;
    }
 
    //increment left sub array index until it is size of the array
    //each increment, copy value from temp left sub array to actual array
    while (leftSubIndex < sizeOfLeftSubArray){
        array[leftIndex] = leftSubArray[leftSubIndex];
        leftSubIndex++;
        leftIndex++;
    }
 
    ///increment right sub array index until it is size of the array
    //each increment, copy value from temp right sub array to actual array
    while (rightSubIndex < sizeOfRightSubArray){
        array[leftIndex] = rightsubArray[rightSubIndex];
        rightSubIndex++;
        leftIndex++;
    }
}

/**
 * mergeSort function takes 2 params
 * 1st param - array to be sorted
 * 2nd param - the total size of the array
 * bottom up mergesort assumes array is already into singleton sub arrays
 * subarray size increases with each for-loop iteration from 1 -> 2 -> 4 -> 8 -> .... n size
 * arrays are then iteratively merged and sorted during the merge
*/
void mergeSort(long array[], int totalArraySize){
  
   for (int subArraySize = 1; subArraySize < totalArraySize; subArraySize = subArraySize*2){
       // Pick starting point of different subarrays of current size
       for (int leftIndex = 0; leftIndex<totalArraySize-1; leftIndex += 2*subArraySize){
           //middle point of array (where left array ends)
           int middleOfArray = leftIndex + subArraySize - 1;
 
           int rightIndex = 0; 
           //check to see if the left index is smaller than right, if so then swap
           if(leftIndex + 2 * subArraySize - 1 < totalArraySize - 1)
	    rightIndex = leftIndex + 2*subArraySize - 1;
           else
            rightIndex = totalArraySize-1;
 
           //call merge function
           merge(array, leftIndex, middleOfArray, rightIndex);
       }
   }
}
