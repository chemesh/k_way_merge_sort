#pragma once
//#include <iostream>
#include "Heap.h"


//implimentation of the Quick Sort algorithm, using the Partition algorithm below,
//to sort an n-sized array in O(nlogn) in avarage.
void quickSort(long int arr[], int low, int high);
int partition(long int arr[], int left, int right);

//This recursive algorithm recieves an array and its most lower and upper available indexes,
//and a variable k, which then controls the number of sub-divisions made on the original array.
//each sub array is then called recursively, and if its size < k, it's being sorted on spot (by QuickSort)
//and returned, or being divided itself and continue the recursion chain.
//uppon returning from the recursion, the array is sent to kMerge() for merging the sub-arrays.
void kMergeSort(long int arr[], int low, int high, int k);

//kMerge() is the merging algorithm for k sorted sub-arrays.
//this piece of code utilzes the comparison model with a minimum heap, which enables
//the function to deliver the smallest value from the k sub arrays in O(nlogk) time.
//the overall logic (except the comparison) is similiar to the standard "merge" algorithm for 2 sub-arrays.
void kMerge(long int arr[], int low, int high, int k);