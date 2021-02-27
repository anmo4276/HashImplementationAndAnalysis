// CPP program to implement hashing with chaining
#include<iostream>
#include<cmath>
#include "chainHash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

unsigned int HashTable::hashFunction(int key)
{
    return ((key/tableSize) % tableSize);
}

// unsigned int HashTable::hashFunction(int key)
// {
//     return (key % tableSize);
// }

node* HashTable::searchItem(int key)
{
    int index = hashFunction(key);
    node* temp = table[index];
    while (temp != nullptr){
        if (temp->key == key){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        int index = hashFunction(key);
        if (table[index] == nullptr){
            table[index] = createNode(key, nullptr);
        }
        else{
            node *parent = table[index], *nn = createNode(key, nullptr);
            while (parent->next != nullptr){
                parent = parent->next;
            }
            parent->next = nn;
        }
        return true;
     }
    else{
        //cout<<"duplicate entry: "<< key << endl;
        return false;
    }

}

bool HashTable::deleteItem(int key)
{
    if (!searchItem(key)){
        //cout << "Key not found in hash table" << endl;
        return false;
    }
    else {
        int steps = 0, index = hashFunction(key);
        node *temp = table[index];
        while (temp != nullptr){
            if (temp->key == key){
                table[index] = nullptr;
                //cout << "Key: "<<  key <<" deleted" << endl;;
                return true;
            }
            else {
                temp = temp->next;
            }
        }
        return false;
    }
}

void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        if (table[i] != nullptr){
            cout << table[i]->key << " ";
            while (table[i]->next != nullptr){
                table[i] = table[i]->next;
                cout << table[i]->key << " ";
            }
        }
        cout << endl;
    }
 }
