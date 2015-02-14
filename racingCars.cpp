//
//  main.cpp
//  racingCars
//
//  Created by Damian Lajara on 2/12/15.
//  Copyright (c) 2015 codeeval. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void calculateMovement(string& line, size_t& found, size_t& position) {
    //move left
    if (found < position) {
        line.at(found) = '/';
        position = found;
    }
    //move straight
    else if (found == position) {
        line.at(found) = '|';
        position = found;
    }
    //move right
    else {
        line.at(found) = '\\';
        position = found;
    }
}

int main(int argc, const char* argv[]) {
    ifstream file(argv[1]);
    stringstream ss;
    string line, input;
    string checkpoint = "C";
    string gate = "_";
    string obstacle = "#";
    size_t position = 0;
    
    if (file.is_open()) {
        getline(file, line);
        size_t found = line.find_first_not_of(obstacle);
        if (found != string::npos) {
            position = found;
            line.at(position) = '|';
            cout << line << endl;
            
        }
        while (getline(file, line)) {
            size_t foundC = line.find_first_of(checkpoint);
            size_t foundG = line.find_first_of(gate);
            if (foundC != string::npos) {
                calculateMovement(line, foundC, position);
            }
            else if (foundG != string::npos) {
                calculateMovement(line, foundG, position);
            }
            cout << line << endl;
        }
    }
    return 0;
}
