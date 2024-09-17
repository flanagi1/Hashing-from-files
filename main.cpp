#include <iostream>
#include <fstream>
#include "hashTable.h"
#include <string>
#include <time.h>
#include <ctime>

using namespace std;

int main(int argc, char* argv[])
{
    clock_t start, end;
    double duration;

    start = clock();
    
    ifstream input(argv[1]);
    
    HashTable<string> ht(10007);

    int rp, ret = 0, del = 0, ins = 0;
    int count = 0;

    string ssn, f, l, front, fl, line;
  

    while(getline(input, line))
    {
        input >> front >> ssn >> f >> l;
        fl = f + " " + l;
        if(front == "i")
        {
            if(ht.insert(ssn, fl))
                ins++;
        }
        else if(front == "d")
        {
            if(ht.erase(ssn))
                del++;
        }
        else if(front == "r")
        {
            if(ht.find(ssn))
                ret++;
        }
    }
    input.close(); 
    
    
    
    end = clock();
    
    duration = ( end - start ) / (double) CLOCKS_PER_SEC;
    cout << "The Number of Valid Insertation: " << ins << endl;
    cout << "The Number of Valid Deletion: " << del << endl;
    cout << "The Number of Valid Retrieval: " << ret << endl;
    cout << "Item numbers in the list: " << ht.getSize() << endl;
    cout << "Time Elapsed: " << duration <<'\n';

    return 0;

    
}
