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
        this->size = nsize; //Constant Time O(1)
        current_size=0;
        top=NULL;
    }
    Stack(){
        this->size=-1;
        this->current_size=0;//Constant Time O(1)
        this->top=NULL;
    }
    void push(T element)
    {
        node *newelem = new node;
        newelem->data = element;//Constant Time O(1)
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
        if (isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return top->data;
        }

        else {
            current_size--;
            T value = top->data;//Constant Time O(1)
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
        else//Constant Time O(1)
            return false;
    }
    
    void print()
    {
        node* ptr = top;
        while (ptr != NULL) {
            cout << ptr->data << " ";//Linear Time O(n) since we go through the stack fully once
            ptr = ptr->next;
        }
    }
};

int main()
{
    Stack<int> stack1(5);
    stack1.push(1);
    stack1.push(2);
    stack1.push(10);
    stack1.push(3);
    stack1.push(7);
    stack1.push(4);
    stack1.print();
    cout<<endl;
    cout<<"After popping all elements"<<endl;
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.print();
    return 0;
}