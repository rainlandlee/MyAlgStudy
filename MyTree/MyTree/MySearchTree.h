#pragma once
#include<iostream>

using namespace std;

const int BLACK = 0;
const int RED = 1;

class MyTreeNode {
public:
    friend class MySearchTree;
    MyTreeNode(int k = 0, MyTreeNode* nil = NULL)
        : key(k), p(nil), left(nil), right(nil) {
    }

    virtual const int color() {  return BLACK; }
    virtual void setColor(const int color) { }
    
//private:
    int key;
    MyTreeNode *p;
    MyTreeNode *left;
    MyTreeNode *right;
};

class MySearchTree {    

public:
    enum order_t {
        PRE,    // 前序
        IN,     // 中序
        POST    // 后续
    };

public:
    MySearchTree();             
    virtual ~MySearchTree();    
    void walk(order_t order);   //遍历
    MyTreeNode* search(int key);    
    MyTreeNode* min();
    MyTreeNode* max();
    MyTreeNode* successor(MyTreeNode* x);   //返回x的后继（中序）
    bool isEmpty();
    MyTreeNode* del(MyTreeNode* x);
    int size();
    virtual MyTreeNode* insert(int key);


protected:
    void inWalk(MyTreeNode* x);
    MyTreeNode* search(int key, MyTreeNode* x);
    MyTreeNode* min(MyTreeNode* x);
    MyTreeNode* max(MyTreeNode* x);
    MyTreeNode* insert(MyTreeNode* x);

protected:
    MyTreeNode* m_root;
    MyTreeNode* m_nil;
    int m_numNodes;
};