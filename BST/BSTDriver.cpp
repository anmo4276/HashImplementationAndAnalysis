#include <iostream>
#include <fstream>
#include <sstream>
#include "BSTHash.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    HashTable ht(10009);
    ifstream myfile;
    myfile.open(argv[1]);
    if (myfile.is_open())
    {

        string line = "";
        while (getline(myfile, line))
        {
            if (line != ""){
                istringstream ss(line);
                string input;
                while (getline(ss, input, ',')){
                    ht.insertItem(stoi(input));
                }
            }
        }
    }

    cout<< "Contents of the hash table are"<<endl;

    ht.printTable();

    cout<<endl;

    int searchFor = 46081432;

    if(ht.searchItem(searchFor)== nullptr)
     {
       cout<<searchFor<<" not found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" found in the hash table at index " << ht.hashFunction(searchFor)<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<< "DELETE: " << searchFor << endl;
    ht.deleteItem(searchFor);
    if(ht.searchItem(searchFor)== nullptr)
     {
       cout<<searchFor<<" not found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" found in the hash table at index " << ht.hashFunction(searchFor)<<endl;
    }
    return 0;
}
