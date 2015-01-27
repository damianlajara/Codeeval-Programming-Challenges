//
//  main.cpp
//  rightMostChar
//
//  Created by Damian Lajara on 10/26/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 CHALLENGE DESCRIPTION:
 
 You are given a string 'S' and a character 't'. 
 Print out the position of the rightmost occurrence of 't' 
 (case matters) in 'S' or -1 if there is none. 
 The position to be printed out is zero based.
 
 INPUT SAMPLE:
 The first argument will ba a path to a filename, containing a string and a character, comma delimited, one per line. 
 Ignore all empty lines in the input file. E.g.
 Hello World,r
 Hello CodeEval,E
 OUTPUT SAMPLE:
 
 Print out the zero based position of the character 't' in string 'S', one per line. 
 Do NOT print out empty lines between your output.
 E.g.
 
 8
 10
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    ifstream file;
    string line;
    unsigned long position;
    char character = ' '; //the char were trying to fine the right most occurence of
    file.open(argv[1]);
    //if file is open
    if(file.is_open()) {
        //loop through the file, line by line
        while(getline(file, line)) {
            //ignore all empty lines
            if(line.length() == 0) {
                continue;
            }
            //loop through every word, character by character
            for(int i = 0; i < line.length(); i++) {
                //if we reached the comma delimeter, the next char is what we are trying to find the right most occurence of
                if(line[i] == ',') {
                    character = line[i+1];
                    //create a substring with only the contents of everything BEFORE the delimeter,
                    //so it doesn't interfere with the algorithm for finding the rightmost char
                    line = line.substr(0,i);
                    break;
                }
            }
            position = line.find_last_of(character);
            //position = line.rfind(",");
            if(position != string::npos) {
                //[DEBUG] cout << "found " << character << " at position: " << position << endl;
                cout << position << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
