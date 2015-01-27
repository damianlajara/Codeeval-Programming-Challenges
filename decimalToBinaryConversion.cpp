//
//  main.cpp
//  decimalToBinaryConversion
//
//  Created by Damian Lajara on 10/17/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 INPUT SAMPLE:
 Your program should accept as its first argument a path to a filename containing whole decimal numbers greater or equal to 0, one per line.
 Ignore all empty lines. E.g.
 2
 10
 67
 
 OUTPUT SAMPLE:
 Print the binary representation, one per line. E.g.
 10
 1010
 1000011
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
//does the conversion calculations
void convert(int& num, vector<int>& vec);
//reverses the array from index to lastElement.
//ex: 123 and index is 1 and last element is 3, it will be 321
void reversePrintVector(vector<int>& vec, int index, unsigned long lastElement);

int main(int argc, const char * argv[]) {
    vector<int> binaryVector;
    int num = 0;
    
    ifstream file;
    file.open("input.txt");//argv[1]
    if(file.is_open()) {
        while(file>>num) {
            if (num < 0) continue; //ignore empty lines
            convert(num,binaryVector);
            cout << endl;
        }
    }
    return 0;
}

void convert(int& num, vector<int>& binaryVector) {
    int remainder;
    
    //default case for when number is a 0
    if(num == 0) {
        binaryVector.push_back(num);
        reversePrintVector(binaryVector,0,binaryVector.size()-1);
        return; //exit
    }
    while(num != 0) {
        remainder = num % 2;
        //cout << "[DEBUG] remainder after dividing " << num << "/2: " << remainder << endl;
        binaryVector.push_back(remainder);
        num /= 2;
        //cout << "[DEBUG] number: " << num << endl;
    }
    reversePrintVector(binaryVector,0,binaryVector.size()-1);
}

void reversePrintVector(vector<int>& binaryVector, int index, unsigned long lastElement) { //unsigned long
    
    int temp;
    while(index < lastElement) {
        temp = binaryVector[index];
        binaryVector[index] = binaryVector[lastElement];
        binaryVector[lastElement] = temp;
        index++;
        lastElement--;
    }
    
    //print out the newly reversed vector
    for(int i = 0; i < binaryVector.size(); ++i) {
        cout << binaryVector[i];
    }
    //Clear the vector, so it can be used again!
    binaryVector.clear();
    
}



