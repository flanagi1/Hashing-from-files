#include <iostream>
#include "Node.h"
using  namespace  std;

template <class U>
class SLL {
    
    Node<U> * headPtr;
    int size;
    
    public:
    // default constructor
    SLL()
    {
      headPtr = nullptr;
      size = 0;
    }

    // destructor    
    ~SLL()
    {
      Node<U>* curr = headPtr;
      while(curr != nullptr)
      {
        Node<U>* next = curr->next;
        delete curr;
        curr = next;
      }
    }
    
    Node<U>* getHeadPtr(){
        return headPtr;
    }
    
    // insert (item1, item2) to the list
    void insert(U item1, U item2)
    {
      Node<U>* newNode = new Node<U>;
      newNode->SSN = item1;
      newNode->name = item2;
      newNode->next = headPtr;
      headPtr = newNode;
      size++;
    }
    
    // if find the item1 value, return the pointer to the node
    // otherwise, return nullptr
    Node<U>* search(U item1)
    {
      Node<U>* curr = headPtr;
      while (curr != nullptr) 
      {
        if (curr->SSN == item1)
          return curr;
        curr = curr->next;
      }
        return nullptr;
    }
    
    // remove the node with key value: item1
    bool remove(U item1)
    {
      if(headPtr == nullptr)
        return false;
      if(headPtr->SSN == item1)
      {
        Node<U>* temp = headPtr;
        headPtr = headPtr->next;
        delete temp;
        size--;
        return true;
      }
      Node<U>* prev = headPtr;
      Node<U>* curr = headPtr->next;
      while((curr != nullptr) && (curr->SSN != item1))
      {
        prev = curr;
        curr = curr->next;
      }
      if(curr != nullptr)
      {
        prev->next = curr->next;
        delete curr;
        size--;
        return true;
      }
      return false;
    }
    
    int getSize(){
        
        return size;
    }
    
    // display the SSN values of each node in the linked list
    void display(){
        Node<U>* temp;
        temp = headPtr;
        while (temp!= nullptr) {
            cout << temp->SSN << endl;
            temp = temp->next;
        }
    }
};


