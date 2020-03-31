#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class Stack {
private:
    struct node {
        T data;
        node* next;
    };
    node* top;
    int size;
    int current_size;
public:
    Stack(int nsize)
    {
        this->size = nsize;
        current_size=0;
        top=NULL;
    }
    Stack(){
        this->size=-1;
        this->current_size=0;
        this->top=NULL;
    }
    void push(T element)
    {
        node *newelem = new node;
        newelem->data = element;
        if (current_size == 0)//empty
        {
            top = newelem;
            current_size++;
        }
        else
        {
            // If size set, check for overflow
            if (current_size + 1 <= size || size == -1)
            {
                newelem->next = top;
                current_size++;
                top = newelem;
            }
            else
            {
                cout << "Stack Overflow cannot add "<<element<<" into stack"<< endl;
            }
        }
    }

    T pop()
    {
        if (isEmpty() == true)
        cout<<"Stack Underflow"<<endl;

        else {
            current_size--;
            T value = top->data;
            node *temp=top;
            top = top->next;
            delete temp;
        return value;
        }
    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    
    void print()
    {
        node* ptr = top;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};