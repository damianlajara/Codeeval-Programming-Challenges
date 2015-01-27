//
//  main.cpp
//  compressedSequence
//
//  Created by Damian Lajara on 12/29/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 COMPRESSED SEQUENCE
 CHALLENGE DESCRIPTION:
 
 Assume that someone dictates you a sequence of numbers and you need to write it down. 
 For brevity, he dictates it as follows: first says the number of consecutive 
 identical numbers and then says the number itself. E.g. 
 The sequence 1 1 3 3 3 2 2 2 2 14 14 14 11 11 11 2 will be dictated as 
 "Two times one, three times three, four times two, three times fourteen, 
 three times eleven, one time two", so you will write down the sequence 
 2 1 3 3 4 2 3 14 3 11 1 2. The challenge is to write the program which 
 compresses the given sequence using this approach.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. 
 The input file contains T lines. Each line is a test case represented by a
 sequence of integers L, where each integer is N, separated by a whitespace. E.g
 
 40 40 40 40 29 29 29 29 29 29 29 29 57 57 92 92 92 92 92 86 86 86
 86 86 86 86 86 86 86
 73 73 73 73 41 41 41 41 41 41 41 41 41 41
 1 1 3 3 3 2 2 2 2 14 14 14 11 11 11 2
 7
 
 OUTPUT SAMPLE:
 
 For each test case produce a single line of output containing a compressed sequence of numbers separated by a single space char. E.g.
 
 4 40 8 29 2 57 5 92 10 86
 4 73 10 41
 2 1 3 3 4 2 3 14 3 11 1 2
 1 7
 Constraints:
 T is in range [20, 50]
 N is in range [0, 99]
 L length is in range [1, 400]
 */

#include <iostream>
#include <fstream>
#include <sstream>

using std::endl;
using std:: ifstream;
using std::stringstream;
using std::string;
using std::cout;

int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    stringstream ss;
    int num;
    int firstNum = 0;
    int count = 0;
    string line;
    if(file.is_open()) {
        //get the whole line
        while(getline(file, line)) {
            ss << line;
            //read first integer from the line
            ss >> firstNum;
            //continue reading the rest of the integers from the line
            while(ss >> num) {
                count++;
                if(num != firstNum) {
                    //we found a new number
                    cout << count << " " << firstNum << " ";
                    firstNum = num;
                    count = 0;
                }
            }
            //display the last number of the line
            cout << count+1 << " " << firstNum << endl;
            
            //reset values
            count = 0;
            ss << "";
            ss.clear();
        }
    } file.close();
    return 0;
}