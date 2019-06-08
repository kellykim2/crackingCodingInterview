//
//  SetOfStack.cpp
//  CrackingCodingInterview
//
//  Created by Kelly Kim on 6/7/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

#include "SetOfStack.hpp"
SetOfStack::SetOfStack(){
    set.push_back( new MaStack(10)); //initializing with first stack
    
}

SetOfStack::~SetOfStack(){
    while(!set.empty())
        delete set.back();
}

void SetOfStack::push(int value){
    //debug
    std::cout << "\nDEBUG: Pushing into set of stack - value = " << value <<std::endl;
    MaStack * curr = set.back();
    curr->print();
    if(curr->isFull()){
        set.push_back( new MaStack(10));
        curr = set.back();
    }
        curr->push(value);
}

int SetOfStack::pop(){
    if(set.empty()){
        return -1;
    }else{
        MaStack * curr = set.back();
        while (curr->isEmpty()){
            set.pop_back();
            curr = set.back();
        }
        
        return curr->pop();
    }
}
