//
//  main.cpp
//  CrackingCodingInterview driver
//
//  Created by Kelly Kim on 4/15/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

#include <cstdio>
#include "ArraysAndStrings.hpp"

using namespace std;

void menu(void);
void chapterOne(void);

int main(int argc, const char * argv[]) {
    
    puts("Cracking Coding Interview\nSolutions by Kelly Kim\nSolutions are not final and work in progress");
    menu();
    chapterOne();
    
    return 0;
}

void menu(void){
    puts("menu");
    puts("ch1.1 - IsUnique");
}

void chapterOne(void){
    //construct test
    ArraysAndStrings testOne;
    string unique = "Unique";
    string notUnique = "nnn";
    string emptyString = "";
    
    if(testOne.IsUnique(unique))
        puts("Test 1 unique passed");
    else
        puts("Test 1 unique not passed");
    if(testOne.IsUnique(notUnique))
        puts("Test 1 not unique case not passed");
    else
        puts("Test 1 not unique case passed");
    if(testOne.IsUnique(emptyString))
        puts("Test 1 empty string case passed");
    else
        puts("Test 1 empty string case not passed");
}
