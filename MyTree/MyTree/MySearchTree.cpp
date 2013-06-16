#include "MySearchTree.h"

MySearchTree::MySearchTree() :m_root(NULL), m_nil(NULL), m_numNodes(0){}

MySearchTree::~MySearchTree() {
    if (m_root) {
        cout<<"Not Empty Tree! (Memory Leaped)!"<<endl;
    }
}

void MySearchTree::walk(order_t order) {
    switch(order) {
    case PRE:
        break;
    case IN:
        inWalk(m_root);
        break;
    case POST:
        break;
    default:
        break;
    }
}

void MySearchTree::inWalk(MyTreeNode* x) {
    if(x != m_nil) {
        inWalk( x->left );
        cout<<x->key <<"\t";
        inWalk( x->right );
    }
}

MyTreeNode* MySearchTree::search(int key) {
    return search(key, m_root);
}

MyTreeNode* MySearchTree::search( int key, MyTreeNode* x ){
    while (x != m_nil && key != x->key) {
        x = key < x->key ? x->left : x->right;
    }
    return x;
}

MyTreeNode* MySearchTree::min() {
    return min(m_root);
}

MyTreeNode* MySearchTree::min( MyTreeNode* x ){
    while (x->left != m_nil) {
        x = x->left;
    }
    return x;
}

MyTreeNode* MySearchTree::max() {
    return max(m_root);
}

MyTreeNode* MySearchTree::max( MyTreeNode* x ) {
    while (x->right != m_nil) {
        x = x->right;
    }
    return x;
}

MyTreeNode* MySearchTree::successor( MyTreeNode* x ){
    if (x->right != m_nil) {
        return min(x->right);
    }

    while (x->p != m_nil && x == x->p->right) {
        x = x->p;
    }

    return x->p;
}

bool MySearchTree::isEmpty(){
    return m_root == m_nil;
}

MyTreeNode* MySearchTree::insert( int key ){
    // 不允许重复，如果存在则直接返回
    MyTreeNode* x = search(key);
    if (x != m_nil) {
        return x;
    }
    
    return insert(new MyTreeNode(key, m_nil));
}

MyTreeNode* MySearchTree::insert( MyTreeNode* z ) {

    if (isEmpty()) {
        m_numNodes++;
        return m_root = z;
    }

    MyTreeNode* x = m_root;
    MyTreeNode* y = m_nil;
    while (x != m_nil) {
        y = x;
        x = z->key < x->key ? x->left : x->right;
    }
    z->p = y;
    z->key < y->key ? y->left = z : y->right = z;

    m_numNodes++;

    return z;

}

// 不考虑x异常情况
MyTreeNode* MySearchTree::del( MyTreeNode* x ){
    MyTreeNode *y, *z;  // y 指向将要删除的节点，z用作暂存
    if (x->left == m_nil || x->right == m_nil) {
    	y = x;
    } else {
        y = successor(x);
    }
    if (y->left != m_nil) {
    	z = y->left;
    } else {
        z = y->right;
    }
    if (z != m_nil) {
        z->p = y->p;    	
    }

    if (x == m_root) {
    	m_root = z;
    } else if (y == y->p->left) {
    	y->p->left = z;
    } else {
        y->p->right = z;
    }

    if (y != x) {
    	x->key = y->key;
    }

    m_numNodes--;
    delete y;

    return z;
}

int MySearchTree::size(){
    return m_numNodes;
}
