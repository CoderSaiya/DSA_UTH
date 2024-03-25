#pragma once
#define LINKEDLIST_H
#include "element.h"
class linkedlist
{
private:
	element* head;
	element* tail;
public:
	linkedlist();
	virtual ~linkedlist();
	element* Gethead() { return head; }
	void Sethead(element* val) { head = val; }
	element* Gettail() { return tail; }
	void Settail(element* val) { tail = val; }
	void InsertFirst(element*);
	void InsertTail(element*);
	void DeleteFirst();
	bool deleteTail();
	bool deleteP(element* p);
	void Travel();
	int sumList();
	int maxList();
	int countList();
	int countSameElement(int x);
	void posLinkedList(linkedlist* list);
	void splitList(linkedlist* list, linkedlist* lessList, linkedlist* greatList, int x);
protected:
	int nNum;
};

