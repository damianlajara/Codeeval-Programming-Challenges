//
//  main.cpp
//  fileSize
//
//  Created by Damian Lajara on 12/28/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

#include <iostream>
#include <fstream>
using std::ios;
using std::ifstream;
using std::cout;

int main(int argc, const char * argv[]) {
    // binary opens file in binary mode
    // ate opens file with cursor at the end of the file already,
    // so theres no need to seek all the way to the end of the file
    // just to figure out the size
    // tellg returns the position of the current character in the input stream
    // and since i used ios::ate, it automatically returned the position at the
    // end of the file, creating the effect of the file size
    // file.seekg(0, file.beg) to go all the way back up to the beggining of the
    // file if you wanted to read it or save it or perform any kinda action on it
    
    ifstream file("input.txt", ios::binary | ios::ate);
    if(file.is_open()) {
        cout << file.tellg();
    } file.close();
    
    return 0;
}
