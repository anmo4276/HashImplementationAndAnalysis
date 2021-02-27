// CPP program to implement hashing with chaining
#include<iostream>
#include <cmath>
#include "BSTHash.hpp"


using namespace std;

void printInorder(node* node)
{
    if (node == NULL)
        return;
    printInorder(node->leftChild);
    cout << node->key<< " ";
    printInorder(node->rightChild);
}

node* HashTable::createNode(int key, node* parent)
{
    node* nw = new node;
    nw->key = key;
    nw -> parent = parent;
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
  node* search = table[index];
  node* traverse = search;
  if(table[index]!= NULL){
      while(traverse!= NULL){
        if(key == traverse-> key){
          return traverse;
        }
        else if(key<traverse->key){
          traverse = traverse ->leftChild;
        }
        else{
          traverse = traverse ->rightChild;
        }
      }
  }
  return nullptr;
}

node* deleteNode(node* head, int key)
{
    node* temp = head;
    if (head == NULL){
      return head;
    }
    if (key > head->key){
        head->rightChild = deleteNode(head->rightChild, key);
      }
    else if (key < head->key){
        head->leftChild = deleteNode(head->leftChild, key);
      }
    else if(key == head->key)
    {
        if (head->rightChild == NULL)
        {
            temp = head->leftChild;
            return temp;
        }
        else if (head->leftChild == NULL)
        {
            temp = head->rightChild;
            return temp;
        }
        node* traverse = head->rightChild;
        while (traverse->leftChild && traverse != NULL){
            traverse= traverse->leftChild;
          }
        temp= traverse;
        head->key = temp->key;
        head->rightChild = deleteNode(head->rightChild, temp->key);
    }
    return head;
}

bool HashTable::deleteItem(int key)
{
  int index = hashFunction(key);
  node* deletedItem = searchItem(key);
  if(deletedItem!= nullptr){ //IF FOUND
        if(key == table[index]->key){

          if(table[index]->rightChild==NULL&&table[index]->leftChild==NULL){
                table[index]= NULL;
          }
          else if(table[index]->rightChild!=NULL&&table[index]->leftChild!=NULL){
              deleteNode(table[index],key);
          }
          else if(table[index]->rightChild==NULL&&table[index]->leftChild!=NULL){
              table[index]= table[index]->leftChild;
          }
          else if(table[index]->rightChild!=NULL&&table[index]->leftChild==NULL){
              table[index]= table[index]->rightChild;
          }

        }
        else{
          deleteNode(table[index],key);
        }
        // cout<< "NEW BUCKET:" <<endl;
        // cout<< "-----------------------" <<endl;
        // printInorder(table[index]);
        // cout<< endl;
        return true;
  }
  else{
    //cout<< "Item not found" <<endl;
  }
  return false;
}

bool HashTable::insertItem(int key)
{
  if(!searchItem(key))
  {
      int index = hashFunction(key);
      if (table[index] != nullptr){
          node *parentOne = table[index];
          node* traverse = parentOne;
          int leftRight =-1;
          while(traverse != NULL){
            parentOne = traverse;
            if(key > traverse ->key){
              traverse = traverse -> rightChild;
              leftRight=0;
            }
            else{
              traverse = traverse -> leftChild;
              leftRight=1;
            }
          }
          if(leftRight==0){
            parentOne -> rightChild = createNode(key,parentOne);
          }
          else{
            parentOne -> leftChild = createNode(key,parentOne);
          }
      }
      else{
          table[index] = createNode(key, nullptr);
      }
      return true;

   }
  else{
      //cout<<"duplicate entry: "<< key << endl;
      return false;
  }

}



void HashTable::printTable()
{
    for(int i =0; i< tableSize; i++){
      cout << i <<"||";
      if (table[i] != nullptr){

          printInorder(table[i]);

      }
      cout << endl;
    }
 }
