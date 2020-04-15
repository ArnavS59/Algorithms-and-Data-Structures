#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

enum Color
{
    RED,
    BLACK
};
struct Node
{
    int data;
    Color color;
    Node *left, *right, *parent;
};
class RedBlackTree
{
private:
    Node *root;

protected:
    void rotateLeft(Node *pt)
    {
        Node *pt_right = pt->right;

        pt->right = pt_right->left;

        if (pt->right != NULL)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_right;

        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;

        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }
    void rotateRight(Node *pt)
    {
        Node *pt_left = pt->left;

        pt->left = pt_left->right;

        if (pt->left != NULL)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_left;

        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;

        else
            pt->parent->right = pt_left;
        pt_left->right = pt;
        pt->parent = pt_left;
    }

public:
    RedBlackTree()
    {
        root = NULL;
    }
    void insert(int w)
    {
        Node *y = NULL;
        Node *x = root;
        Node *z = new Node;
        z->data = w;
        z->left = NULL;
        z->right = NULL;
        z->color = RED;
        while (x != NULL)
        {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == NULL)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;
        z->left = NULL;
        z->right = NULL;
        z->color = RED;
        RB_fixup(root, z);
    }

    void RB_fixup(Node *&root, Node *&temp)
    {
        if (temp == root)
        {
            root->color = BLACK;
            return;
        }
        Node *uncle;

        while (temp->parent != NULL && temp->parent->color == RED)
        {

            if (temp->parent == temp->parent->parent->left)
            {
                uncle = temp->parent->parent->right;
                if (uncle == NULL)
                {
                    if (temp == temp->parent->right)
                    {
                        temp = temp->parent;
                        rotateLeft(temp);
                    }
                    temp->parent->color = BLACK;
                    temp->parent->parent->color = RED;
                    rotateRight(temp->parent->parent);
                }
                else if (uncle->color == BLACK)
                {
                    if (temp == temp->parent->right)
                    {
                        temp = temp->parent;
                        rotateLeft(temp);
                    }
                    temp->parent->color = BLACK;
                    temp->parent->parent->color = RED;
                    rotateRight(temp->parent->parent);
                }
                else
                {

                    temp->parent->color = BLACK;
                    uncle->color = BLACK;
                    temp->parent->parent->color = RED;
                    temp = temp->parent->parent;
                }
            }

            else
            {

                uncle = temp->parent->parent->left;
                if (uncle == NULL)
                {

                    if (temp == temp->parent->left)
                    {
                        temp = temp->parent;
                        rotateRight(temp);
                    }

                    temp->parent->color = BLACK;
                    temp->parent->parent->color = RED;

                    rotateLeft(temp->parent->parent);
                }
                else if (uncle->color == BLACK)
                {
                    if (temp == temp->parent->left)
                    {
                        temp = temp->parent;
                        rotateRight(temp);
                    }
                    temp->parent->color = BLACK;
                    temp->parent->parent->color = RED;
                    rotateLeft(temp->parent->parent);
                }
                else
                {
                    temp->parent->color = BLACK;
                    uncle->color = BLACK;
                    temp->parent->parent->color = RED;
                    temp = temp->parent->parent;
                }
            }
            root->color = BLACK;
        }
    }
    void Transplant(Node *u, Node *v)
    {
        if (u->parent == NULL)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v != NULL)
            v->parent = u->parent;
    }

    void deletenode(Node *z)
    {
        Node *y, *x;
        int yOriginalcolor;

        y = z;
        yOriginalcolor = y->color;

        if (z->left == NULL)
        {
            x = z->right;
            Transplant(z, z->right);
        }

        else if (z->right == NULL)
        {
            x = z->left;
            Transplant(z, z->left);
        }
        else
        {
            y = findMinimum(z->right);
            yOriginalcolor = y->color;
            x = y->right;

            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if (yOriginalcolor == BLACK)
            rb_delete_fix_up(x);
    }

    void rb_delete_fix_up(Node *&x)
    {
        Node *w;
        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                w = x->parent->right;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    x->parent->color = BLACK;
                    x = x->parent;
                }
                else
                {
                    if (w->right->color == BLACK)
                    {
                        w->color = RED;
                        w->left->color = BLACK;
                        rotateRight(w);
                        w = x->parent->right;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    x->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            }
            else
            {
                w = x->parent->left;

                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = BLACK;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }

                if (w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    x->parent->color = BLACK;
                    x = x->parent;
                }
                else
                {

                    if (w->left->color == BLACK)
                    {
                        w->color = RED;
                        w->right->color = BLACK;
                        rotateLeft(w);
                        w = x->parent->left;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    void deleteN(int val)
    {
        Node *z = NULL;
        z = searchinBST(root, val);
        deletenode(z);
        cout << "Element deleted";
    }
    Node *predecessor(Node *&n)
    {
        if (n->left != NULL)
            return findMaximum(n->left);
        Node *p = n->parent;
        while (p != NULL && n == p->left)
        {
            n = p;
            p = p->parent;
        }
        return p;
    }
    Node *successor(Node *&n)
    {
        if (n->right != NULL)
            return findMinimum(n->right);
        Node *p = n->parent;
        while (p != NULL && n == p->right)
        {
            n = p;
            p = p->parent;
        }
        return p;
    }
    Node *getMaximum()
    {
        Node *x = root;
        while (x->right != NULL)
        {
            x = x->right;
        }
        return x;
    }
    Node *getMinimum()
    {
        Node *x = root;
        while (x->left != NULL)
        {
            x = x->left;
        }
        return x;
    }
    Node *findMinimum(Node *&root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
    Node *findMaximum(Node *&root)
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }
    Node *searchinBST(Node *root, int val)
    {
        if (root == NULL || root->data == val)
        {
            return root; //if root is null or the value to be searched is the rootitself
        }
        if (val > root->data)
        {
            return searchinBST(root->right, val);
        }
        else
        {
            return searchinBST(root->left, val);
        }
    }
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data;
        if (root->color == 0)
            cout << "RED"
                 << " ";
        else
            cout << "Black"
                 << " ";
        inorder(root->right);
    }
    void print()
    {
        inorder(root);
        cout << endl;
    }
    void search(int val)
    {
        cout << "Searching for element with value " << val << " in BST" << endl;
        searchinBST(root, val);
        if (searchinBST(root, val) == NULL)
        {
            cout << "Element not found" << endl;
        }
        else
        {
            cout << "Element " << searchinBST(root, val)->data << " found " << endl;
        }
    }
};

int main()
{
    RedBlackTree tree;
    tree.insert(13);
    tree.insert(44);
    tree.insert(37);
    tree.insert(7);
    tree.insert(22);
    tree.insert(16);
    cout << "Our red balck tree is" << endl;
    tree.print();
    tree.search(2);
    tree.search(13);
    cout << "Minimum element is " << tree.getMinimum()->data << endl;
    cout << "Maximum element is " << tree.getMaximum()->data << endl;
    tree.deleteN(13);
}