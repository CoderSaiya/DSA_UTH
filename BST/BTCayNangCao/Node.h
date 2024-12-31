#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node();
    Node(int);
    virtual ~Node();

    Node* Getleft() { return left; }
    void Setleft(Node* val) { this->left = val; }
    Node* Getright() { return right; }
    void Setright(Node* val) { this->right = val; }
    Node* Getparent() { return parent; }
    void Setparent(Node* val) { this->parent = val; }
    int Getkey() { return key; }
    void Setkey(int val) { key = val; }

protected:

private:
    Node* left;
    Node* right;
    Node* parent;
    int key;
};

#endif