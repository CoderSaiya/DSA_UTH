#ifndef NODE_CPP
#include "Node.h"

Node::Node()
{

    //ctor
    this->word = "";
    this->meaning = "";
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
    this->bal = 0;
}
Node::Node(string word, string meaning) {
    //ctor
    this->word = word;
    this->meaning = meaning;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
    this->bal = 0;
}
Node::~Node()
{
    //dtor
}
#endif // NODE_CPP