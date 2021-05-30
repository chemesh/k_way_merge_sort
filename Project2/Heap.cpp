
#include "Heap.h"

template <class T1, class T2>
Heap<T1,T2>::Heap() :size(1), logsize(0), allocated(true)
{
	arr = new pair<T1, T2>[size];
}

template <class T1, class T2>
Heap<T1, T2>::Heap(pair<T1, T2>* _arr, int _size) :size(_size), logsize(_size) {
	arr = _arr;
	allocated = false;

	for (int i = size / 2 - 1; i >= 0; i--) {
		fixHeap(i);
	}
}

template <class T1, class T2>
Heap<T1, T2>::~Heap()
{
	if (allocated) {
		delete[] arr;
	}
	arr = nullptr;
}

template <class T1, class T2>
int Heap<T1, T2>::getParent(int index) {
	return (index - 1) / 2;
}

template <class T1, class T2>
int Heap<T1, T2>::getLeft(int index) {
	return (2 * index + 1);
}

template <class T1, class T2>
int Heap<T1, T2>::getRight(int index) {
	return (2 * index + 2);
}

template <class T1, class T2>
pair<T1, T2> Heap<T1, T2>::getMin() {
	return arr[0];
}

template <class T1, class T2>
pair<T1, T2> Heap<T1, T2>::deleteMin() {
	if (isEmpty())
		throw out_of_range("less then 1 item in heap");

	pair<T1, T2> min = arr[0];
	logsize--;
	arr[0] = arr[logsize];
	fixHeap(0);
	return min;
}

template <class T1, class T2>
void Heap<T1, T2>::insert(pair<T1, T2> data) {
	if (logsize == size)
		resize();
	int i = logsize;
	logsize++;

	while ((i > 0) && arr[getParent(i)].first > data.first) {
		arr[i] = arr[getParent(i)];
		i = getParent(i);
	}
	arr[i] = data;
}

template <class T1, class T2>
void Heap<T1, T2>::swap(int idx1, int idx2) {
	pair<T1, T2> temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

template <class T1, class T2>
bool Heap<T1, T2>::isEmpty() {
	return (logsize == 0 || arr == nullptr);
}

template <class T1, class T2>
void Heap<T1, T2>::resize() {
	size = size * 2;
	pair<T1, T2>* temp = new pair<T1, T2>[size];

	for (int i = 0; i < logsize; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

template <class T1, class T2>
void Heap<T1, T2>::fixHeap(int index) {
	int min;
	int left = getLeft(index);
	int right = getRight(index);

	if ((left < logsize) && arr[left].first < arr[index].first) {
		min = left;
	}
	else
		min = index;
	if ((right < logsize) && arr[right].first < arr[min].first) {
		min = right;
	}
	if (min != index) {
		swap(index, min);
		fixHeap(min);
	}
}