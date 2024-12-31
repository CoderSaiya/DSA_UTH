#define STACK_H
#include "LinkedList.h"

class stack
{
private: int nNum;
       linkedList* list;
public:
    stack() { this->nNum = 0; this->list = new linkedList(); }
    virtual ~stack() {}
    void push(int);
    int pop();
    void print();
    bool check();
    void addTail(int p);
    int getTail();
    void decToBinary(int dec);
};
