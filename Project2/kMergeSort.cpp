#include "kMergeSort.h"
#include "Heap.cpp"

void quickSort(long int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

int partition(long int arr[], int left, int right)
{
	int pivot = left;
	int temp;

	while (left < right) // while the indexes are different - ends when nthe left index is equal to the right index.
	{
		if (arr[left] > arr[right]) // if the array[left] is bigger then array[right]
		{
			if (pivot == left) // if the pivot is equal to the left index switch between left & right and promote left index.
			{
				temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
				pivot = right;
				left++;
			}
			else // if the pivot /= left index switch between left & right and promote right index.
			{
				temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
				pivot = left;
				right--;
			}
		}
		else // if the array[left] is not bigger then array[right]
		{
			if (pivot == right)
			{
				left++;
			}
			else
				right--;
		}
	}

	return pivot;
}

void kMergeSort(long int arr[], int low, int high, int k) {

	if (high - low < k) {
		quickSort(arr, low, high);
		return;
	}

	int q = (high - low + 1) / k;
	int reminder = (high - low + 1) % k;
	int sub_low = low, sub_high = low + q - 1;

	for (int i = 0; i < k ; i++) { //was int i=0; i<k-1 ; i++
		if (reminder > 0) {
			sub_high++;
			reminder--;
		}
		kMergeSort(arr, sub_low, sub_high, k);
				sub_low = sub_high+1;				//re-initiating next sub array indexes
		sub_high = sub_low + q - 1;
	}
	//kMergeSort(arr, low + (k - 1) * q, high, k);

	kMerge(arr, low, high, k);
	return;
}

void kMerge(long int arr[], int low, int high, int k) {

	pair<long int, int>* temp = new pair<long int, int>[k]; //temporary array for innitiating themin heap
	int* indexes = new int[k];						//array to hold current indexes in each of the K arrays
	int* arrBounds = new int[k];					//symbolizes for each array at which index it starts
	long int* res = new long int[high - low + 1];				//merged array result

	int q = (high - low + 1) / k;					//q= size of each sub array
	int reminder = (high - low + 1) % k;
	int sub_low = low, sub_high = low + q - 1;
	for (int i = 0; i < k; i++) {
		if (reminder > 0) {
			sub_high++;
			reminder--;
		}
		temp[i] = make_pair(arr[sub_low], i); //first=value , second = subArr id number (0,1,2,..,k-1)
		indexes[i] = sub_low;				 //for subArr i, starts in index low+i*q in og arr
		arrBounds[i] = sub_low;				//same as above^
		
		sub_low = sub_high+1;				//re-initiating next sub array indexes
		sub_high = sub_low + q - 1;
	}

	Heap<long int, int> heap(temp, k);

	for (int i = 0; i < high - low + 1; i++) {
		pair<long int, int> min = heap.deleteMin();
		res[i] = min.first;
		if ((min.second == k - 1 && indexes[min.second] < high) || (indexes[min.second] < arrBounds[min.second + 1] - 1)) {	//if the index of subArr of min is still smaller than the lower bound of the next subArr 
			indexes[min.second]++;								//we get the next index, and insert the heap the next item in the subArr
			heap.insert(make_pair(arr[indexes[min.second]], min.second));
		}
	}

	int idx = low;
	for (int i = 0; i < high - low + 1; i++) {		//copy the sorted merged array from res to the og arr
		arr[idx++] = res[i];
	}

	delete[] temp;
	delete[] indexes;
	delete[] arrBounds;
	delete[] res;

}