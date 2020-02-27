#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    T *arr;
    int size;
    int index;

public:
    Stack();
    ~Stack();
    Stack(const Stack &);
    Stack(int size);
    bool push(T element);
    bool pop(T &out);
    T back(void);
    int getNumEnteries();
    void print();
};

template <class T>
Stack<T>::Stack()
{
    size = 10;
    arr = new T[size];
    index = -1;
}

template <class T>
Stack<T>::Stack(const Stack &x)
{
    size = x.size;
    arr = new T[x.size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = x.arr[i];
    }
    index = x.index;
}

template <class T>
Stack<T>::Stack(int size1)
{
    size = size1;
    arr = new T[size];
    index = -1;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] arr;
}

template <class T>
bool Stack<T>::push(T element)
{
    if (index + 1 == size)
    {
        return false;
    }
    else
    {
        index=index+1;
        arr[index] = element;
        return true;
    }
}

template <class T>
bool Stack<T>::pop(T &out)
{
    if (index == -1){
        cout<<"Stack is now empty. No more elements can be popped further"<<endl;
        return false;
    }
    else
    {
        out=arr[index];
        index=index-1;
        return true;
        
    }
}

template <class T>
T Stack<T>::back()
{
    return arr[index];
}

template <class T>
int Stack<T>::getNumEnteries()
{
    return index+1;
}
