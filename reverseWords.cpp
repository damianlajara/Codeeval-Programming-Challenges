//
//  main.cpp
//  reverseWords
//
//  Created by Damian Lajara on 12/29/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 REVERSE WORDS
 CHALLENGE DESCRIPTION:
 
 Write a program which reverses the words in an input sentence.
 
 INPUT SAMPLE:
 
 The first argument is a file that contains multiple sentences, one per line. 
 Empty lines are also possible.
 
 For example:
 
 Hello World
 Hello CodeEval
 
 OUTPUT SAMPLE:
 
 Print to stdout each sentence with the reversed words in it, one per line. 
 Empty lines in the input should be ignored. 
 Ensure that there are no trailing empty spaces in each line you print.
 
 For example:
 
 World Hello
 CodeEval Hello
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::string;
using std::cout;
using std::stringstream;
using std::vector;
using std::endl;
using std::ifstream;

void reverseLine(vector<string>& words) {
    for(vector<string>::reverse_iterator it = words.rbegin(); it != words.rend(); it++) {
        it == words.rend()-1 ? cout << *it : cout << *it << " "; //trim spaces at the end
    }
    words.clear();
}

int main(int argc, const char * argv[]) {
    vector<string> words;
    ifstream file("input.txt");
    stringstream ss;
    string line;
    string word;
    if(file.is_open()) {
        while(getline(file, line)) {
            if(line.empty()) continue; //skip empty lines
            ss << line;
            while(ss >> word) {
                words.push_back(word);
            }
            reverseLine(words);
            cout << endl;
            ss << "";
            ss.clear();
        }
    } file.close();
    return 0;
}
