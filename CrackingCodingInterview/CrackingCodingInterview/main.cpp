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
}

void chapterOne(void){
    //construct test
    ArraysAndStrings testOne;
    string unique = "Unique";
    string notUnique = "nnn";
    string emptyString = "";
    string urltest1 = " Mr John Smith";
    string urltest2 = "       John Blah";
    string urltest3 = "Come With me Now ";
    //string pal = "Eva Can I Stab Bats In A Cave";
    string pal = "Deinfintely not a palindrome";
    string oneCorr = "banana";
    string oneOff1 = "bananana";
    string oneOff2 = "bananna";
    string oneOff3 = "banan";
    string oneOff4 = "bacana";
    
    //1-1
    puts("ch1.1 - IsUnique");
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
    
    //1-2
    puts("ch1.2 - Is Permutation");
    if(testOne.IsPermutation(unique, unique))
        puts("Test 1-2 permutation test passed");
    else
        puts("Test 1-2 permutation test failed");
    if(!testOne.IsPermutation("", " "))
        puts("Test 1-2 permutation test passed");
    else
        puts("Test 1-2 permutation test failed");
    if(!testOne.IsPermutation(notUnique, unique))
        puts("Test 1-2 permutation test passed");
    else
        puts("Test 1-2 permutation test failed");
    
    //1.3 URLify
    puts("ch1.3 - URLify");
    cout << "Test 1-3 :" << urltest1 << endl <<
    "Test 1-3 result : " << testOne.URLify(urltest1, (int)urltest1.length()) << endl;
    cout << "Test 1-3 :" << urltest2 << endl <<
    "Test 1-3 result : " << testOne.URLify(urltest2, (int)urltest2.length()) << endl;
    cout << "Test 1-3 :" << urltest3 << endl <<
    "Test 1-3 result : " << testOne.URLify(urltest3, (int)urltest3.length()) << endl;
    
    //1.4 Palindrome Permutation
    puts("ch1.4 - Palindrome Permutation");
    cout << "Test 1-4 " << pal << endl <<
    "Test 1-4 result : " << (testOne.palperm(pal) ? "Success" : "Failed") << endl;
    
    //1.5 One Away
    puts("ch1.5 - One Away");
    cout << "Test 1-5 : " << "banana vs bananana (Expected to fail)" << (testOne.OneAway(oneCorr, oneOff1) ? "pass" : "fail") << endl;
    cout << "Test 1-5 : " << "banana vs banan (Expected to pass)" << (testOne.OneAway(oneCorr, oneOff2) ? "pass" : "fail") << endl;
    cout << "Test 1-5 : " << "banana vs bananaa (Expected to pass)" << (testOne.OneAway(oneCorr, oneOff3) ? "pass" : "fail") << endl;
    cout << "Test 1-5 : " << "banana vs bacana (Expected to pass)" << (testOne.OneAway(oneCorr, oneOff4) ? "pass" : "fail") << endl;


}
