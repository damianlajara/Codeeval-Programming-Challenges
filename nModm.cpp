//
//  main.cpp
//  NmodM
//
//  Created by Damian Lajara on 1/3/15.
//  Copyright (c) 2015 codeeval. All rights reserved.
//

/*
 N MOD M
 CHALLENGE DESCRIPTION:
 
 
 Given two integers N and M, calculate N Mod M (without using any inbuilt modulus operator).
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. Each line in this file contains two comma separated positive integers. E.g.
 
 20,6
 2,3
 You may assume M will never be zero.
 
 OUTPUT SAMPLE:
 
 Print out the value of N Mod M
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    /**
     * Ex: 16 % 5 = 1
     * N = 16, M = 5
     * 16/5 = 3 (N/M)
     * 3*5 = 15 ((N/M)*M)
     * 16 - 15 = 1 (N - ((N/M)*M))
     * 1 = remainder(modulo)
     */
    ifstream file("input.txt");
    vector<int> fileNumbers;
    stringstream ss;
    string line;
    string num;
    int N,M;
    if(file.is_open()) {
        while(getline(file, line)) {
            ss << line;
            while(getline(ss, num, ',')) {
                fileNumbers.push_back(stoi(num));
            }
            N = fileNumbers[0];
            M = fileNumbers[1];
            cout << N - ((N/M)*M) << endl;
            
            //Reset for next line
            fileNumbers.clear();
            ss << "";
            ss.clear();
        }
    } file.close();
    
    return 0;
}
