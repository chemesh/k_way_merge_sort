/*
* Project 2 in data structures course - sorting numbers and implimenting the k-way merge sort algorithm.
* There are 7 source code files in this program, including this one.
* The remainning source filed:
*	kMergeSort.h
*	kMergeSort.cpp
*	Heap.h
*	Heap.cpp
*	Util.h
*	Util.cpp
*/

#include "Util.h"
#include "kMergeSort.h"

int main()
{
	string input;
	long int* arr;
	int n, k;

	try {
		n = getPosIntFromInput(-1); //0 is also ok
		k = getPosIntFromInput();

		cin >> input;
		arr = getArrFromFile(input, n);

		cin >> input;
		kMergeSort(arr, 0, n - 1, k);
		printArrToFile(input, arr, n);
	}
	catch (exception e) {
		//cout << e.what() << endl;

		cout << "wrong input" << endl;
		exit(-1);
	}

	return 0;
}
