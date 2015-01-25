//
//  main.cpp
//  dataRecovery
//
//  Created by Damian Lajara on 1/18/15.
//  Copyright (c) 2015 Damian Lajara. All rights reserved.
//

/*
 https://www.codeeval.com/open_challenges/140/
 DATA RECOVERY
 CHALLENGE DESCRIPTION:
 
 Your friends decided to make fun of you. 
 They have installed a script on your computer which shuffled all words within a text. 
 It is a joke, so they have left hints for each sentence. 
 The hints will allow you to rebuild the data easily, but you need to find out how to use them.
 
 Your task is to write a program which reconstructs each sentence out of a set of words and prints out the original sentences.
 
 INPUT SAMPLE:
 
 Your program should accept a path to a filename as its first argument. 
 Each line is a test case which consists of a set of words and a sequence of numbers separated by a semicolon.
 The words within a set and the numbers within a sequence are separated by a single space.
 
 For example:
 
 2000 and was not However, implemented 1998 it until;9 8 3 4 1 5 7 2
 programming first The language;3 2 1
 programs Manchester The written ran Mark 1952 1 in Autocode from;6
 2 1 7 5 3 11 4 8 9
 
 OUTPUT SAMPLE:
 
 Print out a reconstructed sentence for each test case, one per line.
 
 For example:

 However, it was not implemented until 1998 and 2000
 The first programming language
 The Manchester Mark 1 ran programs written in Autocode from 1952
 
 CONSTRAINTS:
 
 The number of test cases is in a range from 20 to 40.
 The words consist of ASCII uppercase and lowercase letters, digits, and punctuation marks.

 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    ifstream file(argv[1]);
    string line,words,hints,wordInput,hintInput;
    map<int,string> myMap;
    int numWords;
    stringstream ssl,ssr;
    if(file.is_open()) {
        while(getline(file, line)) {
            unsigned long delim = line.find(';');
            if(delim != string::npos) {
                
                //Seperate the line into words and hints
                words = line.substr(0, delim);
                hints = line.substr(delim+1, line.length());
                
                //load into stream
                ssr << hints;
                ssl << words;
                
                //extract every word and hint and save in map as a pair
                while(ssl >> wordInput && ssr >> hintInput) {
                    numWords++;
                    myMap.insert(pair<int,string>(stoi(hintInput),wordInput));
                }
                //Since there is one less hint than there are words, get the last word also
                numWords++;
                ssl >> wordInput;
                
                //Find where the missing word should be
                int i = 0;
                bool missingElement = false; //keep track of test case where there is no missing number in the hint
                for (map<int,string>::iterator it= myMap.begin(); it!=myMap.end(); ++it) {
                    i++;
                    if(it->first != i) {
                        myMap.insert(pair<int, string>(i,wordInput)); //Found where the last word should be, so add it to the map in this position
                        missingElement = true;
                        break;
                    }
                }
                //If there is no missing number in the hint, e.g 3, 2, 1, then add the last word to the end of the sentence (3+1 or position 4 - the last position)
                if(!missingElement) {
                    myMap.insert(pair<int, string>(i+1,wordInput));
                }
                
                //Display the deciphered sentence
                for (map<int,string>::iterator it= myMap.begin(); it!=myMap.end(); ++it) {
                    cout << it->second << " ";
                }
                cout << endl;
            }
            //Reset everything for new line from file
            myMap.clear();
            ssl << "";
            ssr << "";
            ssl.clear();
            ssr.clear();
        }
    } file.close();
    return 0;
}
