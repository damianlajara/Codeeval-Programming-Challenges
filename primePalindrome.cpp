//
//  main.cpp
//  primePalindrome
//
//  Created by Damian Lajara on 10/25/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 Write a program which determines the largest prime palindrome less than 1000.
 
 INPUT SAMPLE:
 There is no input for this program.
 
 OUTPUT SAMPLE:
 Print to stdout the largest prime palindrome less than 1000.
 
 929
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool prime(int x);
bool isPalindrome(int num);
int reverse(int num);

int sum = 0;
vector<int> primePalindromes;

int main(int argc, const char * argv[]) {
    
    for (int i = 2; i < 1000; i++) {
        if (prime(i) && isPalindrome(i)) {
            primePalindromes.push_back(i);
        }
    }
    //print out the last prime palindrome in the vector
    cout << primePalindromes[primePalindromes.size()-1];
    
    return 0;
}

bool prime(int x) {
    
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int reverse(int num)
{
    int test = 0;
    while (num != 0)
    {
        int lastdigit = num % 10;
        test = test * 10 + lastdigit;
        num = num / 10;
    }
    return test;
}

bool isPalindrome(int num)
{
    return num == reverse(num);
}
