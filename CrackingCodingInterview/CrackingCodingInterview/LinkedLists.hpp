//
//  LinkedLists.hpp
//  CrackingCodingInterview
//
//  Created by Kelly Kim on 4/19/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

#ifndef LinkedLists_hpp
#define LinkedLists_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

struct Node{    //singly linked list structure
    int value;
    Node * next;
    Node(int val){ //constructor with value;
        value = val;
        next = nullptr;
    }
    Node(): value(-1), next(nullptr) {}//defulat constructor
};
class LinkedLists{
private:
    Node * head;
    int size;
    void remove(Node*); //parameter pointer to parent of subject due removal.
    void setSize(int);
public:
    LinkedLists();
    ~LinkedLists();
    void Print();
    void TempFillTen();
    int getSize();
    void RemoveDups();//2-1
    
    
};
#endif /* LinkedLists_hpp */
