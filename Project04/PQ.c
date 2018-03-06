#include "PQ.h"
#include <iostream>
using namespace std;


Node::Node(int a) {
	val = a;
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;
}


PQ::PQ() {
	head = tail = NULL;
}

PQ::~PQ(){
    Node* current;
    current = tail;

    while(current != head && current !=NULL){
        current = tail -> prev;
       delete [] tail;
    }

    delete [] current;

}

void PQ::Push(int x) {
	Node* newNode = new Node(x);

	if(head==NULL) { //PQ is empty
		head = newNode;
		tail = newNode;
	}
	if(head->leftChild== NULL) { //PQ only contains head
		head->leftChild = newNode;
		tail = newNode;
	}
	//otherwise find the next open spot, and put it in there
	//then bubble up();
}


void PQ::BubbleUp() {
	Node* tmp = tail;
	while(tmp->parent!=NULL) {
		if(tmp->parent->val >= tmp->val) {
			int hold = tmp->val;
			tmp->val = tmp->parent->val;
			tmp->parent->val = hold;
			tmp = tmp->parent; //shift the thing up
		}else {
			break; //exit, cause were gucci
		}
	}
}


int PQ::Pop() {
	int retVal = head->val;

	if(head==NULL) { //PQ is empty
		return NULL;
	}
	if(head==tail) { //only one thing in the PQ
		head == tail == NULL;
		return retVal;
	}

	//switch head and tail values
	int hold = head->val;
	head->val = tail->val;
	tail->val = hold;

	//now we have to delete the tail and move it

	Node* tmp = tail;

	//now we bubble down the new head

}


void PQ::BubbleDown() {
	if(head==tail) {
		return;
	}
	
}









