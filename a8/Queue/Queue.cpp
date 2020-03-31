#include <iostream>
#include <cstring>
#include "Stacks.h"
using namespace std;

template <class T>
class Queue
{
private:
    Stack<int> stack1;
    Stack<int> stack2;
    int size;

public:
    void enqueue(T element)
    {
        stack1.push(element);
        size++;
    }

    T dequeue()
    { //copy from stack 1 to stack 2 reverses the order and then simply pop from stack2
        if (stack2.isEmpty())
        {
            if (stack1.isEmpty() == true)
                cout << "Queue Underflow" << endl;

            while (stack1.isEmpty() != true)
            {
                int element = stack1.pop();
                stack2.push(element);
            }
        }
        this->size--;
        return stack2.pop();
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        else
            return false;
    }

    Queue()
    {
        this->size = 0;
    }
};

int main()
{
    Queue<int> q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
}





