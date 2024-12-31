#ifndef NODESV_CPP
#include "NodeSV.h"

NodeSV::NodeSV()
{

    //ctor
    this->mssv = "";
    this->name = "";
    this->email = "";
    this->phone = "";
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
    this->bal = 0;
}
NodeSV::NodeSV(string mssv, string name, string email, string phone) {
    //ctor
    this->mssv = mssv;
    this->name = name;
    this->email = email;
    this->phone = phone;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
    this->bal = 0;
}
NodeSV::~NodeSV()
{
    //dtor
}
#endif // NODE_CPP