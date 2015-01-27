//
//  main.cpp
//  rollerCoasterCase
//
//  Created by Damian Lajara on 12/27/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 You are given a piece of text. Your job is to write a program that sets the case of text characters according to the following rules:
 - The first letter of the line should be in uppercase.
 - The next letter should be in lowercase.
 - The next letter should be in uppercase, and so on.
 Any characters, except for the letters, are ignored during determination of letter case.
 
 The first argument will be a path to a filename containing sentences, one per line. You can assume that all characters are from the English language.
 
 For example:
 To be, or not to be: that is the question.
 Whether 'tis nobler in the mind to suffer.
 The slings and arrows of outrageous fortune.
 Or to take arms against a sea of troubles.
 And by opposing end them, to die: to sleep.
 OUTPUT SAMPLE:
 
 Print to stdout the RoLlErCoAsTeR case version of the string.
 
 For example:
 To Be, Or NoT tO bE: tHaT iS tHe QuEsTiOn.
 WhEtHeR 'tIs NoBlEr In ThE mInD tO sUfFeR.
 ThE sLiNgS aNd ArRoWs Of OuTrAgEoUs FoRtUnE.
 Or To TaKe ArMs AgAiNsT a SeA oF tRoUbLeS.
 AnD bY oPpOsInG eNd ThEm, To DiE: tO sLeEp.
 CONSTRAINTS:
 
 The length of each piece of text does not exceed 1000 characters.
 */

#include <iostream>
#include <fstream>
using std::cout;
using std:: ifstream;
using std::endl;
using std::string;

int main(int argc, const char * argv[]) {
    ifstream input("input.txt"); //open file
    string line;
    if(input.is_open()) {
        while(getline(input,line)) {//looping file line per line
            int characterCount = -1; //keeps track of actual alphabetical characters in string (set it to -1, so it can be initialized to 0 with every loop)
            for(int i = 0; i < line.length(); i++) { //looping line character per character
                if(isalpha(line[i])) characterCount++; //if it's an alphabetical character, increase the character count (ignore spaces, commas, etc)
                if(characterCount % 2 == 0) { //by the first time characterCOunt gets here, it will be 0, making the first letter always capital!
                    line[i] = toupper(line[i]); //if even, then make it uppercase
                } else {
                    line[i] = tolower(line[i]); //if odd, then make it lowercase
                }
            }
            cout << line << endl; //display converted line
        }

    }
    input.close();
    return 0;
}