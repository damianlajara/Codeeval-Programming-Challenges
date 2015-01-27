//
//  main.cpp
//  mixedContent
//
//  Created by Damian Lajara on 1/3/15.
//  Copyright (c) 2015 codeeval. All rights reserved.
//

/*
 MIXED CONTENT
 CHALLENGE DESCRIPTION:
 
 
 You have a string of words and digits divided by comma. 
 Write a program which separates words with digits. 
 You shouldn't change the order elements.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. 
 Input example is the following
 
 8,33,21,0,16,50,37,0,melon,7,apricot,peach,pineapple,17,21
 24,13,14,43,41
 
 OUTPUT SAMPLE:
 
 melon,apricot,peach,pineapple|8,33,21,0,16,50,37,0,7,17,21
 24,13,14,43,41
 As you cas see you need to output the same input string if it has words 
 only or digits only.
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

bool isString(string input) {
    for(int i = 0; i < input.length(); i++) {
        if(isalpha(input[i])) {
            //it's a letter
            continue;
        } else {
            //it's not a letter
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    vector<string> fileStrings;
    vector<string> fileNums;
    stringstream ss;
    string line, input;
    if(file.is_open()) {
        while(getline(file, line)) {
            if(line.empty()) continue;
            ss << line;
            
            while(getline(ss, input, ',')) {
                if(isString(input)) fileStrings.push_back(input);
                else fileNums.push_back(input);
            }
            
            if(fileStrings.size() > 0) {
                cout << fileStrings[0];
                for(size_t i = 1; i < fileStrings.size(); i++) {
                    cout << "," << fileStrings[i];
                }
                if(fileNums.size() > 0) cout << "|";
            }
            
            if(fileNums.size() > 0) {
                cout << fileNums[0];
                for(size_t i = 1; i < fileNums.size(); i++) {
                    cout << "," << fileNums[i];
                }
            }
            cout << endl;
            fileStrings.clear();
            fileNums.clear();
            ss << "";
            ss.clear();
        }
    } file.close();

    return 0;
}