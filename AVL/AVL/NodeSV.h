#pragma once
#include <string>
#ifndef NODESV_H
#define NODESV_H

using namespace std;

class NodeSV
{
public:
    NodeSV();
    NodeSV(string, string, string, string);
    virtual ~NodeSV();

    NodeSV* Getleft() { return left; }
    void Setleft(NodeSV* val) { left = val; }
    NodeSV* Getright() { return right; }
    void Setright(NodeSV* val) { right = val; }
    NodeSV* Getparent() { return parent; }
    void Setparent(NodeSV* val) { parent = val; }
    string Getmssv() { return mssv; }
    void Setkey(string val) { mssv = val; }
    int Getheight() { return height; }
    void Setheight(int val) { height = val; }
    string GetName() { return name; }
    void SetName(string val) { name = val; }
    string GetEmail() { return email; }
    void SetEmail(string val) { email = val; }
    string GetPhone() { return phone; }
    void SetPhone(string val) { phone = val; }


protected:

private:
    NodeSV* left;
    NodeSV* right;
    NodeSV* parent;
    int bal; // -1 0 1
    string mssv;
    string name;
    string email;
    string phone;
    int height;
};

#endif // NODESV_H
