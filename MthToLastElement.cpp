//
//  main.cpp
//  MthToLastElement
//
//  Created by Damian Lajara on 1/5/15.
//  Copyright (c) 2015 codeeval. All rights reserved.
//

//https://www.codeeval.com/public_sc/10/

/*
 MTH TO LAST ELEMENT
 SPONSORING COMPANY:
 
 
 CHALLENGE DESCRIPTION:
 
 
 Write a program which determines the Mth to the last element in a list.
 
 INPUT SAMPLE:
 
 The first argument is a path to a file. The file contains the series of space delimited characters followed by an integer. The integer represents an index in the list (1-based), one per line.
 
 For example:
 
 a b c d 4
 e f g h 2
 
 OUTPUT SAMPLE:
 
 Print to stdout the Mth element from the end of the list, one per line. If the index is larger than the number of elements in the list, ignore that input.
 
 For example:
 a
 g
 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    if(file.is_open()) {
        vector<string> vec;
        string line,input;
        while(getline(file, line)) {
            if(line.empty()) continue;
            stringstream ss(line);
            while(ss >> input) {
                vec.push_back(input);
            }
            int index = stoi(vec[vec.size()-1]);
            if(index > vec.size()-1) { //1 based not 0 based
                vec.clear();
                continue; //ignore input
            }
            int positionPointer = 0;
            size_t letterPointer = vec.size()-1;
            for(vector<string>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++, positionPointer++, letterPointer--) {
                if(positionPointer == index) {
                    cout << vec[letterPointer] << endl;
                }
            }
            //Clear for next line
            vec.clear();
        }
    } file.close();
    return 0;
}