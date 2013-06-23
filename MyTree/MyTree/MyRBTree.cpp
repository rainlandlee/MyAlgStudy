#include "MyRBTree.h"


MyRBTree::MyRBTree(MyRBTreeNode* nil)
    : MySearchTree(nil == NULL ? new MyRBTreeNode() : nil)
{
}


MyRBTree::~MyRBTree(void){
    if (m_root == m_nil) {
    	delete m_nil;
        m_root = m_nil = NULL;
    } else {
        cout<<"Not Empty Tree! (Memory Leaped)!"<<endl;
    }
}


void MyRBTree::insertFixUp( MyRBTreeNode* x )
{
    MyRBTreeNode *y;
    while ( x->p()->color() == RED) {
        if (x->p() == x->p()->p()->left()) {
            y = x->p()->p()->right();
        	if (y->color() == RED) {   // case1
        		x->p()->setColor(BLACK);
                y->setColor(BLACK);
                x->p()->p()->setColor(RED);
                x = x->p()->p();
        	} else {
                if (x == x->p()->right()) {  // case2 “之”字形
                    x = x->p();
                    leftRotate(x);
                }
                x->p()->setColor(BLACK);  // case3 直线型
                x->p()->p()->setColor(RED);
                rightRotate(x->p()->p());
            }
        } else {
            y = x->p()->p()->left();
            if (y->color() == RED) {    // case1
            	x->p()->setColor(BLACK);
                y->setColor(BLACK);
                x->p()->p()->setColor(RED);
                x = x->p()->p();
            } else {
                if (x == x->p()->left()) {   // case2
            	    x = x->p();
                    rightRotate(x);
                }
                x->p()->setColor(BLACK);  // case3
                x->p()->p()->setColor(RED);
                leftRotate(x->p()->p());
            }
        }
    }
    root()->setColor(BLACK);
}

MyTreeNode* MyRBTree::insert( int key ){
    // 不允许重复，如果存在则直接返回
    MyRBTreeNode* x = static_cast<MyRBTreeNode*>(search(key));
    if (x != m_nil) {
        return x;
    }

    x = static_cast<MyRBTreeNode*>(__super::insert(new MyRBTreeNode(key, m_nil, RED)));
    
    if (x == root()) {
    	x->setColor(BLACK);
    } else {
        insertFixUp(x);
    }

    return x;
}

MyTreeNode* MyRBTree::del( MyTreeNode* x ){
    bool needFixUp = ( static_cast<MyRBTreeNode*>(x)->color() == BLACK );
    MyRBTreeNode* z =  static_cast<MyRBTreeNode*>(__super::del(x));
    if (needFixUp) {
    	deleteFixUp(z);
    }
    return z;
}

void MyRBTree::deleteFixUp( MyRBTreeNode* x ){
    MyRBTreeNode* w;
    while (x != root() && x->color() == BLACK) {
        if (x == x->p()->left()) {
        	w = x->p()->right();
            if (w->color() == RED) {    // case1
            	w->setColor(BLACK);
                x->p()->setColor(RED);
                leftRotate(x->p());
                w = x->p()->right();
            }
            if (w->left()->color() == BLACK && w->right()->color() == BLACK) {  // case2
            	w->setColor(RED);
                x = x->p();
            } else {
                if (w->right()->color() == BLACK) {    // case3
                    w->left()->setColor(BLACK);
                    w->setColor(RED);
                    rightRotate(w);
                    w = x->p()->right();
                }
                w->setColor(x->p()->color());     //case4
                x->p()->setColor(BLACK);
                w->right()->setColor(BLACK);
                leftRotate(x->p());
                x = root();
            }
        } else {
            w = x->p()->left();
            if (w->color() == RED) {    // case1
            	w->setColor(BLACK);
                x->p()->setColor(RED);
                rightRotate(x->p());
                w = x->p()->left();
            }
            if (w->left()->color() == BLACK && w->right()->color() == BLACK) {  // case2
            	w->setColor(RED);
                x = x->p();
            } else {
                if (w->left()->color() == BLACK) {     //case3 
            	    w->right()->setColor(BLACK);
                    w->setColor(RED);
                    leftRotate(w);
                    w = x->p()->left();
                }
                w->setColor(x->p()->color());     // case4
                x->p()->setColor(BLACK);
                w->left()->setColor(BLACK);
                rightRotate(x->p());
                x = root();
            }
        }
    }
    x->setColor(BLACK);
}
