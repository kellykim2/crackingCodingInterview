//
//  main.cpp
//  CrackingCodingInterview driver
//
//  Created by Kelly Kim on 4/15/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

#include <cstdio>
#include "ArraysAndStrings.hpp"
#define ARRAY_SIZE 5 //1-7


using namespace std;

void menu(void);
void chapterOne(int);

int main(int argc, const char * argv[]) {
    
    puts("Cracking Coding Interview\nSolutions by Kelly Kim\nSolutions may not be final and work in progress");
    int selection = 0;
    do{
        menu();
        cin >> selection;
        chapterOne(selection);
    }while(selection != 0);
    
    return 0;
}

void menu(void){
    puts("menu");
    puts("1: chapter 1-1");
    puts("2: chapter 1-2");
    puts("3: chapter 1-3");
    puts("4: chapter 1-4");
    puts("5: chapter 1-5");
    puts("6: chapter 1-6");
    puts("7: chapter 1-7");
    puts("0: Exit");
}

void chapterOne(int selection){
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
    
    switch(selection){
    //1-1
        case 1:
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
            break;
            
        //1-2
        case 2:
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
            break;
            
        //1.3 URLify
        case 3:
            puts("ch1.3 - URLify");
            cout << "Test 1-3 :" << urltest1 << endl <<
            "Test 1-3 result : " << testOne.URLify(urltest1, (int)urltest1.length()) << endl;
            cout << "Test 1-3 :" << urltest2 << endl <<
            "Test 1-3 result : " << testOne.URLify(urltest2, (int)urltest2.length()) << endl;
            cout << "Test 1-3 :" << urltest3 << endl <<
            "Test 1-3 result : " << testOne.URLify(urltest3, (int)urltest3.length()) << endl;
            break;

        //1.4 Palindrome Permutation
        case 4:
            puts("ch1.4 - Palindrome Permutation");
            cout << "Test 1-4 " << pal << endl <<
            "Test 1-4 result : " << (testOne.palperm(pal) ? "Success" : "Failed") << endl;
            break;
            

        //1.5 One Away
        case 5:
            puts("ch1.5 - One Away");
            cout << "Test 1-5 : " << "banana vs bananana (Expected to fail)" << (testOne.OneAway(oneCorr, oneOff1) ? "pass" : "fail") << endl;
            cout << "Test 1-5 : " << "banana vs banan (Expected to pass)" << (testOne.OneAway(oneCorr, oneOff2) ? "pass" : "fail") << endl;
            cout << "Test 1-5 : " << "banana vs bananaa (Expected to pass)" << (testOne.OneAway(oneCorr, oneOff3) ? "pass" : "fail") << endl;
            cout << "Test 1-5 : " << "banana vs bacana (Expected to pass)" << (testOne.OneAway(oneCorr, oneOff4) ? "pass" : "fail") << endl;
            break;
            
        //1.6 String Compression
        case 6:
            puts("ch1.6 - String Compression");
            cout << "Test 1-6: " << "abbcccdddd ->" << testOne.Compress("abbcccdddd") << endl;
            break;
        
        //1.7 matrix rotation
        case 7:
            puts("ch1.7 - matrix rotation nxn");
            int array[ARRAY_SIZE][ARRAY_SIZE];
            int fill = 0;
            for(int i = 0; i < ARRAY_SIZE; i++){
                for(int j = 0; j < ARRAY_SIZE; j++){
                    array[i][j] = fill++;
                }
            }
            puts("Before 90 degree rotation");
            for(int i = 0; i < ARRAY_SIZE; i++){
                for(int j = 0; j < ARRAY_SIZE; j++){
                    cout << array[i][j] << ", ";
                }
                cout << endl;
            }
            testOne.Rotate(array, ARRAY_SIZE);
            puts("Result: 90 degree rotation");
            for(int i = 0; i < ARRAY_SIZE; i++){
                for(int j = 0; j < ARRAY_SIZE; j++){
                    cout << array[i][j] << ", ";
                }
                cout << endl;
            }
            
            
            break;
            
    }
}
