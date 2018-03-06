#ifndef UNSIGNEDLARGEINT_H_
#define UNSIGNEDLARGEINT_H_ 

#include <iostream>
using namespace std;

class UnsignedLargeInt {
	char *data;
	int length;
	int size;

	static int Compare(const UnsignedLargeInt& one, const UnsignedLargeInt& two) {
		if(one.length > two.length) {
			return 1; 
		} else if(one.length < two.length) {
			return -1;
		} else { //they are the same length
			for(int i =one.length-1; i>=0; i--) {
				if(one.data[i] > two.data[i]) {
					return 1;
				}else if (one.data[i] < two.data[i]) {
					return -1;
				}
			}
		}
		return 0; 
    }

public:
	UnsignedLargeInt();

	//constructor that performs deep copy
	UnsignedLargeInt(const UnsignedLargeInt &copyInt);

	//constructor to take unsigned long long as digits(char) and store the digits in the array
	UnsignedLargeInt(unsigned long long arg);

	~UnsignedLargeInt(); 

	
	friend UnsignedLargeInt& operator+(const UnsignedLargeInt&, const UnsignedLargeInt&);

	friend UnsignedLargeInt& operator*(const UnsignedLargeInt&, const UnsignedLargeInt&);

	UnsignedLargeInt& operator+=(const UnsignedLargeInt&);

	UnsignedLargeInt& operator*=(const UnsignedLargeInt&);

	bool operator!();

	friend bool operator!=(const UnsignedLargeInt&, const UnsignedLargeInt&);

	friend bool operator==(const UnsignedLargeInt&, const UnsignedLargeInt&);

	friend bool operator>(const UnsignedLargeInt&, const UnsignedLargeInt&);

	friend bool operator<(const UnsignedLargeInt&, const UnsignedLargeInt&);

	friend bool operator<=(const UnsignedLargeInt&, const UnsignedLargeInt&);

	friend bool operator>=(const UnsignedLargeInt&, const UnsignedLargeInt&);

	UnsignedLargeInt& operator++(); //preincrement

	UnsignedLargeInt& operator++(int); //postincrement

	friend ostream& operator<<(ostream&, const UnsignedLargeInt&);

	//helper functions to grab the length and char array when the function cannot grab them itself 
	int getLength() const {
		return this->length;
	}
	char* getData() const {
		return this->data;
	}

	int getSize() const {
		return this->size;
	}
};

#endif