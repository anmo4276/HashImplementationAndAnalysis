// CPP program to impliment hashing with linear probing
#include <iostream>
#include <cmath>
#include "hashLP.hpp"
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
    return ((key/tableSize) % tableSize);
}

// unsigned int HashTable::hashFunction(int key)
// {
//     return (key % tableSize);
// }

node* HashTable::searchItem(int key)
{
    int index = hashFunction(key), steps = 0;
    node* temp = table[index];
    while (temp != nullptr){
        if (temp->key == key){
            return temp;
        }
        else {
            index++;
            if (index == 10009){
                index = 0;
            }
            temp = table[index];
            steps++;
        }
        if (steps == 10009){
            break;
        }
    }
    return nullptr;
}

bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        int index = hashFunction(key);
        if (table[index] == nullptr){
            node* nn = new node;
            nn->key = key;
            table[index] = nn;
        }
        else{
            node *temp = table[index], *nn = new node;
            int steps = 0;
            nn->key = key;
            while (temp != nullptr){
                index++;
                if (index == 10008){
                    index = 0;
                }
                temp = table[index];
                steps++;

                if (steps == 10009){
                    return false;
                }
            }
            table[index] = nn;
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
                index++;
                steps++;
                if (index == 10009){
                    index = 0;
                }
                if (steps == 10009){
                    return false;
                }
                temp = table[index];
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
        }
        cout << endl;
    }
 }
