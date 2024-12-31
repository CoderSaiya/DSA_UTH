#include "stack.h"
#include <iostream>

using namespace std;

void stack::push(int val) {
	element* p = new element(val);
	this->list->insertFirst(p);
}

int stack :: pop() {
	int val = this->list->getHead()->getData();
	this->list->deleteFirst();
	return val;
}

void stack::print()
{
	element* p = this->list->getHead();
	while (p != nullptr) {
		cout << p->getData() << "\t";
		p = p->getNext();
	}
	cout << endl;
}

bool stack::check() {
	if (this->list->getHead() != nullptr) return true;
	return false;
}

void stack::addTail(int p)
{
	/*stack* temp = new stack();
	while (this->check()) {
		temp->push(this->list->getHead()->getData());
		this->pop();
	}
	this->push(p);
	while (temp->check()) {
		this->push(temp->list->getHead()->getData());
		temp->pop();
	}*/

	if (!this->check()) this->push(p);
	else {
		int tempData = this->list->getHead()->getData();
		this->pop();
		this->addTail(p);
		this->push(tempData);
	}
}

int stack::getTail()
{
	if (this->list->getHead()->getNext() == nullptr)
		return this->list->getHead()->getData();
	else {
		int tempData = this->list->getHead()->getData();
		this->pop();
		int tailData = this->getTail();
		this->push(tempData);
		return tailData;
	}
}

void stack::decToBinary(int dec) {
	if (dec == 0) {
		if (!this->check()) this->push(0);
		return;
	}
	else {
		this->push(dec % 2);
		decToBinary(dec / 2);
	}
}
