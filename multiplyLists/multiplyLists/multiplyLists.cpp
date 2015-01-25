//
//  main.cpp
//  multiplyLists
//
//  Created by Damian Lajara on 1/8/15.
//  Copyright (c) 2015 Damian Lajara. All rights reserved.
//

/*
 MULTIPLY LISTS
 CHALLENGE DESCRIPTION:
 
 You have 2 lists of positive integers. Write a program which multiplies corresponding elements in these lists.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. Input example is the following
 
 9 0 6 | 15 14 9
 5 | 8
 13 4 15 1 15 5 | 1 4 15 14 8 2
 The lists are separated with a pipe char, numbers are separated with a space char.
 The number of elements in lists are in range [1, 10].
 The number of elements is the same in both lists.
 Each element is a number in range [0, 99].
 
 OUTPUT SAMPLE:
 
 Print the result in the following way.
 
 135 0 54
 40
 13 16 225 14 120 10

 */
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
void populateVector(size_t delim, string line, stringstream& ss, vector<int>& list) {
    string num;
    ss << line;
    while(ss >> num) {
        list.push_back(stoi(num));
    }
    ss << "";
    ss.clear();
}
int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    stringstream ss;
    vector<int> list1;
    vector<int> list2;
    string line,lhs,rhs;
    if(file.is_open()) {
        while(getline(file, line)) {
            
            unsigned long delim = line.find('|');
            
            lhs = line.substr(0, delim-1);
            rhs = line.substr(delim+2, line.length());
            
            populateVector(delim, lhs, ss, list1);
            populateVector(delim, rhs, ss, list2);
            
            for(int i = 0; i < list1.size(); i++) {
                i == list1.size()-1 ? cout << list1[i]*list2[i] : cout << list1[i]*list2[i] << " "; //trim trailing white space
            }
            cout << endl;
            
            //Reset vector for next line
            list1.clear();
            list2.clear();
        }
    } file.close();
    return 0;
}












