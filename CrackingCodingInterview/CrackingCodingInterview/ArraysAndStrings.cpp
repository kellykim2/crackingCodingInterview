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

//ch 1-5
/*
 * One Away: There are three types of edits that can be performed on string;
 * insert a character, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one (or zero) edit away.
 *
 * approach #1
 * First, Check character count and return false if more than one char difference.
 * Second, if equal # of char compare two string  one index at a time and flag up difference.
 * Third, if 1 difference in char count, at first unequal char, continue with 1 off indeces to compare rest.
 * Assumption #1 that s1 is the correct string
 */

bool ArraysAndStrings::OneAway(std::string s1, std::string s2){
    //test 1 size
    int size1 = s1.size();
    int size2 = s2.size();
    int difference = size1 - size2;
    int flag = 0;
    //test example
    /*
     banana vs bananna (one more
     banana vs baana   (one less
     banana vs baaana (same number but wrong char)
     */
    
    switch(difference){
        case 0://same number chars
            //check for char differences
            for(int i = 0; i < size1; i++){
                if(s1.at(i) != s2.at(i)){
                    flag++;
                }
            }
            break;
        case 1: //one less
            for(int i = 0; i < size1; i++){
                if(i+flag < size2 && s1.at(i+flag) != s2.at(i)){
                    flag++;
                }
            }
            break;
        case -1: //one more
            for(int i = 0; i < size1; i++){
                if(i+flag < size1 && s1.at(i) != s2.at(i+flag)){
                    flag++;
                }
            }
            break;
        default: //out of bound (more differences)
            return false;
    }
    if(flag > 1)
        return false;
    return true;
}
/*
 String Compression: Implement a method to perform basic string compression using the counts
 of repeated characters. For example, the string aabcccccaaa would become a2blc5a3, If the
 "compressed" string would not become smaller than the original string, your method should return
 the original string. You can assume the string has only uppercase and lowercase letters (a - z).
 
 approach
 Count number of chars that are same with at index at i
 then add number
 
 01234567890123456789
 
 */

std::string ArraysAndStrings::Compress(std::string s1){
    std::string result = "";
    for(int i = 0; i < s1.size(); i++){
        int count = 1;
        char temp = s1.at(i);
        while(count+i < s1.size() && temp == s1.at(i+count)){
            count++;
        }
        i += count;
        result += temp;
        //add a way to add integer to string for temp val.
    }
    if (s1.size() < result.size())
        return s1;
    return result;
}
