//
//  MultiplyLargeNumberUsingString.hpp
//  ProblemSolvingPractice
//
//  Created by Yash Arora on 19/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef MultiplyLargeNumberUsingString_hpp
#define MultiplyLargeNumberUsingString_hpp

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;
class MultiplyLargeNumberUsingString{

    
public:
    static string multiplyLargeNumbers(string num1,int len1,string num2,int len2);
    static string addLargeNumbers(vector<string> &multRes);
    static string addTwoLargeNums(string &str1,string &str2);
    static void Test_MultiplyLargeNumberUsingString();
};
#endif /* MultiplyLargeNumberUsingString_hpp */
