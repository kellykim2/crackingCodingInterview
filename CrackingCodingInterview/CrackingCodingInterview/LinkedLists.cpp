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
    head = new Node(1);
    size = 1;
}

LinkedLists::~LinkedLists(){
    delete head;
}

void LinkedLists::TempFillTen(){
    Node * curr = head;
    srand(time(NULL));
    while(curr->next != nullptr){
        curr = curr->next;
    }
    for(int i = 0; i < 10; i++){
        curr->next = new Node(rand()%10);
        size++;
        curr = curr->next;
    }
}

void LinkedLists::Print(){
    puts("List contains:");
    Node * curr = head;
    while (curr != nullptr){
        cout << curr->value << " " << endl;
        curr = curr->next;
    }
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
