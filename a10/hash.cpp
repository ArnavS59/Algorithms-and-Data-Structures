#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class HashTable
{
private:
    Node **arr;
    int maxSize;
    int currentSize;

public:
    HashTable()
    {
        currentSize = 0;
        maxSize = 10;
        arr = new Node *[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            arr[i] = NULL;
        }
    }

    int hashCode(int key)
    {
        return key % maxSize; //hash linear probing function for keys less than modulo it returns the value itself
    }
    void insertNode(int key, int value)
    {
        if (currentSize > maxSize)
            cout << "Hash table overflow" << endl;
        else
        {
            int index = hashCode(key); //slot the position in the hash table
            while (arr[index] != NULL && arr[index]->key != key)
            {
                index = hashCode(index + 1);
            }
            arr[index] = new Node(key, value);
            currentSize++;
        }
    }

    bool isEmpty()
    {
        if (currentSize == 0)
            return true;
    }
    void print()
    {
        for (int i = 0; i < maxSize; i++)
        {
            if (arr[i] != NULL)
                cout << "The key is " << arr[i]->key << " The value is " << arr[i]->value << endl;
        }
    }
    int get(int key)
    {
        int index = hashCode(key);
        while (arr[index] != NULL && arr[index]->key != key)
        {
            index = hashCode(index + 1);
        }
        if (arr[index] == NULL)
            return -1; //empty
        else
            return arr[index]->value;
    }
};

int main()
{
    HashTable hash1;
    hash1.insertNode(1, 2);
    hash1.insertNode(2, 4);
    hash1.insertNode(3, 10);
    hash1.insertNode(12, 7);
    hash1.insertNode(11, 8);
    hash1.insertNode(17, 8);
    cout<<"Printing the hash table"<<endl;
    hash1.print();
    cout<<"The value of the node with key 3 is "<<hash1.get(3)<<endl;
    return 0;
}