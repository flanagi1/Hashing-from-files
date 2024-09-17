#include <iostream>
#include "SLL.h"
#include <string>
using  namespace  std;

template <class V>
class HashTable {
    int tableSize; // table size
    
    SLL<V>* table;
    
    public:
    // default constructor, which uses default table size 3
    HashTable(){
        tableSize = 3;
        table = new SLL<V>[tableSize];
    }
    
    // constructor, which use size as the table size
    HashTable(int size)
    {
      tableSize = size;
      table = new SLL<V>[tableSize];
    }
    
    // search item in the table
    // if found, return true; otherwise, return false
    bool find(V item)
    {
      int index = hash(item);
      return table[index].search(item) != nullptr;
    }
    
    // insert (item1, item2) to the table
    // use item1 as the key
    // if inserted, return true
    // otherwise, return false
    bool insert(V item1, V item2)
    {
      SLL<V>* temp;
      int index = hash(item1);
      temp = &table[index];
      if(temp->search(item1) == nullptr)
      {
        temp->insert(item1, item2);
        return true;
      }
      return false;
    }
    
    // delete the pair whose key value is item
    // if deleted, return true
    // otherwise, return false 
    bool erase(V item)
    {
      int index = hash(item);
      return table[index].remove(item);
    }

    // return the total number of nodes in the hash table    
    int getSize()
    {
      int size = 0;
      for(int i = 0; i < tableSize; i++)
      {
        size += table[i].getSize();
      }
      return size;
    }

    private:

    int hash(V item)
    {
      int temp = stoi(item);
      return temp % tableSize;
    }
};
