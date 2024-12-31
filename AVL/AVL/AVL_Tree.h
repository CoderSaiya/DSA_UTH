
#ifndef AVL_TREE_H
#pragma once
#define AVL_TREE_H
#include "Node.h"

class AVL_tree
{
public:
    AVL_tree();
    virtual ~AVL_tree();
    Node* Getroot() { return root; }
    void Setroot(Node* val) { root = val; }
    bool InsertNode(Node*);
    Node* InsertNode(Node*, Node*);
    void InsertNodeRe(Node*);
    void deleteNode(Node*);
    void TravelNLR();
    void TravelLNR();
    void TravelLRN();
    void NLR(Node*);
    void LNR(Node*);
    void LRN(Node*);
    void RemoveAll(Node* root);
    void LeftRotate(Node*&);
    void RightRotate(Node*&);
    int CheckBal(Node*);
    int GetHeight(Node*);
    int getCountCompare();
    Node* search_x(string);
    void outFile(Node* p, ofstream& of);

protected:

private:
    Node* root;

    int nNum; // Node number of tree
    int height; //height of tree
    int count;

};

#endif // AVL_TREE_H
