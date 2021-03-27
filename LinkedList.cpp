//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Thanh Vu on 1/14/21.
//

#include "LinkedList.hpp"
#include <iostream>

//         ----------------------          DEFAULT CONSTRUCTOR      --------------------//
template<class T>
LinkedList<T>::LinkedList()
{
    headPtr = nullptr;
    tail = nullptr;
    count = 0;
}

//   -----------------------------          COPY CONSTRUCTOR        -------------------------------//
template<class T>
LinkedList<T>::LinkedList(T A[], int n)
{
    Node<T>* temp = nullptr;
 
    
    headPtr = new Node<T>;      //Create Head Pointer
    headPtr->setItem(A[0]);        //Set Headpointer to the first Node contain A[0]
    headPtr->setNext(nullptr);     //The first node point to zero/
    tail = headPtr;                //Tail become first node, the linkedlist has one node
                                    //Initialize with one node
    for(int i = 1; i < n; i++)      //Tranverse through A, to put the rest of A in list
    {
        if(headPtr == nullptr)
        {
            headPtr = new Node<T>;      //If linkedList is empty, set that headptr to the first node and create it.
            headPtr->setItem(A[i]);
        }
        
        else
        {
        temp = new Node<T>;         //Create temp node
        
        temp->setItem(A[i]);        //Set items in A for temp.
        temp->setNext(nullptr);     //every nodes point to nullptr, and insert a new
                                    //elements until i < n.At this point, temp is neither
                                    //connected to tail nor head
        
        tail->setNext(temp);        //Now last will point to temp, now head->last->temp
        tail = temp;                //Copy temp becomes official nodes,
                                    //now head->node1->node2-> .... -> node n-1 -> tail
        }
    }
}   //END COPY CONSTRUCTOR



//      -------------------     LENGTH      ----------------------  //
template <class T>
int LinkedList<T>::length()
{
    int count = 0;
    Node<T> *p = headPtr;
    while(p)
    {
        count++;
        p = p->getNext();
    }
    return count;
}




//        -----------------     SUM OF NODES    ----------------------      ///
template <class T>
T LinkedList<T>::sum()
{
    Node<T> *p = headPtr;
    T sum = 0;
    while(p)
    {
        sum += p->getItem();
        p = p->getNext();
    }
    return sum;
}


//        -------------     MAX VALUE OF LINKED LIST    -----------------   ///
template <class T>
T LinkedList<T>::max()
{
    T m = INT_MIN;
    Node<T> *p = headPtr;
    while(p)
    {
        if(p->getItem() > m)
        {
            m = p->getItem();                       //Get item
        }
        p = p->getNext();                               //Iterative,point to next node.
    }
    
    return m;
}






//------------------------------------------------------------------------//
// --------------------------    INSERT NODES  -------------------------- //

template<class T>
void LinkedList<T>::insert(int pos, T x)
{
    Node<T> *temp, *p;                  //CREATE TEMP AND POINTER

    if(pos == 0)
    {                                   //IF INSERT NODE AFTER FIRST NODE.
        temp = new Node<T>;
        temp->setItem(x);               //DECLARE DATA FOR THE NODE
        temp->setNext(headPtr);         //TEMP NODE POINT TO THE NODE THE FIRST NODE POINT TO
        headPtr = temp;                 //ASSIGN FIRST NODE TO TEMP.
    }
                    
    else if(pos > 0)                    //INSERT AT GIVEN POSITION
    {
        temp = new Node<T>;
        temp->setItem(x);
        p = headPtr;                    //*HEAD = *P
        for(int i = 0; i < pos - 1 && p; i++)       //AT POSITION - 1, p->getNext() will get to the POSITION
            p = p->getNext();                       //&p is to make sure p != nullptr
        
        if(p != nullptr)
        {
                                 //Create temp node
          //  temp->setItem(x);                       //Declare value for temp node
            temp->setNext(p->getNext());            //temp node point to the node that *p point to
            p->setNext(temp);                       //p node point to the temp node.
        }
        
    }
}

