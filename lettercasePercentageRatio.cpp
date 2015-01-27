//
//  main.cpp
//  lettercasePercentageRatio
//
//  Created by Damian Lajara on 10/26/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/**
 * Your goal is to find the percentage ratio of lowercase and uppercase letters in line below.
 *
 * INPUT SAMPLE:
 * Your program should accept as its first argument a path to a filename. Each line of input contains a string with uppercase and lowercase letters
 * E.g.:
 *
 * thisTHIS
 * AAbbCCDDEE
 * N
 * UkJ
 *
 * OUTPUT SAMPLE:
 * For each line from input, print the percentage ratio of uppercase and lowercase letters rounded to the second digit after the dot.
 * E.g.:
 *
 * lowercase: 50.00 uppercase: 50.00
 * lowercase: 20.00 uppercase: 80.00
 * lowercase: 0.00 uppercase: 100.00
 * lowercase: 33.33 uppercase: 66.67
 */

#include <iostream>
#include <fstream>
#include <iomanip> //set precision
using namespace std;

void calculatePercentage(float totalCharacters, int totalUppercase, int totalLowercase) {
    /**
     * Sets the number decimal places up to the precision parameter in precision();
     */
    cout.precision(2);
    
    /**
     * When floatfield is set to fixed, floating-point values are written using fixed-point notation:
     * the value is represented with exactly as many digits in the decimal part
     * as specified by the precision field (precision) and with no exponent part.
     */
    fixed(cout);
    
    float lowercasePercentage = (totalLowercase/totalCharacters)*100;
    float uppercasePercentage = (totalUppercase/totalCharacters)*100;
    
    cout << "lowercase: " << lowercasePercentage << " ";
    cout << "uppercase: " << uppercasePercentage << endl;
}

int main(int argc, const char * argv[]) {
    locale loc;
    ifstream file;
    string line;
    float totalCharacters = 0.00; //used float here for decimal precision in calculatePercentage()
    int totalUppercase = 0;
    int totalLowercase = 0;
    
    file.open(argv[1]);
    if(file.is_open()) {
        while(getline(file, line)) { //looping file line per line
            for(int i = 0; i < line.length(); i++) { //looping words character per character
                if(isupper(line[i], loc)) {
                    //increase the number of uppercase characters in the current line
                    totalUppercase++;
                } else {
                    //increase the number of lowercase characters in the current line
                    totalLowercase++;
                }
                totalCharacters++;
            }
            calculatePercentage(totalCharacters, totalUppercase, totalLowercase);
            
            totalCharacters = 0; //reset it for next line
            totalUppercase = 0;
            totalLowercase = 0;
        }
    }
    return 0;
}
