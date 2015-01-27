//
//  main.cpp
//  swapCase
//
//  Created by Damian Lajara on 12/31/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 SWAP CASE
 CHALLENGE DESCRIPTION:
 
 
 Write a program which swaps letters' case in a sentence. 
 All non-letter characters should remain the same.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. 
 Input example is the following
 
 Hello world!
 JavaScript language 1.8
 A letter
 
 OUTPUT SAMPLE:
 
 Print results in the following way.
 
 hELLO WORLD!
 jAVAsCRIPT LANGUAGE 1.8
 a LETTER

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
        //read line from file
        while(getline(file, line)) {
            ss << line;
            //read words from line
            while(ss >> word) {
                //read characters from words
                for(int i = 0; i < word.length(); i++) {
                    if(isalpha(word[i])) {
                        if(isupper(word[i])) word[i] = tolower(word[i]);
                        else word[i] = toupper(word[i]);
                    }
                }
                cout << word << " ";
            }
            
            //reset stream for next line
            cout << endl;
            ss << "";
            ss.clear();
        }
    }file.close();
    return 0;
}
