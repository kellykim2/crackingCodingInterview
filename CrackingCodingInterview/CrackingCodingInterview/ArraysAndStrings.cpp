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
//the solution has BigO(n)

bool ArraysAndStrings::IsPermutation(std::string s1, std::string s2){
    if(s1.size() != s2.size()){
        return false;
    }else{
        //process s1
        std::unordered_map<char, int> hm;
        for(char c : s1){
            auto search = hm.find(c);
            if(search == hm.end()){
                //printf("\nInserting %c", c);
                hm.insert({c, 1});
            }
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
            //std::cout<<"Key: " << node.first << " Value: " << node.second << std::endl;
            if(node.second != 0)
                return false;
        }
        //return true since no false flag was triggered.
        return true;
    }
}

//1.3
//URLify write a method to replace all spaces in a string with "%20"
//you may assume that the string has sufficient space at the end to hold the additional characters, and that
//you are given the "true" length of the string.
std::string ArraysAndStrings::URLify(std::string s, int size){
    //take care of empty string
    std::string result = "";
    if(size == 0)
        return result;
    else{
        for(int i = 0; i < size; i++){
            if(s.at(i) == ' ')
                result += "%20";
            else
                result += s.at(i);
        }
    }
    return result;
}

//ch1-4
/*
 * Palindrome Permutation
 * Given a string, write a function to check if it is a permutation of a parlindrome
 * A parlindrome is a word or phrase that is same forwards and backwards. a permutation is a rearrangement of letters.
 * The palindrome does not need to be limited to just dictionary words.
 *
 * Approach #1 brute force
 * create all permutation of given string
 * check for palindrome
 *
 * approach #2 semi brute force
 * check if there is matching char count for a palindrome,
 * there must be a even number of chars and maybe 1 unique center char
 * then it is guaranteed for such permutation to exist since no need to check for dictionary words
 */

bool ArraysAndStrings::palperm(std::string s){
    std::unordered_map<char, int> count;
    //process the given string
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    for(char c : s){
        if(c == ' ')
            continue;
        if(count.find(c) == count.end()){
            count.insert({c,1});
        }else{
            count[c]++;
        }
    }
    //once done processing the given string, check for even numbers of chars and a single possible 1 count. space should not be accounted
    int flag = 0;
    for(const auto& node : count){
        if(node.second % 2 != 0)
            flag++;
    }
    if (flag > 1)
        return false;
    else
        return true;
 
}
