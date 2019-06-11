//
//  MaStack.cpp
//  CrackingCodingInterview
//
//  Ch3 Stacks And Queues
//  Data structure built to supply solution program adequate data structures
//
//  Created by Kelly Kim on 4/27/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

#include "MaStack.hpp"

/*basic operations*/
MaStack::MaStack(int size){
    this->size = size;
    top = 0;
    stackArray = new int[this->size];
}
MaStack::~MaStack(){
    delete[] stackArray;
    
}

void MaStack::push(int value){
    if(top > size){
        puts("ERR: Stack Over Flow");
    }else{
        stackArray[top++] = value;
        
    }
}
int MaStack::peek(){
    return stackArray[top];
}

int MaStack::pop(){
    int result = __INT_MAX__; //error value
    if(isEmpty()){
        puts("ERR: Stack Under Flow");
    }else{
        result = stackArray[top--];
        
    }
    return result;
}

bool MaStack::isEmpty(){
    return (top == 0);
}

bool MaStack::isFull(){
    return (top == size);
}

void MaStack::print(){
    std::cout << "Current Stack = {\n";
    for(int i = 0; i < top; i++){
        std::cout << "index " << i << " : " << stackArray[i] << std::endl;
    }
    std::cout << "}\n";
}

void MaStack::fillTen(){
    srand(time(NULL));
    for(int i = 0 ; i < 10; i++){
        int temp =  rand()%100;
        std::cout << "fill ten " << i << " : " << temp << std::endl;
        push(temp);
        
    }
}

/* 3.1
 Q: Describe how you could use a single array to implement three stacks.
 
 A: In a array length N,
 I can allocate each stack N/3 N/3 N/3
 Stack 1 will run indices 0~ N/3 -1
 Stack 2 will run through N/3 ~ 2N/3 -1
 Stack 3 will run through 2N/3 ~ N - 1
 each stack will have to have constant range value to keep an index from reaching over,
 when pushes/pops rotate around the indices
 
 
 
 */

/* 3.2
 Q: Stack Min - How would you design a stack which, in addtion to push and pop, has a function
 min which returns the minimum element. Push, pop and min should all operate in O(1) time.
 A: since stack is based on LIFO, A pointer to top which will push element in at O(1),
 pop element in O(1). While push and pop are kept normal operation keeping a pointer to min value
 for each operation for push and pop by updating min pointer
 while push can remain at O(1) by adding one comparsion to update the min to incoming value
 pop will require re locating the min value of from the whole remaining stack if it was the min
 that got popped from the stack. Thus the book's solution was to keep an additional stack of min
 which I did not quite understand, and other suggestion was to keep a pointer to min of each node.
 Which can also fail to provide O(1) because of the complication when updating pop for min
 
 */

/* 3.4
 Stack sorting with a temporary stack
 no other data structure allowed
 
 While input stack is NOT empty do this:
 Pop an element from input stack call it temp
 while temporary stack is NOT empty and top of temporary stack is greater than temp,
 pop from temporary stack and push it to the input stack
 push temp in temporary stack
 
 
 */

void MaStack::sort(){
    MaStack *temp = new MaStack(this->size);
    
    
    // While input stack is NOT empty do this:
    while(!this->isEmpty()){
        //puts("Original ");
        this->print();
        puts("\ntemp\n");
        //
        int val = this->pop();

        while(!temp->isEmpty() && temp->peek() > val){
            this->push(temp->pop());
        }
        temp->push(val);
    }
}

