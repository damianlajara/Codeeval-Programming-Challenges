//
//  main.cpp
//  fizzBuzzFile
//
//  Created by Damian Lajara on 10/5/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 INPUT SAMPLE:
 Your program should accept a file as its first argument. The file contains multiple separated lines;
 each line contains 3 numbers that are space delimited. 
 The first number is the first divider (X), the second number is the second divider (Y), and the third number is how far you should count (Z). 
 You may assume that the input file is formatted correctly and the numbers are valid positive integers.
 
 For example, 
 line 1) 3 5 10
 line 2) 2 7 15
 
 OUTPUT SAMPLE:
 Print out the series 1 through Z replacing numbers divisible by X with “F”, numbers divisible by Y with “B”
 and numbers divisible by both with “FB”.
 Since the input file contains multiple sets of values, your output should print out one line per set. 
 Ensure that there are no trailing empty spaces in each line you print.
 
 For example,
 line 1) 1 2 F 4 B F 7 8 F B
 line 2) 1 F 3 F 5 F B F 9 F 11 F 13 FB 15
 */

#include <iostream>
#include <fstream>
//using namespace std; //Don't use this because it puts extra files into program
using std::cout;
using std::ifstream;
using std::endl;
//prototype
void fizzBuzz(int& firstDivider, int& secondDivider, int& count);

int main(int argc, const char * argv[]) {
    
    int line = 0; //will hold the contents of the file
    int numOfIterations = 0;
    int firstDivider = 0;
    int secondDivider = 0;
    int count = 0;
    
    ifstream file;
    file.open(argv[1]);
    //read file
    if(file.is_open()) {
        while(file>>line) {
            if(numOfIterations == 0) firstDivider = line;
            else if(numOfIterations == 1) secondDivider = line;
            else if(numOfIterations == 2){
                //if it's it reached 2, then we finished the first line
                count = line;
                fizzBuzz(firstDivider, secondDivider, count); //check for fizzbuzz
                numOfIterations = 0;//restart for second line in input file
                continue; //skip back to the loop, so we can avoid 'numOfIterations++' right after resetting it
            }
            numOfIterations++;
        }
        
        
        cout << endl; //to seperate each line, so you can see the info clearer
        
        file.close();
    }
    
}

void fizzBuzz(int& firstDivider, int& secondDivider, int& count) {
    
    for(int x = 1; x <= count; x++){
        //FizzBuzz
        if ((x % firstDivider == 0) && (x % secondDivider == 0)) {
            //if we reached the last number in the line, then don't print spaces
            //in order to avoid trailing zero's
            x == count ? cout << "FB" : cout << "FB ";
        }
        //Fizz
        else if (x % firstDivider == 0){
            x == count ? cout << "F" : cout << "F ";
        }
        //Buzz
        else if (x % secondDivider == 0){
            x == count ? cout << "B" : cout << "B ";
        }
        //None, so show original number
        if((x % firstDivider != 0) && (x % secondDivider != 0)){
            x == count ? cout << x : cout << x << " ";
        }
    }
    cout << endl;
}





