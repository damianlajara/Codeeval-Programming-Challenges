//
//  main.cpp
//  toLower
//
//  Created by Damian Lajara on 10/24/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

/*
 Given a string write a program to convert it into lowercase.
 
 INPUT SAMPLE:
 The first argument will be a path to a filename containing sentences, one per line. 
 You can assume all characters are from the english language. 
 
 E.g.
 HELLO CODEEVAL
 This is some text
 
 OUTPUT SAMPLE:
 Print to stdout, the lowercase version of the sentence, each on a new line. 
 
 E.g.
 hello codeeval
 this is some text
 */

#include <iostream>
#include <fstream>
#include <locale> //locale, tolower
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream file;
    string line;
    locale loc; //use default systems locale and encoding(english aplhabet)
    file.open(argv[1]);
    if(file.is_open()) {
        while(getline(file, line)) {
            for(int i = 0; i < line.length(); i++) {
                cout << tolower(line[i], loc); //print out every character converted to lowercase
            }
            cout << endl; //end the line, so every sentence appears in a different line
        }
    }
    return 0;
}
