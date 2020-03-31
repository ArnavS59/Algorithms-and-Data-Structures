#include <iostream>
#include <list>
using namespace std;

class BST {
    struct node {
        int data;
        node* left;
        node* right;
    };
    node* root;
    //Function finds the midopint and creates a balanced BST recursivly
    node* sortedListToBST(int left, int right, node* t, int value)
    {
        if (left > right || right == 0)
            return NULL;
        int mid = (right + left) / 2; //finding the midpoint
        node* newnode = new node;
        newnode->data = value; //value
        newnode->left = sortedListToBST(left, mid - 1, newnode->left, value);
        newnode->right = sortedListToBST(mid + 1, right, newnode->right, value);
        return newnode;
    }s

public:
    BST()
    {
        root = NULL;
    }
    void bonus(int x)
    {
        root = sortedListToBST(0, 10, root, x);
    }
};

int main()
{
    BST bst;
    list<int> list1;
    for (int i = 0; i <= 10; i++) {
        list1.push_back(i);
    }
    list<int>::iterator iter;
    cout << "Calling the BST function for every linked list node" << endl;
    for (iter = list1.begin(); iter != list1.end(); iter++) {
        bst.bonus(*iter);
    }
    return 0;
}