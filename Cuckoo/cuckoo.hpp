//
//  cuckoo.hpp
//  
//
//  Created by Manuel Navarrete on 12/7/19.
//

#ifndef cuckoo_hpp
#define cuckoo_hpp

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
    
    // Pointer to an array containing buckets;
    node* *table2;
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);
    
    //deletes key from hash table
    bool deleteItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);
    
    // second hash function to deal with collisions
    unsigned int hashFunc2(int key);

    void printTable();

    node* searchItem(int key);
};


#endif
