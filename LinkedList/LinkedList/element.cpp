#include "element.h"

using namespace std;

element::element()
{
	this->data = 0;
	this->pointer = nullptr;
}
element::element(int data)
{
	this->data = data;
	this->pointer = nullptr;
}
element::~element()
{
	
}
