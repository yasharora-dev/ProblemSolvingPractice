//
//  MultiplyLargeNumbers.hpp
//  ProblemSolvingPractice
//
//  Created by Yash Arora on 19/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef MultiplyLargeNumbers_hpp
#define MultiplyLargeNumbers_hpp

#include <stdio.h>
#include <vector>

using namespace std;
class MultiplyLargeNumbers{

    
public:
    static vector<int> multiplyLargeNumbers(vector<int> &num1, vector<int> &num2);
    static vector<int> addLargeNumbers(vector<vector<int>> &multRes);
    static vector<int> addTwoLargeNums(vector<int> &num1,vector<int> &num2);
    static void Test_MultiplyLargeNumbers();
};
#endif /* MultiplyLargeNumbers_hpp */
