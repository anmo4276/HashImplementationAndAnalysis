// CPP program to impliment cuckoo hashing
#include <iostream>
#include <cmath>
#include "cuckoo.hpp"
using namespace std;

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

unsigned int HashTable::hashFunc2(int key)
{
    return (floor(key/tableSize) % tableSize)
}

node* HashTable::searchItem(int key)
{
    int index = hashFunction(key);
    node* temp = table[index];
    if (temp->key == key){
        return temp;
    }
    else{
        index = hashFunc2(key);
        temp = table[index];
        if (temp->key == key){
            return temp;
        }
    }
    return nullptr;
}

bool HashTable::insertItem(int key)
{
    int index = hashFunction(key);
    node* nn = new node;
    nn->key = key;
    if (table[index] == nullptr){
        table[index] = nn;
        return true;
    }
    else{
        index = hashFunc2(key);
        if (table[index] == nullptr){
            table[index] = nn;
            return true;
        }
        else{
            int key2 = table[index]->key;
            table[index] = nn;
            
            }
        }
    }
}

bool HashTable::deleteItem(int key)
{
    int index = hashFunction(key);
    node* temp = table[index];
    if (temp->key == key){
        temp->key = -1;
        return true;
    }
    else{
        index = hashFunc2(key);
        temp = table[index];
        if (temp->key == key){
            temp->key = -1;
            return true;
        }
    }
    return false;
}

void HashTable::printTable()
{
    cout << "Table 1" << endl;
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        if (table[i] != nullptr){
            cout << table[i]->key << " ";
        }
        cout << endl;
    }
    
    cout << "Table 2" << endl;
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        if (table2[i] != nullptr){
            cout << table2[i]->key << " ";
        }
        cout << endl;
    }
 }
