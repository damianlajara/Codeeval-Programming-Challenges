//
//  main.cpp
//  fibonacciSeries
//
//  Created by Damian Lajara on 10/26/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 The Fibonacci series is defined as: F(0) = 0; F(1) = 1; F(n) = F(n-1) + F(n-2) when n>1. Given a positive integer 'n', print out the F(n).
 
 INPUT SAMPLE:
 The first argument will be a path to a filename containing a positive integer, one per line. E.g.
 
 5
 12
 
 OUTPUT SAMPLE:
 Print to stdout, the fibonacci number, F(n). E.g.
 
 5
 144
 */

#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;

int fibonacci(int n);

int main(int argc, const char * argv[]) {
    ifstream file;
    file.open(argv[1]);
    int num;
    if(file.is_open()) {
        while(file >> num) {
            cout << fibonacci(num) << endl;
        }
    }
    return 0;
}
int fibonacci(int n)
{
    /*
     Fibonacci sequence
     a0 = 0
     a1 = 1
     an = an-1 + an-2
     */
    
    //cases for 0 and 1
    if(n <= 1 )
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}