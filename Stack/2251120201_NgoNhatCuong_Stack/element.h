#pragma once
#include <iostream>

class element
{
private:
	int data;
	element* prev;
	element* next;
public:
	element() { data = 0; prev = next = nullptr; }
	element(int val) { data = val; prev = next = nullptr; }
	int getData() { return data; }
	void setData(int val) { data = val; }
	element* getPrev() { return prev; }
	void setPrev(element* val) { prev = val; }
	element* getNext() { return next; }
	void setNext(element* val) { next = val; }
	virtual ~element();
protected:
};

