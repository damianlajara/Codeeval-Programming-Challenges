//
//  main.cpp
//  wordToDigit
//
//  Created by Damian Lajara on 1/31/15.
//  Copyright (c) 2015 Damian Lajara. All rights reserved.
//

/*
 WORD TO DIGIT
 CHALLENGE DESCRIPTION:
 
 
 Having a string representation of a set of numbers you need to print this numbers.
 
 All numbers are separated by semicolon. 
 There are up to 20 numbers in one line. 
 The numbers are "zero" to "nine"
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. 
 Each line in this file is one test case. E.g.
 
 zero;two;five;seven;eight;four
 three;seven;eight;nine;two
 
 OUTPUT SAMPLE:
 
 Print numbers in the following way:
 
 025784
 37892

 */
#include <iostream>
#include <fstream> //for opening file
#include <sstream> //to create a stream
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector <int> arrays;
    //declare a stream
    stringstream ss;
    //declare and open file
    ifstream file("input.txt");
    string line,input;
    if(file.is_open()) {
        //Read from file and save line by line
        while(getline(file, line)) {
            //save the line into a stream
            ss << line;
            //Read from stream word by word
            while(getline(ss, input, ';')) {
                if(input == "zero") {
                    arrays.push_back(0);
                } else if(input == "one") {
                    arrays.push_back(1);
                } else if(input == "two") {
                    arrays.push_back(2);
                } else if(input == "three") {
                    arrays.push_back(3);
                } else if(input == "four") {
                    arrays.push_back(4);
                } else if(input == "five") {
                    arrays.push_back(5);
                } else if(input == "six") {
                    arrays.push_back(6);
                } else if(input == "seven") {
                    arrays.push_back(7);
                } else if(input == "eight") {
                    arrays.push_back(8);
                } else if(input == "nine") {
                    arrays.push_back(9);
                }
            }
            //Display the converted word
            for(auto i : arrays) {
                cout << i;
            }
            
            /**
             * The normal for loop, instead of the new one in C++11 only
             *
             * for(int i = 0; i < arrays.size(); i++) {
             *    cout << i;
             * }
             *
             */
            
            //Clear the stream for the next line from the file
            cout << endl;
            ss << "";
            ss.clear();
            arrays.clear();
        }
    } file.close();
    
    return 0;
}