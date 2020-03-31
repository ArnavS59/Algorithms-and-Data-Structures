#include <iostream>
#include <cstring>
#include <list>
#include<stdio.h> 

using namespace std;
list <int>list_a; //USing the stl list container to initialize a list
class BST {
    
    struct node {
        int data;
        node* left;
        node* right;
    };
    node* root;
    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        list_a.push_back(t->data);//inorder traverserall goes in sorted direction therfore we insert the elements as we traverse the BST simulteanusly.
        inorder(t->right);
    }
    public:
    BST() {
        root = NULL;
    }


    void insert(int x) {
        root = insert(x, root);
    }

    void ConvertBST_tosortedlist() {
        inorder(root);
        cout << endl;
    }

};

int main() {
    BST t;
    cout<<"Inserted elements into the binary search tree"<<endl;
    t.insert(20);
    t.insert(102);
    t.insert(9);
    t.insert(10);
    t.insert(0);
    t.insert(2);
    t.insert(3);
    t.insert(27);
    t.ConvertBST_tosortedlist();

list <int >:: iterator iter; //Printing the list 
cout<<"Printing out the linked list"<<endl;
for(iter=list_a.begin();iter!=list_a.end();iter++){
    cout<<*iter<<" ";
}

    return 0; 
}



