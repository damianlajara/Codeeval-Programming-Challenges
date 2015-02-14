//
//  main.cpp
//  hiddenDigits
//
//  Created by Damian Lajara on 2/14/15.
//  Copyright (c) 2015 codeeval. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;
map<char, int> mymap = { {'a',0},{'b',1},{'c',2},{'d',3},{'e',4},{'f',5},{'g',6},{'h',7},{'i',8},{'j',9} };

int main(int argc, const char * argv[]) {
    
    ifstream file("input.txt");
    int nonValidChar = 0;
    string line, input;

    if(file.is_open()) {
        while(getline(file, line)) {
            //Skip empty lines
            if(line.empty()) continue;
            //Loop over the line
            for(auto i = 0; i < line.length(); i++) {
                //if it's a character and it's lowercase
                if((isalpha(line[i])) && (line[i] == tolower(line[i]))) {
                    auto it = mymap.find(line[i]);
                    //if it's in the map
                    if(it != mymap.end()) {
                        cout << it->second;
                    } else nonValidChar++; //if it's a character, but NOT in the map (Need this for the else to work properly)
                } else if(isdigit(line[i])) { //if it's a number
                    cout << line[i];
                } else {
                    //Enters here if it is not a character nor a number
                    //Does not increment 'nonValidChar' it if it's a lowercase character because of the first if statement
                    //that's why the else inside the first if statement accounts for those characters and increases the count from there
                    nonValidChar++;
                }
             }
            //Check if none of the characters in the line were printed, if none were, then there were no numbers found
            if(nonValidChar == line.length()) cout << "NONE";
            //reset the counter for the next line in the loop
            nonValidChar = 0;
            //Seperate the answers for each line
            cout << endl;
        }
    }
    return 0;
}
