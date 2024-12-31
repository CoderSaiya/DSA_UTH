#pragma once
#include <string>
#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
public:
    Node();
    Node(string,string);
    virtual ~Node();

    Node* Getleft() { return left; }
    void Setleft(Node* val) { left = val; }
    Node* Getright() { return right; }
    void Setright(Node* val) { right = val; }
    Node* Getparent() { return parent; }
    void Setparent(Node* val) { parent = val; }
    string Getkey() { return word; }
    void Setkey(string val) { word = val; }
    int Getheight() { return height; }
    void Setheight(int val) { height = val; }
    string GetMeaning() { return meaning; }
    void SetMeaning(string meaning) { this->meaning = meaning; }


protected:

private:
    Node* left;
    Node* right;
    Node* parent;
    int bal; // -1 0 1
    string word;
    string meaning;
    int height;
};

#endif // NODE_H

