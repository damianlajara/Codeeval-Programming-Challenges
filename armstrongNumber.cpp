//
//  main.cpp
//  armstrongNumber
//
//  Created by Damian Lajara on 1/4/15.
//  Copyright (c) 2015 codeeval. All rights reserved.
//

/*
 ARMSTRONG NUMBERS
 CHALLENGE DESCRIPTION:
 
 
 An Armstrong number is an n-digit number that is equal to the sum of the n'th powers of its digits. 
 Determine if the input numbers are Armstrong numbers.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. 
 Each line in this file has a positive integer. E.g.

 6
 153
 351
 
 OUTPUT SAMPLE:
 
 Print out True/False if the number is an Armstrong number or not. E.g.
 
 True
 True
 False

 */
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    vector<int> vec;
    string num;
    int sum = 0;
    int count = 0;
    if(file.is_open()) {
        while(file >> num) {
            //Store each individual number from the string into the vector
            for(int i = 0; i < num.length(); i++) {
                count++; //keep track of length of number
                vec.push_back(static_cast<int>(num[i])-48); //convert char(ascii) to it's int equivalent
            }
            //Add the sum of powers
            for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
                sum += pow(*it, count);
            }
            //if the sum of it's powers is equal to original number, then its an armstrong number!
            if(sum == stoi(num)) cout << "True" << endl;
            else cout << "False" << endl;
            
            //Reset values for next line
            sum = 0;
            count = 0;
            vec.clear();
        }
    } file.close();
    return 0;
}