#include "xArray.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
int x;
cout << "Enter the size of the array" << endl;
cin >> x;

    while (x>0) {
        int* first = ReadInput(x);
        int* second = ReadInput(x);

        int dotProduct = DotProduct(first, second, x);

        cout << "Dot Product Result:" << dotProduct << endl;

        delete [] first;
        delete [] second;
        
        cout << "Enter the size of the next array" << endl;
        cin >> x;
    }
return 0;
}
