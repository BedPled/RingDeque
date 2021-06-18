#include <iostream>
#include "RingDeque.h"
using namespace std;
int main() {
    RingDeque A(5);

    A.pushFront(5);

    cout << endl;
    A.printDeque();

    return 0;
}