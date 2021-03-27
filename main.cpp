//
//  main.cpp
//  LinkedList
//
//  Created by Thanh Vu on 1/14/21.
//

#include "Node.h"
#include "LinkedList.cpp"
#include "LinkedList.hpp"

#include <iostream>



int main() {
    // insert code here...
    int A[] = {3,5,7,10,25,30,30,75,80,};
    int n = sizeof(A)/sizeof(A[0]);
    
    
    //     -----------------    CREATE LINKED LIST      --------------------    ///
    LinkedList<int> l(A,n);
    

    //     ------------- DISPLAY ------------------//
    
    //DISPLAY
    std::cout << "Linked List: \n";
    l.display();
    
    std::cout << "\t\t ------------------------------------------------------- \n\n";
    
    
    //      ----------------    MODIFY ELEMENTS FUNCTION, SUCH AS INSERT, APPEND, DELETE , .... ---------------------//
    
    //INSERT ELEMENTS
    int x = 4;
    int position = 1;
    l.insert(position,x);
    std::cout << "\nInsert " << x << " at position " << position << "\n";
    
    //DISPLAY
    std::cout << "Linked List: \n";
    l.display();
    std::cout << "\n\n";
    
    //APPEND ELEMENTS
    int newVal = 99;
    std::cout << "Append " << newVal << " to the list \n";
    l.append(newVal);
    
    //DISPLAY
    std::cout << "Linked List: \n";
    l.display();
    std::cout << "\n\n";
    
    
    //INSERT SORTED
    int x2 = 42;
    l.insertSored(x2);
    std::cout << "Insert " << x2 << " in a sorted order ... \n";
    
    //DISPLAY
    std::cout << "Linked List: \n";
    l.display();
    std::cout << "\n\n";
    
    
    //DELETE ELEMENT BY INDEX
    int pos = 5;
    int delVal = l.remove(pos);
    std::cout << "Delete " << delVal << " at position " << (pos-1) << "\n";
    
    
    //DISPLAY
    std::cout << "Linked List: \n";
    l.display();
    std::cout << "\n\n";
    
    
    //DELETE ELEMENT BY VALUE
    int target = 30;
    int delVal2 = l.removeByValue(target);
    std::cout << "Delet value " << delVal2 <<  "\n";
    
    //DISPLAY
    std::cout << "Linked List: \n";
    l.display();
    std::cout << "\n\n";
    
    
    std::cout << "\t\t ------------------------------------------------------- \n\n";
    
    
    //     -------------------------- SEARCH ELEMENT ------------------------------------ //
    int key = 80;
    int delPos = l.search(key);
    std::cout << "Key " << key << " found at: " << delPos << "th \n\n";
    
    
    std::cout << "\t\t ------------------------------------------------------- \n\n";
    
 
    //------------------- MEMBER FUNCTION THAT RETURN THE  VALUE, SUCH AS MAX, TOTAL, LENGTH    ------------------------//
    
    //LENGTH
    int count = 0;
    count = l.length();         //Print Length of list
    std::cout << "Length of list: " << count << "\n\n";
    
    
    //TOTAL ELEMENTS
    int total = l.sum();
    std::cout << "Total value: " << total << "\n\n";
    
    
    //MAX VALUE
    int max = l.max();
    std::cout << "Max value: " << max << "\n\n";
    
    
    std::cout << "\t\t ------------------------------------------------------- \n\n";
    
    
    //DISPLAY
    std::cout << "Linked List: \n";
    l.display();
    
    return 0;
}
