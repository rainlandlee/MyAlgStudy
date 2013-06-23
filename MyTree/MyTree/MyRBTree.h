#pragma once
#include "mysearchtree.h"

const int BLACK = 0;
const int RED = 1;

class MyRBTreeNode : MyTreeNode {
public:
    friend class MyRBTree;
    MyRBTreeNode(int k = 0, MyTreeNode* nil = NULL, int color = BLACK) : MyTreeNode(k, nil), m_color(color) { }

private:
    const int color() {  return m_color; }
    void setColor(const int color) {    m_color = color; }

private:
    MyRBTreeNode* p()        { return static_cast<MyRBTreeNode*>(__super::p); }
    MyRBTreeNode* left()     { return static_cast<MyRBTreeNode*>(__super::left); }
    MyRBTreeNode* right()    { return static_cast<MyRBTreeNode*>(__super::right); }
    
private:
    int m_color;
};

class MyRBTree :
    public MySearchTree
{
public:
    MyRBTree(MyRBTreeNode* nil = NULL);
    virtual ~MyRBTree();
    virtual MyTreeNode* del(MyTreeNode* x);
    virtual MyTreeNode* insert(int key);

private:
    void insertFixUp(MyRBTreeNode* x);
    void deleteFixUp(MyRBTreeNode* x);
    MyRBTreeNode* root() { return static_cast<MyRBTreeNode*>(m_root); }
};

