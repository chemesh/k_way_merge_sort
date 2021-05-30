#pragma once
#include <iostream>

using namespace std;

template <class T1, class T2>
class Heap {
	/*
	* Heap class is the implimantation of the min heap
	* theory and algorithms learned in data structure course.
	* the additions i made is that I changed it to a template class,
	* such that T1 represents the key value and T2 the sattelite data.
	*/
private: 
	pair<T1,T2>* arr;
	int size;
	int logsize;
	bool allocated;
	
	//in-case there's a need to support more data, resize will
	//change the capacity to 2 times its previous limit was.
	void resize();
	void fixHeap(int index);

public:
	Heap();

	//constractor that recieves an array of pairs, and buildes 
	//the heap using Floyd algorithm
	Heap(pair<T1, T2>* _arr, int _size);
	~Heap();

	static int getParent(int index);
	static int getLeft(int index);
	static int getRight(int index);

	pair<T1, T2> getMin();
	pair<T1, T2> deleteMin();
	void insert(pair<T1, T2> data);

	//swap between 2 nodes in the heap.
	//performed by sending the indexes of the nodes.
	void swap(int idx1, int idx2);
	bool isEmpty();

};