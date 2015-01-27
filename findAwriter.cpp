//
//  main.cpp
//  findAwriter
//
//  Created by Damian Lajara on 12/29/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 FIND A WRITER
 CHALLENGE DESCRIPTION:
 
 
 You have a set of rows with names of famous writers encoded inside. 
 Each row is divided into 2 parts by pipe char (|). 
 The first part has a writer's name. 
 The second part is a "key" to generate a name.
 
 Your goal is to go through each number in the key (numbers are separated by space)
 from left-to-right.
 Each number represents a position in the 1st part of a row. 
 This way you collect a writer's name which you have to output
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. Input example is the following
 
 osSE5Gu0Vi8WRq93UvkYZCjaOKeNJfTyH6tzDQbxFm4M1ndXIPh27wBA rLclpg| 3 35 27 62 51 27 46 57 26 10 46 63 57 45 15 43 53
 
 3Kucdq9bfCEgZGF2nwx8UpzQJyHiOm0hoaYP6ST1WM7Nks5XjrR4IltBeDLV vA| 2 26 33 55 34 50 33 61 44 28 46 32 28 30 3 50 34 61 40 7 1 31
 This input had 2 rows.
 
 OUTPUT SAMPLE:
 
 Print results in the following way.
 
 Stephen King 1947
 Kyotaro Nishimura 1930
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    vector<int> keys;
    stringstream ss;
    size_t delim;
    string name;
    string key;
    string numFromKey;
    string line;
    if(file.is_open()) {
        while(getline(file, line)) {
            if(line.empty()) continue; //skip empty lines
            delim = line.find('|');
            name = line.substr(0, delim);
            key = line.substr(delim+2, line.size()); //+2 to account for actual delimeter and the space following it
            ss << key; // copy the entire key string into the stream
            while(getline(ss, numFromKey, ' ')) {
                keys.push_back(stoi(numFromKey)-1); //lower every number down by 1, since string starts at 0
            }
            string decipheredName = "";
            for(int i = 0; i < keys.size(); i++) {
                decipheredName += name[keys[i]]; //keep adding every char into the string
            }
            cout << "Deciphered Name: " << decipheredName << endl;
            
            //Reset values for next line of input
            ss << "";
            numFromKey = "";
            keys.clear();
            ss.clear();
        }
    } file.close();
    return 0;
}
