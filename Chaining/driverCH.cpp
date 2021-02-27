#include <iostream>
#include <fstream>
#include <sstream>
#include "chainHash.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    // 10009 is count of buckets in hash table
    HashTable ht(10009);
    // Imputing Data Set File
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
                    cout << ht.insertItem(stoi(input)) << endl;
                }
            }
        }
    }

    cout<< "Contents of the hash table are"<<endl;
    ht.printTable();

    cout<<endl;

    int searchFor = 22181778;
    cout << ht.hashFunction(searchFor) << endl;
    cout << ht.searchItem(searchFor) << endl;
    cout << ht.deleteItem(searchFor)<< endl;
    if(ht.searchItem(searchFor) == nullptr)
     {
       cout<<searchFor<<" not found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" found in the hash table"<<endl;
    }
    cout<<"------------------------------------"<<endl;

    return 0;
}

