#include "BST.h"
#include <iostream>
#include <algorithm>

using namespace std;
BST::BST()
{
    //ctor
    this->root = nullptr;
}

BST::~BST()
{
    //dtor
}
bool BST::InsertNode(Node* n) {
    Node* p = this->root;
    Node* T = nullptr;
    if (root == nullptr)
    {
        this->root = n;
        return true;
    }
    while (p != nullptr) {
        T = p;

        if (p->Getkey() > n->Getkey())
            p = p->Getleft();
        else
            if (p->Getkey() < n->Getkey())
                p = p->Getright();
            else
                if (p->Getkey() == n->Getkey())
                    return false;
    }

    if (T->Getkey() > n->Getkey()) T->Setleft(n);
    else T->Setright(n);

    n->Setparent(T);
    return true;
}
bool BST::InsertNodeRe(Node* root, Node* p) {
    if (root == nullptr) {
        root = p;
        return true;
    }
    if (root->Getkey() == p->Getkey())
        return false;
    else if (root->Getkey() > p->Getkey())
        return InsertNodeRe(root->Getleft(), p);
    else return InsertNodeRe(root->Getright(), p);
}

void BST::NLR(Node* r) {
    if (r != nullptr) {
        cout << r->Getkey() << "\n";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}
void BST::LNR(Node* r) {
    if (r != nullptr) {
        LNR(r->Getleft());
        cout << r->Getkey() << "\n";
        LNR(r->Getright());
    }
}

void BST::LRN(Node* r) {
    if (r != nullptr) {
        LNR(r->Getleft());
        LNR(r->Getright());
        cout << r->Getkey() << "\n";
    }
}
void BST::TravelNLR() {
    NLR(this->root);
}
void BST::TravelLNR() {
    LNR(this->root);
}
void BST::TravelLRN() {
    LRN(this->root);
}
//Node* BST::search_x(Node* root, int k) {
//    if (this->root == nullptr) return this->root;
//    else {
//        if (root->Getkey() > k) return search_x(root->Getright(), k);
//        else return search_x(root->Getleft(), k);
//    }
//}

Node* BST::search_x(int k) {
    Node* p = this->root;
    while (p != nullptr) {
        if (p->Getkey() > k)
            p = p->Getleft();
        else
            if (p->Getkey() < k)
                p = p->Getright();
            else
                if (p->Getkey() == k)
                    return p;
    }
    return nullptr;
}

void BST::deleteNode(Node* n) {
    Node* p = n;
    if (p->Getleft() == nullptr && n->Getright() == nullptr) {
        // sinh vien code
        delete n;
    }
    else {
        if (p->Getright() != nullptr) {
            p = p->Getright();
            while (p->Getleft() != nullptr)//
                p = p->Getleft();
            n->Setkey(p->Getkey());
            //sinh vien code
            deleteNode(p);


        }
        else {
            p = p->Getleft();
            while (p->Getright() != nullptr)//
                p = p->Getright();

            n->Setkey(p->Getkey());
            //sinh vien code
            deleteNode(p);


        }
    }
}

int BST::SumTree(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    else {
        return n->Getkey() + SumTree(n->Getleft()) + SumTree(n->Getright());
    }
}

void BST::minMax() {
    Node* p = this->Getroot();
    Node* q = this->Getroot();
    while (p->Getleft() != nullptr) {
        p = p->Getleft();
    }
    cout << "Min: " << p->Getkey() << endl;

    while (q->Getright() != nullptr) {
        q = q->Getright();
    }
    cout << "Max: " << q->Getkey() << endl;
}

int BST::CountNode(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    else {
        return 1 + CountNode(n->Getleft()) + CountNode(n->Getright());
    }
}

int BST::countLeafNode(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    else if (n->Getleft() == nullptr && n->Getright() == nullptr) {
        // Node is a leaf node
        return 1;
    }
    else {
        // Non-leaf node, continue counting in both subtrees
        return countLeafNode(n->Getleft()) + countLeafNode(n->Getright());
    }
}


}
