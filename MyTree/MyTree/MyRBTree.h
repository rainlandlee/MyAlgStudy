#pragma once
#include "mysearchtree.h"

extern const int BLACK;
extern const int RED;

class MyRBTreeNode : MyTreeNode {
public:
    friend class MyRBTree;
    MyRBTreeNode(int k = 0, MyTreeNode* nil = NULL, int color = BLACK) : MyTreeNode(k, nil), m_color(color) { }

    virtual const int color() {  return m_color; }
    virtual void setColor(const int color) {    m_color = color; }
    
private:
    int m_color;
};

class MyRBTree :
    public MySearchTree
{
public:
    MyRBTree(void);
    virtual ~MyRBTree(void);
    MyTreeNode* del(MyTreeNode* x);
    virtual MyTreeNode* insert(int key);

private:
    void leftRotate(MyTreeNode* x);
    void rightRotate(MyTreeNode* x);
    void insertFixUp(MyTreeNode* x);
    void deleteFixUp(MyTreeNode* x);
};

