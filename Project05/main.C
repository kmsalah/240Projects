#include <iostream>

#include "UnsignedLargeInt.h"

using namespace std;



int main () {
/*
        unsigned long long c = 1000000;

        unsigned long long d = 3000;

        UnsignedLargeInt a(d),q(d), b(c);

        cout << "B " << b << endl;
        cout << "A" << a << endl;
        cout << "D" << d << endl;
       	++a;

        cout << " incremented a " << a << endl;

        b++;
        cout << "incremented b" << b << endl;

        //++a;

        //cout << a << endl;

        UnsignedLargeInt bob = b + q;
        cout << "bob "<<bob << endl;
       	a += b;
        cout << " new A" << a << endl;

        if(a > b) {
                cout << "a is bigger than b" << endl;

        }

        if (d < b) {
        	cout << "d is smaller than b" << endl;
        }

        if(a <= b) {
        	cout << "a is less than or equal to b" << endl;
        }else {
        	cout << "a is not less than or equal to b" << endl;
        }

        if(a != b) {

                cout << "a is not equal to b" << endl;
        }

        unsigned long long r = 5;

        UnsignedLargeInt test(r),fry(r);

        if(test == fry) {
        	cout << "test and fry are equal" << endl;
        }


        // you can test all other boolean operators here
        */
	 unsigned long long c = 1000000;

        UnsignedLargeInt a, b(c);
        cout << "UnsignedLargeInt B: " ;

        cout <<  b << endl;

        a++;
        cout << "UnsignedLargeInt A: ";
        cout <<  a << endl;

        ++a;

        cout << "Incremented A ";
        cout << a << endl;

        a += b;

        cout << "A+=B: "<< a << endl;

        if(a > b) {

                cout << "a is bigger than b" << endl;

        }



        if(a != b) {

                cout << "a is not equal to b"<< endl;

        }



        if(a <= b) {
        	cout << "a is less than or equal to b" << endl;
        }else {
        	cout << "a is not less than or equal to b" << endl;
        }

        if(a != b) {

                cout << "a is not equal to b" << endl;
        }

        unsigned long long r = 5;

        UnsignedLargeInt x(r),y(r);

        cout << "UnsignedLarge Int X " << x << " UnsignedLargeInt Int Y: " << y  << endl;

        if(x == y) {
        	cout << "test and fry are equal" << endl;
        }
        // you can test all other boolean operators here


}