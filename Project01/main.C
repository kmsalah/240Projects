#include <iostream>
using namespace std;

int main() {
    int N, i, j;
    cout << "Please input a number >= 3: ";
    cin >> N;
    if (N < 3) {
        cout << "Your input is smaller than 3, quit\n";
        return 1;
    }

    for (i = 0; i <= N; i++) {
        //leading space
        for (j = 0; j < i; j++) {
            cout << " ";
        }
        //first N *
        for (j = 0; j < N; j++) {
            cout << "*";
        }
        //middle 2(N-i) spaces
        for (j = 0; j < 2 * (N - i); j++) {
            cout << " ";
        }
        //second N *
        for (j = 0; j < N; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
