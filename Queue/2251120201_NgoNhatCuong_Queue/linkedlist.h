#pragma once
#define LINKEDLIST_H
#include "element.h"
class linkedList
{
private:
	element* head;
	element* tail;
public:
	linkedList();
	virtual ~linkedList();
	element* getHead() { return head; }
	void setHead(element* val) { head = val; }
	element* getTail() { return tail; }
	void setTail(element* val) { tail = val; }
	void insertFirst(element*);
	void insertTail(element*);
	void deleteFirst();
	void deleteTail();
	bool deleteP(element* e);
	void travel();
	//void importList(linkedList* list);
	//void print();
	//int calculateList(int x);
	//void add2List(linkedList* list1, linkedList* list2, linkedList* result);
	//linkedList multiply2List(linkedList* list1, linkedList* list2);
protected:
	int nNum;
};

