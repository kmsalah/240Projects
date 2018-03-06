/*
Khalid Salah
Project 5
*/


#include "UnsignedLargeInt.h"
#include <stdio.h>
#include <string.h>


UnsignedLargeInt::UnsignedLargeInt() {
	size = 1;
	data = new char[size];
	data[0] = 0;
	length = 1;
}

//copy constructor
UnsignedLargeInt::UnsignedLargeInt(const UnsignedLargeInt &copyInt) {

	data = new char[copyInt.length]; //allocate memory of data to be same size as what we are copying
	for (int i = 0; i < copyInt.length; i++ ) {
		data[i] = copyInt.getData()[i];
	}
	length = copyInt.length; //set the length to the same length we're copying
	size = copyInt.size;

}

UnsignedLargeInt::UnsignedLargeInt(unsigned long long copy) {
	//this block of code gives me the length of the long long
	unsigned long long tmp = copy;

	int count = 0;
	while (tmp != 0) {
		tmp /= 10;
		++count;
	}

	data = new char[count];

	int counter = 0;

	unsigned long long boo = copy;
	for (int i = 0; i < count; i++) {
		int j = boo % 10;
		boo /= 10;
		data[i] = j;
	}

	size = count;
	length = count;

}

UnsignedLargeInt::~UnsignedLargeInt() {
	delete[] data;
}

/*
static int UnsignedLargeInt::Compare(const UnsignedLargeInt& one, const UnsignedLargeInt& two) {

	if(one.length > two.length) {
		return 1;
	} else if(one.length < two.length) {
		return -1;
	} else { //they are the same length
		for(int i =one.length-1; i<=0; i--) {
			if(one.data[i] > two.data[i]) {
				return 1;
			}else if (one.data[i] < two.data[i]) {
				return -1;
			}
		}
	}
	return 0;
}
*/

UnsignedLargeInt& operator+(const UnsignedLargeInt& one, const UnsignedLargeInt& two) {

	UnsignedLargeInt* sum = new UnsignedLargeInt(); // create new unsigned large int 
	sum->length = 0;

	if (one.getLength() > two.getLength()) { //if the first one is longer than the second one


		char * tmp = new char[one.getLength() + 1]; //new char array of the longer one + 1
		int carry = 0;

		for (int i = 0; i < two.getLength(); i++) { //to the length of the short one, add the values 
			int j = one.data[i] + two.data[i] + carry;
			carry = j / 10;
			j = j % 10;
			tmp[i] = j;
			sum->length++;

		}
		for (int i = two.getLength(); i < one.getLength(); i++) { //from short to long, add the remaining longer one values
			int j = one.data[i] + carry;
			carry = j / 10;
			j = j % 10;
			tmp[i] = j;

			sum->length++;

		}
		if (carry > 0) {
			tmp[one.getLength()] = carry;

			sum->length++;
		}

		sum->data = tmp;

	}
	else {//two is longer
		char *tmp = new char[two.getLength() + 1];

		int carry = 0;
		for (int i = 0; i < one.getLength(); i++) {
			int j = one.data[i] + two.data[i] + carry;
			carry = j / 10;
			j = j % 10;
			tmp[i] = j;

			sum->length++;

		}
		for (int i = one.getLength(); i < two.getLength(); i++) {
			int j = two.data[i] + carry;
			carry = j / 10;
			j = j % 10;
			tmp[i] = j;

			sum->length++;

		}
		if (carry > 0) {
			tmp[two.getLength()] = carry;
			sum->length++;
		}
		sum->data = tmp;
	}
	return *sum;
}

UnsignedLargeInt& UnsignedLargeInt::operator+=(const UnsignedLargeInt& one) {
	if (one.length > this->length) {
		this->length = 0;
		int carry = 0;

		for (int i = 0; i < one.length; i++) {
			int j = one.data[i] + this->data[i] + carry;
			carry = j / 10;
			j = j % 10;
			this->data[i] = j;

			this->length++;
		}
	}
	else {//this is longer
		this->length = 0;
		int carry = 0;
		for (int i = 0; i < this->length; i++) {
			int j = one.data[i] + this->data[i] + carry;
			carry = j / 10;
			j = j % 10;
			this->data[i] = j;

			this->length++;
		}
	}
	return *this;
}



bool UnsignedLargeInt::operator!() {
	if(this->length < 0) {
		return true;
	}
	return false;
}


bool operator!=(const UnsignedLargeInt& one, const UnsignedLargeInt& two) {
	if (UnsignedLargeInt::Compare(one, two) != 0) return true;

	return false;
}

bool operator==(const UnsignedLargeInt& one, const UnsignedLargeInt& two) {
	if (UnsignedLargeInt::Compare(one, two) == 0) return true;

	return false;
}

bool operator>(const UnsignedLargeInt& one, const UnsignedLargeInt& two) {
	if (UnsignedLargeInt::Compare(one, two) > 0) return true;

	return false;
}

bool operator<(const UnsignedLargeInt& one , const UnsignedLargeInt& two)  {
	if (UnsignedLargeInt::Compare(one, two) < 0) return true;

	return false;
}

bool operator<=(const UnsignedLargeInt& one, const UnsignedLargeInt& two) {
	if (UnsignedLargeInt::Compare(one, two) <= 0) return true;

	return false;
}

bool operator>=(const UnsignedLargeInt& one, const UnsignedLargeInt& two) {
	if (UnsignedLargeInt::Compare(one, two) >= 0) return true;

	return false;
}


UnsignedLargeInt& UnsignedLargeInt::operator++() {
	UnsignedLargeInt sam(1);
	*this = *this + sam;
	return *this;
}


UnsignedLargeInt& UnsignedLargeInt::operator++(int x) {
	UnsignedLargeInt sam(1);
	UnsignedLargeInt frank = *this;
	*this = *this + sam;

	return frank;
}

ostream& operator<<(ostream& out, const UnsignedLargeInt& one) {
	char* hold = one.getData();
	for (int i = one.getLength() - 1; i >= 0; i--) {
		out << (int) hold[i];
	}

	return out;
}