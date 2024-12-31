#include "queue.h"

using namespace std;

void queue::enqueue(int val)
{
	element* p = new element(val);
	this->list->insertFirst(p);
}

int queue::dequeue()
{
	int dataTail = this->list->getTail()->getData();
	this->list->deleteTail();
	return dataTail;
}

void queue::print()
{
	element* p = this->list->getHead();
	while (p != nullptr) {
		cout << p->getData() << "\t";
		p = p->getNext();
	}
	cout << endl;
}

bool queue::check()
{
	if (this->list->getHead() != nullptr) return true;
	return false;
}

void queue::addTail(int val)
{
	if (!this->check()) this->enqueue(val);
	else {
		int tempData = this->list->getHead()->getData();
		this->dequeue();
		this->addTail(val);
		this->enqueue(tempData);
	}
}

int queue::getFirst()
{
	if (this->list->getTail()->getPrev() != nullptr) return this->list->getTail()->getData();
	else {
		int tempData = this->list->getTail()->getData();
		this->dequeue();
		int FirstData = this->getFirst();
		this->enqueue(tempData);
		return FirstData;
	}
}
