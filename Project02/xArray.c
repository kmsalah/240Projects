#include "xArray.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int* ReadInput(int n) {
	//string input;
	//cin >> input;

	int*  array = new int[n];
	
	//stringstream is(input);
	//int num;

	for (int i =0; i<n; ++i) {
		//is >> num;
		//array[i] = num;
        cin >> array[i];
	}
	return array;
}

int DotProduct(int *a, int *b, int length) {
	int total =0;
	for(int i=0; i<length; i++) {
		int val = a[i]*b[i];	
		total+=val;
	}

	return total;
}

