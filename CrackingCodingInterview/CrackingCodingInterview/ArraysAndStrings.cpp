//
//  ArraysAndStrings.cpp
//  CrackingCodingInterview
//
//  Created by Kelly Kim on 4/15/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

#include "ArraysAndStrings.hpp"

//Cracking Coding interview
//1.1 Is Unique
//Implement an algorithm to determine if a string has all unique characters.
//What if you cannot use additional data structures?

//problem solving apporach
//ver.1 string manipulation through string class
//recursive solution to check substring of given string for first char to substring.
//this solution will run at Big O of (n^2))
//this solution also has high risk of memory overflow when string s is large
bool ArraysAndStrings::IsUnique(std::string s){
    //bool result;
    unsigned long length = s.size();
    //make decision for empty string, empty string will be considered unique
    if (length == 0)
        return true;
    else{
    //non recursive solution
        for (int i = 0; i < length; i++){
            //for size of string s
            //check first char is found in given string
            char temp = s.at(i);
            std::string sub = s.substr(i+1, length-(i+1));
            for(int j = 0; j < sub.size(); j++){
                if(temp == sub.at(j))
                    return false;
            }
        }
        return true;
    }
}
