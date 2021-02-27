#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct node
{
    int key;
    node* parent = NULL;
    node* leftChild = NULL;
    node* rightChild = NULL;
};

class HashTable
{
    int tableSize;
    node* root;
    node* *table;
    node* createNode(int key, node* next);

public:
    HashTable(int bsize);

    bool insertItem(int key);

    unsigned int hashFunction(int key);
    bool deleteItem(int key);
    void printTable();

    node* searchItem(int key);
};

#endif