//------------------------------------------------------------------------//
//  ---------------------------- APPEND NODES ------------------ //
template <class T>
void LinkedList<T>:: append(int x)
{
    Node<T> *temp = new Node<T>;
   
    
    temp->setItem(x);               //Declare value for temp
    temp->setNext(nullptr);         //Next temp point to nullptr, since because it will be the last nodes
    
    if(headPtr == nullptr)          //IF there is empty node
    {
        headPtr = tail = temp;      //Set that created node as the first node
    }
    
    else
    {
        tail->setNext(temp);        //last node point to that temp node
        tail = temp;                //that temp node becomes the last node
    }
    
}

//------------------------------------------------------------------------//
// -------------------- INSERTE SORT NODES ----------------------- //

template<class T>
void LinkedList<T>:: insertSored(T x)
{
    Node<T> *temp, *p;              //Create temp
    Node<T> *q = nullptr;           //pointer q is following(chasing) p
    
    p = headPtr;                    //Set head to p
    
    while(p && p->getItem() < x)      //p != null && p->data < target
    {
        q = p;                        // when q and p is in the same node
        p = p->getNext();             //this make p becomes the node after q, so now q follow p,  q --> p
    }
    
    temp = new Node<T>;               //Create temp
    temp->setItem(x);                 //Declare data for temp
    temp->setNext(q->getNext());      //since q ---> p, q->next is point to p. Temp will also point to p.
    q->setNext(temp);                 //Set pointer of q point to temp. So now, q --> temp(new Node) --> p
    
}


//------------------------------------------------------------------------//
// -------------------- DELETE NODES BY INDEX----------------------- //

template <class T>
T LinkedList<T>::remove(int pos)
{
    Node<T> *p , *q;        //create p & q
    

    T x = -1;         //Initialize x, x will contain the value of the node that will be deleted
    
    if(pos == 1)
    {
        p = headPtr;
        headPtr = headPtr->getNext();    //Point headptr to a node after the first node.
        x = p->getItem();               //Store value of deleted node to x
        delete p;                       //p is now delete, headptr now point to second node
    }
    
    else if(pos < 1 || pos > length())     return x;
    
    else
    {
        p = headPtr; q = nullptr;
        for(int i = 0; i < pos - 1 ; i++)
        {
            q = p;                  // when q and p is in the same node
            p = p->getNext();       //this make p becomes the node after q, so now q follow p,  q --> p
        }
        if(p)
        {
            q->setNext(p->getNext());      //q point to the node that p point to,  q ---> p ---> someNode
            x = p->getItem();               //store value of p node to x
            delete p;
        }                               //delete p, now   q ----> someNode
    }
    
    return x;
    
}

//------------------------------------------------------------------------//
// -------------------- DELETE NODES BY VALUE----------------------- //

template<class T>
T LinkedList<T>::removeByValue(T target)
{
    Node<T> *p,*q;
    p = headPtr;
    q = nullptr;
    if(headPtr == nullptr) return NULL;
    
    while(headPtr->getItem() == target)    headPtr = headPtr->getNext();
    
    while(p && p->getItem() != target)
    {
        
        q = p;
        p = p->getNext();
    }
    
    while(p)
    {
        if(p->getItem() == target)
        {
            q->setNext(p->getNext());
        }
            p = p->getNext();
    }
   

    return target;
    
    
}







//    ------------- SEARCH OPS ------------ //

template<class T>
int LinkedList<T>::search(T key)
{
    Node<T> *p = headPtr;
    //Node<T> *q = nullptr;   //For improve search, create *q, following *p
    int i = 1;
    while(p)
    {
        if(key == p->getItem())
        {
            //q->setNext(p->getNext());   //All of this comment is for improve search
            //p->setNext(headPtr);      //If target found, have the headptr point to
            //headPtr = p;              //the node contain target.
            return i;
        }
        i++;
        //q = p;
        p = p->getNext();
    }
    return -1;
}


//       -------------DISPLAY--------------- //
template <class T>
void LinkedList<T>::display()
{
    Node<T> *p = headPtr;
    
    //Iterative way
    while(p)
    {
        std::cout << p->getItem() << "  ";
        p = p->getNext();
    }
    std::cout << "\n";
}




//       ------------ DESTRUCTOR ------------- //
template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* p = headPtr;
    while(headPtr != nullptr)
    {
        headPtr = headPtr->getNext();
        delete p;
        p = headPtr;
    }
}
