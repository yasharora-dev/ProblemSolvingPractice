//
//  MultiplyLargeNumbers.cpp
//  ProblemSolvingPractice
//
//  Created by Yash Arora on 19/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "MultiplyLargeNumbers.hpp"
#include <iostream>

//multiply two large numbers for e.g. num of length 500
//this cannot be done using standard operations as it cannot fit the DS
//So what we can use here is string or linked to store the numbers and implement the multiply operaation
// store both numbers in string
// the result of each multiplication should be stored in one string
// and then after all digits have been multiplied adjust the list by appending zeroes at the end
// for e.g. for 111*234
// 1. multiply 4 with 111 and store it in str1
// 2. multiply 3 with 111 and store it in str2
// 3. multiply 2 with 111 and store it in str2
//now as 3 is 2nd digit from right append one zero at the end of str2
//same append two zeroes at end of str3 a
//repeat for all answers

//now add all the str1 str2 str3 same as adding two numbers using linked list approach

vector<int> MultiplyLargeNumbers::addTwoLargeNums(vector<int> &str1,vector<int> &str2)
{
    int len1= str1.size();
    int len2 = str2.size();
    
    vector<int> sum;
    
    int i =len1-1,j=len2-1;
    int carry=0;
    while(i >=0  && j >=0)
    {
        //int addition = ( (str1[i]-'0') + (str2[j]-'0') ) + carry;
        int addition = str1[i] + str2[j] + carry;
        carry = addition/10;
        int digit = addition%10;

        sum.push_back(digit);
        i--;
        j--;
    }
    while(i>=0)
    {
        int addition = str1[i] + carry;
        carry = addition/10;
        int digit = addition%10;
        
        sum.push_back(digit);
        i--;
    }
    
    while(j>=0)
    {
        int addition = (str2[j]) + carry;
        carry = addition/10;
        int digit = (addition%10);
        
        sum.push_back(digit);
        j--;
    }
    
    if(carry>0)
    {
        sum.push_back(carry);
    }
    reverse(sum.begin(), sum.end());
    
    return sum;
}
vector<int> MultiplyLargeNumbers::addLargeNumbers(vector<vector<int>> &multRes)
{
    int len = multRes.size();
    for(int i=0;i<len-1;i++)
    {
        multRes[i+1] = addTwoLargeNums(multRes[i], multRes[i+1]);
    }
    
    return multRes.back();
}

vector<int> MultiplyLargeNumbers::multiplyLargeNumbers(vector<int> &num1,vector<int> &num2)
{
    int len1= num1.size();
    int len2 = num2.size();
    
    vector<vector<int>> mulAns(len2);
    
    int count =0;
    for(int i=len2-1;i>=0;i--)
    {
        vector<int> mul(len1+1,0);
        int carry=0;
        int multiplier = num2[i];
        //mul.reserve(len1);
        int product;
        for(int j=len1;j>0;j--)
        {
            product = (multiplier * (num1[j-1])) + carry;
            mul[j] = (product % 10);
            carry = product/10;
            
        }
        if(carry>0)
        {
            mul[0] = carry;
        }
        
        mulAns[count] = mul;
        count++;
        
    }
    
    
    for(int i=1;i<mulAns.size();i++)
    {
        for(int j=0;j<i;j++)
            mulAns[i].push_back(0);
    }
    
    vector<int> result = addLargeNumbers(mulAns);
    return result;
}






void MultiplyLargeNumbers::Test_MultiplyLargeNumbers()
{
    //vector<int> num1 {3,1,1};
    //vector<int> num2 {2,3,4};
    
    vector<int> num1 = { 3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2,3,1,1,8,9,2,8,3,9,8,2 };
    vector<int> num2 = { 2,3,4,8,9,3,8,2,3,4,8,9,3,8,2,3,4,8,9,3,8,3,4,8,9,3,8,3,4,8,9,3,8 ,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8,8,3,4,8,9,3,8  };
    vector<int> ans = multiplyLargeNumbers(num1,num2);
    
    cout<<"Multiplication of below two Numbers is:"<<endl;
    
    cout<<"Input1: ";
    for(auto x:num1)
        cout<<x;
    cout<<endl;
    
    cout<<"Input2: ";
    for(auto x:num2)
        cout<<x;
    cout<<endl;
    
    cout<<"Output: "<<endl;
    for(auto x:ans)
        cout<<x;
    cout<<endl;
    
    
}
