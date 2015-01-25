//
//  main.cpp
//  simpleSorting
//
//  Created by Damian Lajara on 1/17/15.
//  Copyright (c) 2015 Damian Lajara. All rights reserved.
//

/*
 SIMPLE SORTING
 CHALLENGE DESCRIPTION:
 
 
 Write a program which sorts numbers.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. Input example is the following
 
 70.920 -38.797 14.354 99.323 90.374 7.581
 -37.507 -3.263 40.079 27.999 65.213 -55.552
 
 OUTPUT SAMPLE:
 
 Print sorted numbers in the following way. Please note, that you need to print the numbers till the 3rd digit after the dot including trailing zeros.
 
 -38.797 7.581 14.354 70.920 90.374 99.323
 -55.552 -37.507 -3.263 27.999 40.079 65.213
 
 SUBMIT SOLUTION
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    vector<float> vec;
    string line, input;
    stringstream ss;
    cout.precision(3);
    cout << fixed;
    if(file.is_open()) {
        while(getline(file, line)) {
            ss << line;
            while(getline(ss, input, ' ')) {
                vec.push_back(stof(input));
            }
            sort(vec.begin(), vec.end());
            for(size_t i = 0; i < vec.size(); i++) {
                cout << vec[i] << " ";
            }
            cout << endl;
            ss << "";
            ss.clear();
            vec.clear();
        }
    }
    return 0;
}
