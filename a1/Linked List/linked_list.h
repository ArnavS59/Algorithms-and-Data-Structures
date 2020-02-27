#include <cstring>
#include <iostream>
#include <list>

using namespace std;

template <class T>
class double_list
{
private:
    struct node
    {
        T data;
        node *prev;
        node *next;
    };
    node *head;
    node *tail;
    int counter;

public:
    double_list()
    {
        head = NULL;
        tail = NULL;
        counter=0;
    }
   
    ~double_list()
    {
        node *temp;
        while (head->next != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(T element)
    {
        node *newItem = new node;
        newItem->data= element;
        newItem->prev=NULL;
        newItem->next=NULL;
        counter++;
        if (head == NULL)
        {
            head = newItem;
            tail = newItem;
        }
        else
        {
            head->prev = newItem;
            newItem->next = head;
            head = newItem;
        }
    }

    void push_end(T element)
    {
        node *newItem = new node;
        newItem->data= element;
        newItem->prev=NULL;
        newItem->next=NULL;
        counter++;
        if (head == NULL)
        {
            head = newItem;
        }
        else
        {

            tail->next = newItem;
            newItem->prev = tail;
        }
        tail = newItem;
    }

    void pop_front()
    {
        if (head == NULL){
         cout<<"List is empty you cant do anything push some values"<<endl;
            return;
        }
        else
        {
            counter--;
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void pop_end()
    {
        if (head == NULL)
            return;
        else
        {
            counter--;
            node *temp = tail;
            tail->prev = tail;
            tail->next = NULL;
            delete temp;
        }
    }

    T return_last()
    {
        return tail->data;
    }

    T return_first()
    {
        return head->data;
    }

    int numElem()
    {
      
        return counter;
    }

    bool isEmpty()
    {
        
        if (head == NULL || tail == NULL)
        {
           
            return true;
        }
        else
            return false;
    }

   
};