//
//  main.cpp
//  sumOfIntegersFromFile
//
//  Created by Damian Lajara on 10/4/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    
    // get the info from file
    int line = 0; //will hold the contents of the file
    int sum = 0;
    ifstream file;
    file.open(argv[1]);
    //read file
    if(file.is_open()) {
        while(file>>line) {
            sum += line;
            line++;
        }
        cout << sum << endl;
        file.close();
    }
    
}
