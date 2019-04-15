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
//a recursive solution has high risk of memory overflow when string s is large
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

//1.2 Check Permutation
//Given two strings, write a method to decide if one is a permutation of the other.

//problem solving approach
//criteria #1 check length of two strings
//criteria #2 put components of one string into hash table using char as key,
//and account each index to be equal at the end

bool ArraysAndStrings::IsPermutation(std::string s1, std::string s2){
    if(s1.size() != s2.size()){
        return false;
    }else{
        //process s1
        std::unordered_map<char, int> hm;
        for(char c : s1){
            auto search = hm.find(c);
            if(search == hm.end())
                hm.insert({c, 0});
            else{
                hm[c]++;
            }
        }
        //process s2
        for(char c: s2){
            auto search = hm.find(c);
            if(search == hm.end()){
                return false; //unknown char found. not permutation
            }else{
                hm[c]--;
            }
        }
        //now iterate through hashmap to check non zero value
        for(const auto& node : hm){
            if(node.second != 0)
                return false;
        }
        //return true since no false flag was triggered.
        return true;
    }
}
