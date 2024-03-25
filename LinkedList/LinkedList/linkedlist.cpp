#pragma once
#include "linkedlist.h"
#include <iostream>

using namespace std;

linkedlist::linkedlist()
{
	this->head = nullptr;
	this->tail = nullptr;
	nNum = 0;
}
linkedlist::~linkedlist()
{
}
void linkedlist::InsertFirst(element* e) {
	if (this->head == nullptr)
		this->head = this->tail = e;
	else {
		e->Setpointer(this->head);
		this->head = e;
	}
	nNum++;
}
void linkedlist::InsertTail(element* e) {
	if (this->head == nullptr)
		this->head = this->tail = e;
	else {
		this->tail->Setpointer(e);
		this->tail = e;
	}
	nNum++;
}
void linkedlist::Travel() {
	element* p = this->head;
	while (p != nullptr) {
		cout << p->Getdata() << "\t";
		p = p->Getpointer();
	}
}
void linkedlist::DeleteFirst() {
	element* p = this->head;
	this->head = this->head->Getpointer();
	delete p;
	this->nNum--;
}

bool linkedlist::deleteTail() {
	if (this->nNum == 0) return false;
	if (this->nNum == 1) this->DeleteFirst();
	else {
		element* p = this->head;
		while (p->Getpointer()->Getpointer() != nullptr) p = p->Getpointer();
		delete this->tail;
		tail = p;
		tail->Setpointer(nullptr);
		this->nNum--;
		return true;
	}
}

bool linkedlist::deleteP(element* e)
{
	if (this->nNum == 0) return false;
	if (this->nNum == 1) this->DeleteFirst();
	else {
		element* p = this->head;
		element* prev = nullptr;
		while (p != nullptr) {
			if (p->Getdata() == e->Getdata() && p->Getpointer() == e->Getpointer()) {
				if (prev == nullptr) this->head = p->Getpointer();
				else prev->Setpointer(p->Getpointer());
				delete p;
				this->nNum--;
				return true;
			}
			prev = p;
			p = p->Getpointer();
		}
		cout << "Not have e in list!" << endl;
		return false;
	}
}

int linkedlist::sumList() {
	int sum = 0;
	element* p = this->head;
	while (p != nullptr) sum += p->Getdata();
	return sum;
}

int linkedlist::maxList() {
	int max = this->head->Getdata();
	element* p = this->head->Getpointer();
	while (p != nullptr) {
		if (p->Getdata() > max) max = p->Getdata();
		p = p->Getpointer();
	}
	return max;
}

int linkedlist::countList() {
	int count = 0;
	element* p = this->head;
	while (p != nullptr){
		count++;
		p = p->Getpointer();
	}
	return count;
}

int linkedlist::countSameElement(int x) {
	int count = 0;
	element* p = this->head;
	while (p != nullptr) {
		if (p->Getdata() == x) count++;
		p = p->Getpointer();
	}
	return count;
}

void linkedlist::posLinkedList(linkedlist* list) {
	int n; cout << "Number of nodes in list: "; cin >> n;
	for (int i = 0; i < n; i++) {
		bool flag = false;
		int value; cout << "Input value of element " << i << " :"; cin >> value;
		do {
			element* prev = this->head;
			while (prev != nullptr) {
				if (prev->Getdata() == value) {
					flag = true;
					break;
				}
				flag = false;
				prev = prev->Getpointer();
			}
			if (flag) {
				cout << "The value is already in list, re-input value of element: "; cin >> value;
			}
		} while (flag);
		element* e = new element();
		e->Setdata(value);
		list->InsertTail(e);
	}
}

void linkedlist::splitList(linkedlist* list, linkedlist* lessList, linkedlist* greateList, int x) {
	element* p = list->head;
	while (p != nullptr) {
		element* e = new element(p->Getdata());
		if (p->Getdata() < x) lessList->InsertTail(e);
		else if (p->Getdata() > x) greateList->InsertTail(e);
		p = p->Getpointer();
	}
}

