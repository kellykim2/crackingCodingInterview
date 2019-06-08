//
//  SetOfStack.hpp
//  CrackingCodingInterview
//
//  Created by Kelly Kim on 6/7/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

/* 3.3
 Stack of Plates
 Implement a data structure SetOFStacks that mimics real life stacks of plates.
 SetOfStacks should be composed of several stacks and should create a new stack once the previous ones exceed
 its capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stac.
 
 Additionally implement a function popAt(int index) which performs a pop operation on a specific sub-stack
 */

#ifndef SetOfStack_hpp
#define SetOfStack_hpp

#include <stdio.h>
#include <list>
#include "MaStack.hpp"

class SetOfStack{
private:
    std::list<MaStack *> set;
    
public:
    SetOfStack();
    SetOfStack(int); //initial size of each stack
    ~SetOfStack();
    void push(int);
    int pop();
    
};
#endif /* SetOfStack_hpp */
