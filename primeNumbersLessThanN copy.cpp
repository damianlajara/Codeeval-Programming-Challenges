//
//  main.cpp
//  PrimeNumbersLessThanN
//
//  Created by Damian Lajara on 10/17/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 PRIME NUMBERS
 CHALLENGE DESCRIPTION:
 
 Print out the prime numbers less than a given number N. 
 For bonus points your solution should run in N*(log(N)) time or better. 
 You may assume that N is always a positive integer.
 
 INPUT SAMPLE:
 Your program should accept as its first argument a path to a filename. 
 Each line in this file is one test case. 
 Each test case will contain an integer n < 4,294,967,295. E.g.
 10
 20
 100
 
 OUTPUT SAMPLE:
 For each line of input, print out the prime numbers less than N, in ascending order, comma delimited. 
 (There should not be any spaces between the comma and numbers) E.g.
 2,3,5,7
 2,3,5,7,11,13,17,19
 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
 */

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
bool prime(int x);

int main(int argc, const char * argv[]) {
    
    int num = 0;
    ifstream file;
    file.open(argv[1]);
    //read file
    if(file.is_open()) {
        while(file>>num) {
            //if num taken from file is a 1 or 2,
            //then there will be no prime numbers to display
            if(num < 3) {
                cout << "None!\n";
                continue; //jump back to loop
            }
            //cout << num << ": "; //debug
            for (int i = 2; i < num; i++) {//find the primes up to num
                if (prime(i)) {
                    //if it's the first number (which is always 2 for primes)
                    //then don't print a comma, if it's not print it
                    //this creates the effect of removing trailing commas at the end
                    i == 2 ? cout << i : cout << "," << i;
                }
            }
            cout << endl;
        }
        file.close();
    }
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