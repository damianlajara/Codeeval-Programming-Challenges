//
//  main.cpp
//  evenNumberFromFile
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
    ifstream file;
    file.open(argv[1]);
    //read file
    if(file.is_open()) {
        while(file>>line) { //while there is still content in the file
            
            if(line % 2 == 0) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
            line++;
        }
        file.close();
    }
    
    
    
    
    
    
    
    return 0;
}
