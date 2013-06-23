#include "MySearchTree.h"
#include "MyRBTree.h"
#include <ctime>
#include <cstdlib>
#include <windows.h>

const int MAX = 20;

int main() {    
    // Test MySearchTree
    MySearchTree* msTree = new MySearchTree();
    cout<<"Test MySearchTree"<<endl;
    //cout<<(msTree->isEmpty() ?  "Empty tree" : "Not empty tree")<<endl;

    srand(time(NULL));
    time_t t1 = time(NULL);
    for (int i=0; i< MAX; i++) {
    	msTree->insert(rand());
    }
    time_t t2 = time(NULL);

    cout<<"Tree node number: "<<msTree->size()<<", time: "<<t2 - t1<<endl;
    //msTree->walk(MySearchTree::IN);
    //cout<<"\nDelete element "<<msTree->del(msTree->search(10))<<endl;
    //cout<<"Tree node number: "<<msTree->size()<<endl;
    cout<<endl;

    // Test MyRBTree

    MySearchTree* mrbTree = new MyRBTree();
    cout<<"Test MyRBTree"<<endl;
    //cout<<(mrbTree->isEmpty() ?  "Empty tree" : "Not empty tree")<<endl;

    t1 = time(NULL);
    for (int i=0; i< MAX; i++) {
        mrbTree->insert(rand());
    }
    mrbTree->insert(10);
    t2 = time(NULL);

    cout<<"Tree node number: "<<mrbTree->size()<<", time: "<<t2 - t1<<endl;
    mrbTree->walk(MySearchTree::InOrder);
    mrbTree->del(mrbTree->search(10));
    cout<<"\nDelete element 10"<<endl;
    cout<<"Tree node number: "<<mrbTree->size()<<endl;
    cout<<endl;

    int k = rand();
    t1 = time(NULL);
    msTree->search(k);
    t2 = time(NULL);
    cout<<"MySearchTree search("<<k<<"), time: "<<t2-t1<<endl;

    t1 = time(NULL);
    mrbTree->search(k);
    t2 = time(NULL);
    cout<<"MyRBTree search("<<k<<"), time: "<<t2-t1<<endl;

    //cin>>t1;
    return 0;
}