//
//  main.cpp
//  SumOfPrimes
//
//  Created by Damian Lajara on 9/26/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//
#include <iostream>
#include <cmath>
using namespace std;
bool prime(int x);
int sum = 0;
int isPrime = 0;
int main(int argc, const char * argv[]) {
    
    // Find the first 1000 primes which is (3682913)
    // NOT primes all the way up till 1000 which is(76127)
    for (int i = 2; isPrime < 1000; i++) {
        if (prime(i)) {
            isPrime++;
            sum += i;
        }
    }
    cout << sum << endl;
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