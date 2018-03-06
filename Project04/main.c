#include "PQ.h"
#include <iostream>

#include <stdlib.h>     /* for random number generation */

#include <time.h>       /* time for random seed*/

using namespace std;

int main(){

        PQ pq;

        /* initialize random seed: */

        srand (time(NULL));

        for (int i = 1; i < 10; ++i) pq.Push(rand() % 100 + 1);

        Node * p = pq.tail;

        while(p != pq.head){

                cout << p->val << endl;

                p = p->prev;

        }

        for (int i = 0; i < 10; i++) cout << pq.Pop() << ", ";

}