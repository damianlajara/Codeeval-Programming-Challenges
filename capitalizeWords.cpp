//
//  main.cpp
//  capitalizeWords
//
//  Created by Damian Lajara on 12/31/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 CAPITALIZE WORDS
 CHALLENGE DESCRIPTION:
 
 Write a program which capitalizes the first letter of each word in a sentence.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. Input example is the following
 
 Hello world
 javaScript language
 a letter
 1st thing
 OUTPUT SAMPLE:
 
 Print capitalized words in the following way.
 
 Hello World
 JavaScript Language
 A Letter
 1st Thing
 */

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    stringstream ss;
    string line;
    string word;
    if(file.is_open()) {
        while(getline(file, line)) {
            ss << line;
            while(ss >> word) {
                word[0] = toupper(word[0]);
                cout << word << " ";
            }
            cout << endl;
            ss << "";
            ss.clear();
        }
    } file.close();
    return 0;
}
