/*
Khalid Salah
03/16/17
*/


#ifndef PQ_H_
#define PQ_H_

class Node {
public:
	int val;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
	Node* prev;

	Node(int);
	//friend class PQ
};


class PQ {
public:
	Node* head;
	Node* tail;

	PQ();
	~PQ();
	//do i need a copy constructor
	void Push(int);
	void BubbleUp();
	int Pop();
	void BubbleDown();
	//Node* findParentOfNextTail();
	bool isEmpty() {
		if(head==null) return true; else return false; }
};


#endif






/*

PQARRAY.H

class PQArray {
	int* Arr;
	int size, length;

	PQArray();

	void increaseSize();
	void push(int);
	void pop();

	}


PQARRAY.C

PQArray::PQArray() {
	arr = new int[1];
	length = 1;
	size =0;

}
	
PQARRAY::increaseSize() {
	int *tmp = arr;
	arr = new int[2*length];
	memcpy = (tmp, arr, length);
	delet [] tmp;
}


push (int i) {
	if(full) {
	increasesize();
	}
	arr[size]=i;
	size++;
	int index = size -1;

}




TREE NOTES
























*/