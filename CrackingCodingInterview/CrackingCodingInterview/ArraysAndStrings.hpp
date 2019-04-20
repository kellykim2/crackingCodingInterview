//
//  ArraysAndStrings.hpp
//  CrackingCodingInterview
//
//  Created by Kelly Kim on 4/15/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//

#ifndef ArraysAndStrings_hpp
#define ArraysAndStrings_hpp

#include <stdio.h>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <iostream>

class ArraysAndStrings{
private:
    
public:
    bool IsUnique(std::string); //ch1-1
    bool IsPermutation(std::string, std::string); //ch1-2
    std::string URLify(std::string, int); //ch1-3
    bool palperm(std::string); //ch 1-4
    bool OneAway(std::string, std::string);//ch1-5
    std::string Compress(std::string);//ch1-6
    void Rotate (int[5][5], int); //ch1-7
    void ZeroOut(int**,int, int); //ch1-8
    
};


#endif /* ArraysAndStrings_hpp */
