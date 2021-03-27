//
//  Node.h
//  LinkedList
//
//  Created by Thanh Vu on 1/14/21.
//

#ifndef Node_h
#define Node_h

// --------------- class Prototype ----------------- //
template<class T>
class Node
{
private:
    T item;
    Node<T>* next;
public:
    Node();
    Node(const T& item);
    Node(const T& item, Node<T> * next);
    void setItem(const T& item);
    void setNext(Node<T>* nextNodePtr);
    
    T getItem() const;
    Node<T>* getNext() const;
};

//         ------------ Member ------------- //

//Default Constructor
template<class T>
Node<T>:: Node() : next(nullptr) {}
//End default constructor


//COPY CONSTRUCTOR1
template<class T>
Node<T>:: Node(const T& item)
{
    this->item = item;
    setNext(nullptr);
}
//END COPY CONSTRUCTOR1


//Copy Constructor2
template<class T>
Node<T>:: Node(const T& item, Node<T> *nextNodePtr)
{
    this->item = item;
    setNext(nextNodePtr);
}
//END COPY CONSTRUCTOR2


        //MUTATOR
template<class T>
void Node<T>::setItem(const T& item)
{
    this->item = item;
}       //END SET ITEM

template<class T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
    next = nextNodePtr;
}       //END SET NEXT

    
//ACCESOR
template<class T>
T Node<T>::getItem() const
{
    return item;
}       //END GET ITEM

template<class T>
Node<T>* Node<T>::getNext() const
{
    return next;
}       //END GET NEXT






#endif /* Node_h */
