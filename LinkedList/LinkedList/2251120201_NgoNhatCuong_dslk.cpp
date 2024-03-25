#include <iostream>
#include "linkedlist.h"
using namespace std;
int main()
{
	linkedlist* list_ = new linkedlist();
	/*element* e = new element();*/
	/*e = new element(9);
	list_->InsertTail(e);
	e = new element(10);
	list_->InsertTail(e);
	e = new element(8);
	list_->InsertTail(e);*/
	list_->posLinkedList(list_);
	list_->Travel();
	linkedlist* lessList = new linkedlist();
	linkedlist* greateList = new linkedlist();
	cout << endl;
	int x; cout << "Input x: "; cin >> x;
	list_->splitList(list_, lessList, greateList, x);
	lessList->Travel(); cout << endl;
	greateList->Travel();

	/*element* f;
	f = new element();
	f->Setdata(10);
	f->Setpointer(e);
	cout << endl;
	cout<<list_->countList();
	list_->deleteP(f);
	list_->Travel();
	cout << endl;
	list_->DeleteFirst();
	cout << list_->countList();
	cout << "\n";
	list_->deleteTail();
	cout << "\n";
	list_->Travel();*/
	return 0;
}