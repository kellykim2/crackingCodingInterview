//
//  LinkedLists.cpp
//  CrackingCodingInterview
//
//  Created by Kelly Kim on 4/19/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

#include "LinkedLists.hpp"
using namespace std;

LinkedLists::LinkedLists(){
    head = nullptr;
    size = 0;
}

LinkedLists::~LinkedLists(){
    delete head;
}

//initial filler
void LinkedLists::TempFillTen(){
    head = new Node(rand()%100);
    size++;
    Node * curr = head;
    srand(time(NULL));
    //assuming this method only fills from head
//    while(curr->next != nullptr){
//        curr = curr->next;
//    }
    
    do{
        curr->next = new Node(rand()%100);
        size++;
        curr = curr->next;
    }while(size < 10);
}

void LinkedLists::Print(){
    puts("List contains:");
    Node * curr = head;
    while (curr != nullptr){
        cout << curr->value << " - ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

/*
 Remove Dups: Write code to remove duplicates from an unsorted linked list.
 approach : From head to tail iterate through the list to remove index [i] element's duplicate.
 if there are no duplicate, this will run at n-square time.
 FOLLOW UP
 How would you solve this problem if a temporary buffer is not allowed?
 for follow up I would sort the list (bubble sort since the problem restriction is no temp buffer).
 and then compare adjacent nodes to remove dups.
 */
void LinkedLists::RemoveDups(){
    //handle empty list
    if(size > 0){ //at least head exist
        Node * curr = head;
        Node * hold = curr; //initially at the head together.
        int data = hold->value; // hold my beer
        int index = 0;
        while(index < size && hold->next != nullptr){
            curr = hold;
            while(curr && curr->next != nullptr){ //found dup
                if(data == curr->next->value){
                    remove(curr);
                }
                curr = curr->next;
            }
            if(hold->next != nullptr){ //shift checking index up
                hold = hold->next;
                data = hold->value;
                index++;
            }
        }
    }//end if
}

//pre: given parent node
//post: delete child 
void LinkedLists::remove(Node * parent){
    if(parent->next != nullptr){
        Node * temp = parent->next;
        if(temp->next != nullptr){      //has grandchild
            parent->next = temp->next;  //build bridge
            delete temp;
            size--;
        }else{                          //no grandchild
            parent->next = nullptr;
        }
    }
}
//ch2-1
//Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

Node * LinkedLists::KthToLast(int k){
    return KthToLast(k, head);
}

Node * LinkedLists::KthToLast(int k, Node * curr){
    if(k > 0 && curr != nullptr){
        //since singly linked list has known size, size-k should give us the correct number of times
        //of iteration to kth element from last
        int count = size - k;
        
        while(count > 0 && curr != nullptr){
            curr = curr->next;
            count--;
        }
    }
    return curr;
}

/*2.3
 Delete Middle Node: Implement an algorithm to delete a node in the middle (any node but
 the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
 that node.
 
 Hint given->Picture the list 1->5->9->12, Removing 9 would make it look like 1- >5- >12.You only
 have access to the 9 node. Can you make it iook like the correct answer?
 
 Approach #1 : Since we are given only access to the targeted node
 Step1 : Copy contents of next link to itself.
 step2: Copy next link's next to itself.
 step3: delete the tailing node.
 */

void LinkedLists::DeleteMiddle(Node * target){
    //step1
    target->value = target->next->value;
    //step2 & step3 are done by remove function that receives parent node of object due deletion.
    remove(target);
}

/*
 *
 Sum Lists: You have two numbers represented by a linked list,
 where each node contains a single digit.
 The digits are stored in reverse order,
 such that the Vs digit is at the head of the list.
 Write a function that adds the two numbers and returns the sum as a linked list.
 
 For this problem, I have quickly implemented pop and push for the list,
 and SumList will have summing of a list of digits in reverse order.
 
 Thus from driver program,
 User will have access to SumList which will sum the list that contains
 reverse order digits
 User also has access to IntToList which will convert an integer value
 to reverser order digit representation in a List.
 
 */
int LinkedLists::SumList(void){
    int sum = 0;
    for(int i = 0; i < size; i++){
        cout << "Debug pow (10, " << i << ") = " << pow(10, i) <<endl;
        
        sum += pow(10, i) * pop(); //per digit
    }
    return sum;
}

//to an empty list with given integer, fills list with single digit reversely
//i.e. given 123, (one hundred and twenty three)
// mod 10, assigns 3 to digit, pushes 3 / and i is 12
// mod 10 assigns 2 to digit pushes 2 / and i is
void LinkedLists::IntToList(int i){
    while (i > 0){
        int digit = i % 10;
        push(digit);
        i /= 10;
    }
}

//stack style insert and remove
void LinkedLists::push(int val){
    if(head == nullptr){
        head = new Node(val);
        
    }else{
        Node * curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = new Node(val);
        
    }
    size++;
}

int LinkedLists::pop(){
    Node * temp = head;
    head = head->next;
    int value = temp->value;
    delete temp;
    return value;
}

