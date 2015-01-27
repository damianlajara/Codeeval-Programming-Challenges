//
//  main.cpp
//  sumOfPrecedingDigits
//
//  Created by Damian Lajara on 10/10/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 
 Given a positive integer, find the sum of its constituent digits.
 INPUT SAMPLE:
 The first argument will be a path to a filename containing positive integers, one per line. E.g.
 23
 496
 
 OUTPUT SAMPLE:
 Print to stdout, the sum of the numbers that make up the integer, one per line. E.g.
 5
 19
 
 */
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int numFromFile;
    ifstream file;
    file.open(argv[1]);
    if(file.is_open()) {
        //loop through file
        while(file >> numFromFile) {
            int i = 0;
            int sum = 0;
            //loop lines and get number
            while(numFromFile > 0) {
                sum += numFromFile % 10;
                numFromFile /= 10;
                i++;
            }
            cout << sum << endl;
        }
        file.close();
    }

    
    return 0;
}

/*
 For example, 1234%100 = 234. 1234%10 = 34.
 */

    
