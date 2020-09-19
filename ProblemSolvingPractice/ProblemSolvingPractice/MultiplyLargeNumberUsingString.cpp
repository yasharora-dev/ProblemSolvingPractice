//
//  MultiplyLargeNumberUsingString.cpp
//  ProblemSolvingPractice
//
//  Created by Yash Arora on 19/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "MultiplyLargeNumberUsingString.hpp"
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


string MultiplyLargeNumberUsingString::addTwoLargeNums(string &str1,string &str2)
{
    int len1= str1.length();
    int len2 = str2.length();
    
    string sum;
    
    int i =len1-1,j=len2-1;
    int carry=0;
    while(i >=0  && j >=0)
    {
        int addition = ( (str1[i]-'0') + (str2[j]-'0') ) + carry;
        carry = addition/10;
        string digit = to_string(addition%10);

        sum.push_back(digit[0]);
        i--;
        j--;
    }
    while(i>=0)
    {
        int addition = (str1[i]-'0') + carry;
        carry = addition/10;
        string digit = to_string(addition%10);
        
        sum.push_back(digit[0]);
        i--;
    }
    
    while(j>=0)
    {
        int addition = (str2[j]-'0') + carry;
        carry = addition/10;
        string digit = to_string(addition%10);
        
        sum.push_back(digit[0]);
        j--;
    }
    
    if(carry>0)
    {
        string c =to_string(carry);
        sum.push_back(c[0]);
    }
    reverse(sum.begin(), sum.end());
    
    return sum;
}
string MultiplyLargeNumberUsingString::addLargeNumbers(vector<string> &multRes)
{
    int len = multRes.size();
    for(int i=0;i<len-1;i++)
    {
        string res = addTwoLargeNums(multRes[i], multRes[i+1]);
        multRes[i+1] = res;
    }
    
    return multRes.back();
}

string MultiplyLargeNumberUsingString::multiplyLargeNumbers(string num1,int len1,string num2,int len2)
{
    vector<string> mulAns(len2);
    int count =0;
    for(int i=len2-1;i>=0;i--)
    {
        string mul(len1+1,'0');
        int carry=0;
        int multiplier = num2[i]-'0';
        mul.reserve(len1);
        int product;
        for(int j=len1;j>0;j--)
        {
            product = (multiplier * (num1[j-1]-'0')) + carry;
            string ans = to_string(product % 10);
            carry = product/10;
            mul[j] = ans[0];
        }
        if(carry>0)
        {
            string carryStr = to_string(carry);
            mul[0] = carryStr[0];
        }
        
        mulAns[count] = mul;
        count++;
        
    }
    
    
    for(int i=1;i<mulAns.size();i++)
    {
        for(int j=0;j<i;j++)
            mulAns[i].push_back('0');
    }
    
    string result = addLargeNumbers(mulAns);
    return result;
}

void MultiplyLargeNumberUsingString::Test_MultiplyLargeNumberUsingString()
{
    //string num1 = "111"; //723
    string num1 = "31189283982";
    string num2 = "23489238";
    
    int len1 = num1.length();
    int len2 = num2.length();
    
    string ans = multiplyLargeNumbers(num1,len1,num2,len2);
    
    cout<<"Multiplication of "<<num1<<" and "<<num2<<" is: "<<ans<<endl;
    

}


