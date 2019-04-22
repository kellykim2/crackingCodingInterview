//
//  main.cpp
//  CrackingCodingInterview driver
//
//  Created by Kelly Kim on 4/15/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

#include <cstdio>
#include "ArraysAndStrings.hpp" //Ch1
#include "LinkedLists.hpp"      //Ch2
#define ARRAY_SIZE 5 //1-7


using namespace std;

void mainMenu(void);
void menuOne(void);
void menuTwo(void);
void chapterOne();
void chapterTwo(void);

int main(int argc, const char * argv[]) {
    
    puts("Cracking Coding Interview\nSolutions by Kelly Kim\nSolutions may not be final and work in progress");
    int selection = 0;
    do{
        mainMenu();
        cin >> selection;
        switch(selection){
            case 1:{
                chapterOne();
                break;
            }
            case 2:{
                chapterTwo();
                break;
            }
        }
    }while(selection != 0);
    
    return 0;
}

void mainMenu(void){
    puts("Select Chapter");
    puts("1: chapter 1");
    puts("2: chapter 2");
    puts("3: chapter 3");
    puts("4: chapter 4");
    puts("5: chapter 5");
    puts("6: chapter 6");
    puts("7: chapter 7");
    puts("8: chapter 8");
    puts("0: Exit");
}

void menuOne(void){
    puts("1: chapter 1-1");
    puts("2: chapter 1-2");
    puts("3: chapter 1-3");
    puts("4: chapter 1-4");
    puts("5: chapter 1-5");
    puts("6: chapter 1-6");
    puts("7: chapter 1-7");
    puts("8: chapter 1-8");
    puts("0: Return to Main Menu");
}

void chapterOne(void){
    //construct test
    menuOne();
    int selection = 0;
    do{
        menuOne();
        cin >> selection;
        if(selection != 0){
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
                case 1:{
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
                }
                //1-2
                case 2:{
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
                }
                //1.3 URLify
                case 3:{
                    puts("ch1.3 - URLify");
                    cout << "Test 1-3 :" << urltest1 << endl <<
                    "Test 1-3 result : " << testOne.URLify(urltest1, (int)urltest1.length()) << endl;
                    cout << "Test 1-3 :" << urltest2 << endl <<
                    "Test 1-3 result : " << testOne.URLify(urltest2, (int)urltest2.length()) << endl;
                    cout << "Test 1-3 :" << urltest3 << endl <<
                    "Test 1-3 result : " << testOne.URLify(urltest3, (int)urltest3.length()) << endl;
                    break;
                }
                //1.4 Palindrome Permutation
                case 4:{
                    puts("ch1.4 - Palindrome Permutation");
                    cout << "Test 1-4 " << pal << endl <<
                    "Test 1-4 result : " << (testOne.palperm(pal) ? "Success" : "Failed") << endl;
                    break;
                    
                }
                //1.5 One Away
                case 5:{
                    puts("ch1.5 - One Away");
                    cout << "Test 1-5 : " << "banana vs bananana (Expected to fail)" << (testOne.OneAway(oneCorr, oneOff1) ? "pass" : "fail") << endl;
                    cout << "Test 1-5 : " << "banana vs banan (Expected to pass)" << (testOne.OneAway(oneCorr, oneOff2) ? "pass" : "fail") << endl;
                    cout << "Test 1-5 : " << "banana vs bananaa (Expected to pass)" << (testOne.OneAway(oneCorr, oneOff3) ? "pass" : "fail") << endl;
                    cout << "Test 1-5 : " << "banana vs bacana (Expected to pass)" << (testOne.OneAway(oneCorr, oneOff4) ? "pass" : "fail") << endl;
                    break;
                }
                //1.6 String Compression
                case 6:{
                    puts("ch1.6 - String Compression");
                    cout << "Test 1-6: " << "abbcccdddd ->" << testOne.Compress("abbcccdddd") << endl;
                    break;
                }
                //1.7 matrix rotation
                case 7:{
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
                            cout << array[i][j] << ",\t";
                        }
                        cout << endl;
                    }
                    testOne.Rotate(array, ARRAY_SIZE);
                    puts("Result: 90 degree rotation");
                    for(int i = 0; i < ARRAY_SIZE; i++){
                        for(int j = 0; j < ARRAY_SIZE; j++){
                            cout << array[i][j] << ",\t";
                        }
                        cout << endl;
                    }
                    break;
                }
                case 8:{
                    // MxN ex of 8 x 5
                    int rows = 8;
                    int cols = 5;
                    int **matrix;
                    int val = 0;
                    //initializing with dynamic 2d array to test.
                    matrix = new int*[rows];
                    for(int i = 0; i < rows; i++){ matrix[i] = new int[cols]; }
                    for(int i = 0; i < rows; i++){
                        for(int j = 0; j < cols; j++){
                            matrix[i][j] = val++;
                        }
                    }
                    //pre
                    puts("MxN matrix before :");
                    for(int i = 0; i < rows; i++){
                        for(int j = 0; j < cols; j++){
                            cout << matrix[i][j] << ",\t";
                        }
                        cout << endl;
                    }
                    testOne.ZeroOut(matrix, rows, cols);
                    //post
                    puts("MxN matrix After :");
                    for(int i = 0; i < rows; i++){
                        for(int j = 0; j < cols; j++){
                            cout << matrix[i][j] << ",\t";
                        }
                        cout << endl;
                    }
                    
                    delete matrix;
                    break;
                }
            }//end switch
        }//end if
    }while(selection != 0);
}//end chapter one

void menuTwo(){
    puts("1: chapter 2-1");
    puts("2: chapter 2-2");
    puts("3: chapter 2-3");
    puts("4: chapter 2-4");
    puts("5: chapter 2-5");
    puts("6: chapter 2-6");
    puts("7: chapter 2-7");
    puts("8: chapter 2-8");
    puts("0: Return to Main Menu");
    
}
void chapterTwo(void){
    int selection = 0;
    do{
        menuTwo();
        cin >> selection;
        if (selection != 0) {
            switch(selection){
                case 1:{
                    LinkedLists myList;
                    myList.TempFillTen();
                    puts("Current List:");
                    myList.Print();
                    myList.RemoveDups();
                    puts("After removing dups:");
                    myList.Print();
                    break;
                }
                case 2:{
                    LinkedLists myList2;
                    myList2.TempFillTen();
                    puts("Ch.2.2 List:");
                    myList2.Print();
                    cout << "8th element is " << (myList2.KthToLast(8)->value) << endl;
                    break;
                }
                case 3:{
                    LinkedLists myList3;
                    myList3.TempFillTen();
                    puts("Ch2.3 List contains");
                    myList3.Print();
                    myList3.DeleteMiddle(myList3.KthToLast(5));
                    puts("Ch2.3 List after removing 5th node");
                    myList3.Print();
                    break;
                }
                case 4:{
                    LinkedLists myList4;
                    myList4.IntToList(123);
                    puts("ch2.4 List1 of 123 now contains");
                    myList4.Print();
                    LinkedLists myList5;
                    myList5.IntToList(345);
                    puts("ch2.4 List2 345 now contains");
                    myList5.Print();
                    int sum = myList4.SumList() + myList5.SumList();
                    LinkedLists myList6;
                    myList6.IntToList(sum);
                    puts("ch2.4 Sum of two lists contains:");
                    myList6.Print();
                    
                    break;
                }
                case 5:{
                    break;
                }
            }
        }
    }while(selection != 0 );
}
