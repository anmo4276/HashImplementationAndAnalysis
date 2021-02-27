// Project Linear Probing Hash Table Header File
#ifndef hashLP_hpp
#define hashLP_hpp

#include <string>
using namespace std;
struct node
{
    int key;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
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
