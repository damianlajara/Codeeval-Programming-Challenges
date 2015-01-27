//
//  main.cpp
//  penultimateWord
//
//  Created by Damian Lajara on 1/3/15.
//  Copyright (c) 2015 codeeval. All rights reserved.
//

/*
 PENULTIMATE WORD
 CHALLENGE DESCRIPTION:
 
 
 Write a program which finds the next-to-last word in a string.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. Input example is the following
 
 some line with text
 another line
 Each line has more than one word.
 
 OUTPUT SAMPLE:
 
 Print the next-to-last word in the following way.
 
 with
 another

 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    vector<string> fileContents;
    stringstream ss;
    string line,word;
    if(file.is_open()) {
        while(getline(file, line)) {
            ss << line;
            while(getline(ss, word, ' ')) {
                fileContents.push_back(word);
            }
            /**
             * If fileContents[fileContents.size()-1], is the last element(word)
             * in the vector, then fileContents[fileContents.size()-2] must
             * be the element(word) becore the last one, or the penultimate one
             */
            if(fileContents.size() > 0) {
                cout << fileContents[fileContents.size()-2];
                cout << endl;
            }
            
            //Reset for next line
            fileContents.clear();
            ss << "";
            ss.clear();
        }
    } file.close();
    return 0;
}
