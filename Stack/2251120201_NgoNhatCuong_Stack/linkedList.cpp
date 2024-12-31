#pragma once
#include "linkedlist.h"
#include <iostream>
#include <algorithm>

using namespace std;

linkedList::linkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	nNum = 0;
}

linkedList::~linkedList()
{
}

void linkedList::insertFirst(element* e) {
	if (this->head == nullptr)
		this->head = this->tail = e;
	else {
		this->head->setPrev(e);
		e->setNext(this->head);
		this->head = e;
	}
	nNum++;
}

void linkedList::insertTail(element* e) {
	if (this->head == nullptr)
		this->head = this->tail = e;
	else {
		this->tail->setNext(e);
		this->tail = e;
	}
	nNum++;
}

void linkedList::travel() {
	element* p = this->head;
	while (p != nullptr) {
		cout << p->getData() << "\t";
		p = p->getNext();
	}
}

void linkedList::deleteFirst() {
	element* p = this->head;
	this->head = this->head->getNext();
	delete p;
	this->nNum--;
}

void linkedList::deleteTail() {
	element* p = this->tail;
	this->tail = this->tail->getPrev();
	delete p;
	this->nNum--;
}

bool linkedList::deleteP(element* e)
{
	if (this->nNum == 0) return false;
	if (this->nNum == 1) this->deleteFirst();
	else {
		e->getPrev()->setNext(e->getNext());
		e->getNext()->setPrev(e->getPrev());
		delete e;
		return true;
	}
}

//void linkedList::importList(linkedList* list) {
//	int n; cout << "\nNumber of nodes in list: "; cin >> n;
//	for (int i = 0; i < n; i++) {
//		element* e = new element();
//		int name; cout << "Input value of element " << i + 1 << " :"; cin >> value;
//		e->setData(value);
//		list->insertTail(e);
//	}
//}
//
//void linkedList::print() {
//	element* p = this->head;
//	int i = nNum - 1;
//	cout << "f(x) = ";
//	while (p != nullptr) {
//		if (p->getData() != 0) {
//			cout << (p->getData() < 0 ? "- " : p == head ? "" : " + ");
//			if (i != 0) cout << abs(p->getData()) << "x^" << i;
//			else cout << abs(p->getData());
//		}
//		p = p->getNext();
//		i--;
//	}
//}
//
//int linkedList::calculateList(int x) {
//	int result = 0, i = nNum - 1;
//	element* p = this->head;
//	while (p != nullptr) {
//		result += p->getData() * pow(x, i);
//		p = p->getNext();
//		i--;
//	}
//	return result;
//}
//
//void linkedList::add2List(linkedList* list1, linkedList* list2, linkedList* result) {
//	element* p1 = list1->getTail();
//	element* p2 = list2->getTail();
//	element* p;
//	while (p1 != nullptr && p2 != nullptr) {
//		p = new element(p1->getData() + p2->getData());
//		result->insertFirst(p);
//		p1 = p1->getPrev();
//		p2 = p2->getPrev();
//	}
//	while (p1 != nullptr) {
//		p = new element(p1->getData());
//		result->insertFirst(p);
//		p1 = p1->getPrev();
//	}
//	while (p2 != nullptr) {
//		p = new element(p2->getData());
//		result->insertFirst(p);
//		p2 = p2->getPrev();
//	}
//}
//
//linkedList linkedList::multiply2List(linkedList* list1, linkedList* list2) {
//	linkedList result;
//
//	element* p1 = list1->getHead();
//	while (p1 != nullptr) {
//		element* p2 = list2->getHead();
//		while (p2 != nullptr) {
//			int coeff1 = p1->getData();
//			int coeff2 = p2->getData();
//			int product = coeff1 * coeff2;
//
//			int exponent1 = 0;
//			element* p3 = p1->getNext();
//			while (p3 != nullptr) {
//				exponent1++;
//				p3 = p3->getNext();
//			}
//
//			int exponent2 = 0;
//			element* p4 = p2->getNext();
//			while (p4 != nullptr) {
//				exponent2++;
//				p4 = p4->getNext();
//			}
//			int exponent = exponent1 + exponent2;
//
//			element* temp = new element(product);
//			result.insertTail(temp);
//
//			while (exponent > 0) {
//				element* zero = new element(0);
//				result.insertTail(zero);
//				exponent--;
//			}
//
//			p2 = p2->getNext();
//		}
//		p1 = p1->getNext();
//	}
//
//	return result;
//}


