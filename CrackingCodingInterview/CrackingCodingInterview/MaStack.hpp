//
//  MaStack.hpp
//  CrackingCodingInterview
//
//  Ch3 Stacks And Queues
//  Data structure built to supply solution program adequate data structures
//
//  Created by Kelly Kim on 4/27/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

#ifndef MaStack_hpp
#define MaStack_hpp
#include <iostream>
#include <stdio.h>
class MaStack{
private:
    int * stackArray;
    int top;
    int size;
    
public:
    
    MaStack(int);
    ~MaStack();
    void push(int);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void print();
    void fillTen();
    void sort();
    
};
#endif /* MaStack_hpp */
