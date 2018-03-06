#include "DList.h"
#include <iostream>
using namespace std;



Node::Node(int a) {
	val = a;
	parent = NULL;
	child = NULL;
}



DList::DList() {
	head = NULL;
	tail = NULL;
}

DList::DList(const DList &list) {
	head = list.head;
	tail = list.tail;
}

//create a Node containing a
//and add it to the front of the list
void DList::PushFront(int a) {
	Node *newNode = new Node(a); 
	if(head==NULL) { //list is empty(now creating a single node list)
		head = newNode;//set head to the new node
		tail = head; //set the tail to the new node
	}
	//else, go to head, head = head.childnode, newnode = head
	else
	{
		Node* oldHead = head; //save the current head 
		head = newNode;//moving the head to the new node

		oldHead->parent = head;// oldheads parent is the head
		head->child = oldHead; // heads child is the oldhead 
	}
}

//create a Node containing a
//and add it to the end of the lis
void DList::PushEnd(int a) {
	//create new node
	//if the list is empty, set new node to head and tail,  
	//if not, create a temp node pointer and set to head,
		//keep moving temp until temp->child equals NULL
		//set temp->child to the new node
		//set new node to tail
	Node *newNode = new Node(a);
	//if list is empty set new node as head and tail
	if(head==NULL) {
		head = newNode; //move head to new node
		tail = head; //move tail to new node
	}
	else {
		Node* oldTail = tail; //new pointer to save tail
		tail = newNode;// set tail to newly created node

		oldTail->child = tail; //set old tails child to point to the new tail
		tail->parent = oldTail; //set the newtails parent to point to old tail        
	}
	
}


//popping out the first Node of the list,
//if the list is empty, return NULL
Node* DList::PopFront() {
	if (head == NULL) return NULL; //if the list is empty return null
	
	Node *holder = head; //create a pointer to point to head
	if (head->child == NULL) //if the list only contains one node
	{
		head = NULL; //set head to point to nothing
		tail = NULL; //set tail to point to nothing 
		return holder; //return the old head
	}

	head = head->child; //set head to be the next node
	return holder;//return oldhead
}


Node* DList::PopEnd() {//popping out the last Node of the list,
	if (tail == NULL) return NULL; //if the list is empty 
	
	Node *holder = tail; //create pointer to point to tail
	if (tail->parent == NULL)//if there is only one node in thelist
	{
		head = NULL; //emptying list
		tail = NULL; 
		return holder;
	}

	tail = tail->parent; //set tail to be its parent  
	return holder;
}

//if the list is empty, return
void  DList::PrintListForward() //print every element from start to end
{
	if (head == NULL) return; //if list is empty
	if (head->child == NULL) { //if the list contains 1 node
		cout << head->GetData(); // printing out data at the head
		return;
	}

	Node *current = head; //create a new 
	bool done = false;

	while(!done) {
		cout << current->GetData() << " ";
		current = current->child;
		if (current == NULL) done = true; //if the 
	}

	cout << endl;
}
//in one line separated by a space
void DList::PrintListReverse() //print every element from end to start
{
	if (head == NULL) return;
	if (head->child == NULL) {
		cout << head->GetData();
		return;
	}

	Node *current = tail;
	bool done = false;

	while(!done) {
		cout << current->GetData() << " ";
		current = current->parent;
		if (current == NULL) done = true;
	}

	cout << endl;
}
//in one line separated by a space
