#pragma once
#include<iostream>

using namespace std;


class MyTreeNode {
public:
    MyTreeNode(int k = 0, MyTreeNode* nil = NULL)
        : key(k), p(nil), left(nil), right(nil) {
    }
    
//protected:
public:
    int key;
    MyTreeNode *p;
    MyTreeNode *left;
    MyTreeNode *right;
};

class MySearchTree {    

public:
    enum order_t {
        PreOrder,    // ǰ��
        InOrder,     // ����
        PostOrder    // ����
    };

public:
    MySearchTree(MyTreeNode* nil = NULL);             
    virtual ~MySearchTree();    
    void walk(order_t order);   //����
    MyTreeNode* search(int key);    
    MyTreeNode* min();
    MyTreeNode* max();
    MyTreeNode* successor(MyTreeNode* x);   //����x�ĺ�̣�����
    bool isEmpty();
    int size();
    virtual MyTreeNode* del(MyTreeNode* x);
    virtual MyTreeNode* insert(int key);


protected:
    MyTreeNode* search(int key, MyTreeNode* x);
    MyTreeNode* min(MyTreeNode* x);
    MyTreeNode* max(MyTreeNode* x);
    MyTreeNode* insert(MyTreeNode* x);
    void leftRotate(MyTreeNode* x);
    void rightRotate(MyTreeNode* x);

private:
    void inWalk(MyTreeNode* x);

protected:
    MyTreeNode* m_root;
    MyTreeNode* m_nil;
    int m_numNodes;
};