#ifndef BST_H
#define BST_H
#include "Node.h"
class BST
{
public:
    BST();
    virtual ~BST();

    Node* Getroot() { return root; }
    void Setroot(Node* val) { root = val; }
    bool InsertNode(Node*);
    bool InsertNodeRe(Node*, Node*);
    void deleteNode(Node*);
    int SumTree(Node* n);
    void minMax();
    int CountNode(Node* n);
    int countLeafNode(Node* n);
    void countText(string t);
    void TravelNLR();
    void TravelLNR();
    void TravelLRN();
    void NLR(Node*);
    void LNR(Node*);
    void LRN(Node*);
    Node* search_x(int);

protected:

private:
    Node* root;
};

#endif // BST_H