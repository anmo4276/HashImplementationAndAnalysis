#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "BSTHash.cpp"
#include <time.h>
#include <windows.h>
using namespace std;
int main(){
    vector<int> v;
    int loadFactor= 10009*1; //Change Load Factor
    int count=0;
    HashTable ht(10009);
        ifstream myfile;
        myfile.open("dataSetA.csv");
        if (myfile.is_open())
        {

            string line = "";
            while (getline(myfile, line))
            {
                if (line != ""){
                    istringstream ss(line);
                    string input;
                    while (getline(ss, input, ',')){
                        if(count==loadFactor){
                          break;
                        }
                        v.push_back(stoi(input));
                        count++;
                    }
                }
            }
        }
        for(int d=0; d<v.size(); d++){
          ht.insertItem(v[d]);
        }

        LARGE_INTEGER frequency;
        LARGE_INTEGER startTime, endTime, totalTime;
        for(int i=0; i<100;i++){
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&startTime);
          for(int b=0; b<100;b++){
            ht.deleteItem(v[b]);
          }
        QueryPerformanceCounter(&endTime);
        for(int d=0; d<100; d++){
          ht.insertItem(v[d]);
        }
        totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e9) / frequency.QuadPart;
        cout << totalTime.QuadPart << endl;
      }
        //1e9 is nanoseconds, 1e6 microseconds, 1e3 is milliseconds
        //the multiplier is what changes the form of measurement, which are listed above.









    return 0;
}
