//
//  LinkedChar.h
//  LinkedList
//
//  Created by Thanh Vu on 1/14/21.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "Node.h"

template<class T>
class LinkedList
{
private:
    Node<T> *headPtr;
    Node<T> *tail;
    int count;
  
public:
    //CONSTRUCTOR && DESTRUCTOR
    LinkedList();
    LinkedList(T A[], int n);
    virtual ~LinkedList();
   
   
    
    //DISPLAY
    void display();
    
    
    
    //FUNCTION RETURN VALUE.
    int length();
    T sum();
    T max();
    
    
    //FUNCTION MODIFY LIST
    void insert(int pos, T x);
    void append(int x);
    void insertSored(T x);
    T remove(int pos);
    T removeByValue(T target);
    
    
    //SEARCH OPS
    int search(T key);      
    
    
};


#endif /* LinkedChar_h */
