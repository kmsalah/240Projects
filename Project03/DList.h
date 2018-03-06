#ifndef DLIST_H_
#define DLIST_H_

class Node {
public:
	int val;
	Node *parent;
	Node *child;
	Node(int); 
	int GetData() {return val;};
};

class DList {
public:

	Node *head;
	Node *tail;

	DList();
	DList(const DList &list);

	void PushFront(int a); //create a Node containing a
	//and add it to the front of the list
	void PushEnd(int a); //create a Node containing a
	//and add it to the end of the list
	Node* PopFront(); //popping out the first Node of the list,
	//if the list is empty, return NULL
	Node* PopEnd(); //popping out the last Node of the list,
	//if the list is empty, return NULL
	void PrintListForward(); //print every element from start to end
	//in one line separated by a space
	void PrintListReverse(); //print every element from end to start
	//in one line separated by a space
};
#endif