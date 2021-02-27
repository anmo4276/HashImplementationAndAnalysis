// Project Chain Hash Table Header File
#ifndef CHAINHASH_HPP
#define CHAINHASH_HPP

#include <string>


using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;

    node* createNode(int key, node* next);
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);
    
    //deletes key from hash table
    bool deleteItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();

    node* searchItem(int key);
};

#endif
