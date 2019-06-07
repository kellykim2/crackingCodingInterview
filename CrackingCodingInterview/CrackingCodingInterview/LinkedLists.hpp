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
#include <math.h>
#include <string>

struct Node{    //singly linked list structure
    int value;
    char letter;
    Node * next;
    Node(int val){  // Node constructor with integer value
        value = val;
        next = nullptr;
        letter = '\0';
    }
    Node(char c){ //Node constructor with char value
        value = 0;
        next = nullptr;
        letter = c;
    }
    Node(): value(-1), next(nullptr) {}//defulat Node constructor
};

class LinkedLists{
private:
    Node * head;
    int size;
    void remove(Node*); //parameter pointer to parent of subject due removal.
    void setSize(int);
    Node * KthToLast(int, Node*); //recursion inner method
    void push(int);     //push for integer node
    int pop();          //pop for integer node
    void push(char);    //push for char node
    char cPop();        //pop for char node
    Node * getTail();   //gets the tail node
public:
    LinkedLists();
    ~LinkedLists();
    void Print();       //prints linkedlist
    void TempFillTen(); //fills ten arbitrailiy filled node
    int getSize();      //returns size of node
    void RemoveDups();              //2-1
    Node * KthToLast(int);          //recursion outer method
    void DeleteMiddle(Node *);      //2-3
                                    //2-4
    int SumList(void);              //2-5
    void IntToList(int);            //2-5 helper creates
    bool IsPalindrome(void);        //2-6
    void InputString(std::string);
    Node * Intersect(LinkedLists *); //2-7
    
    
};
#endif /* LinkedLists_hpp */
