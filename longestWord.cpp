//
//  main.cpp
//  longestWord
//
//  Created by Damian Lajara on 12/31/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 LONGEST WORD
 CHALLENGE DESCRIPTION:
 
 In this challenge you need to find the longest word in a sentence. If the sentence has more than one word of the same length you should pick the first one.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. Input example is the following
 
 some line with text
 another line
 Each line has one or more words. Each word is separated by space char.
 
 OUTPUT SAMPLE:
 
 Print the longest word in the following way.
 
 some
 another
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
    string firstWord;
    if(file.is_open()) {
        //get line from file
        while(getline(file, line)) {
            ss << line;
            //read first word
            ss >> firstWord;
            //read the rest of the words
            while(ss >> word) {
                if(word.length() > firstWord.length()) {
                    firstWord = word;
                }
            }
            cout << firstWord << endl;
            
            //Reset stream for next line
            ss << "";
            ss.clear();
        }
    }file.close();
    return 0;
}