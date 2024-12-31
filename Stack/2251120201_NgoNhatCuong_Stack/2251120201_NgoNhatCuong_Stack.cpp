#include "stack.h"
#include <iostream>

using namespace std;

int main()
{

    stack* s = new stack();
    s->push(7);
    s->push(10);
    s->push(18);
    s->push(20);
    s->print();
    s->pop();
    cout << "\n";
    s->print();
    s->pop();
    s->pop();
    s->pop();
    if (s->check()) s->print();
    else cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
    s->push(7);
    s->push(10);
    s->addTail(2);
    cout << s->getTail() << endl;
    s->print();

    stack* s2 = new stack();
    s2->decToBinary(120);
    s2->print();

    return 0;
}

