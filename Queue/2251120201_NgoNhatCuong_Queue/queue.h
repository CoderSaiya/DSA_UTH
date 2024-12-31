#pragma once
#define QUEUE_H
#include "linkedlist.h"
class queue
{
	int nNum;
	linkedList* list;
public:
	queue() { this->nNum = 0; this->list = new linkedList(); }
	virtual ~queue() {}
	void enqueue(int val);
	int dequeue();
	void print();
	bool check();
	void addTail(int val);
	int getFirst();
};

