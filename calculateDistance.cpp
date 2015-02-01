//
//  main.cpp
//  calculateDistances;
//
//  Created by Damian Lajara on 1/31/15.
//  Copyright (c) 2015 Damian Lajara. All rights reserved.
//

//Distance formula = ((x2-x1)^2 + (y2-y1)^2)^(1/2)

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream file("input.txt");
    stringstream ssleftSide,ssrightSide,ssleftDigits,ssrightDigits;
    string line,linput,rinput,ldigit,rdigit;
    vector<int>leftVec,rightVec;
    
    if(file.is_open()) {
        //while there are still lines in the file -- ex: (25, 4) (1, -6)
        while(getline(file, line)) {
            string lhs, rhs;
            //find the position of the last ')'
            char delim = line.find_first_of(')');
            
            //extract everything up to and including the last ')' -- ex: (25, 4)
            lhs = line.substr(0, delim+1);
            
            //extract starting from the last ')' +1 to trim space, up till the end of the string -- ex: (1, -6)
            rhs = line.substr(lhs.length()+1, line.length());
            
            //trim the parathensis from the strings
            lhs = lhs.substr(1, lhs.length()-2);
            rhs = rhs.substr(1, rhs.length()-2);
            
            //Store the trimmed strings into it's respective stream -- ex: "25, 4" in ssl and "1, -6" in ssr
            ssleftSide << lhs;
            ssrightSide << rhs;
            
            //while there is content in the two trimmed strings, loop over them
            while(getline(ssleftSide, linput) && getline(ssrightSide, rinput)) {
                
                //save these into a stream so we can seperate them from the comma delimiter
                ssleftDigits << linput;
                ssrightDigits << rinput;
                
                //seperate the strings and save the numbers into the vectors
               while(getline(ssleftDigits, ldigit, ',') && getline(ssrightDigits, rdigit, ',')) {
                   leftVec.push_back(stoi(ldigit));
                   rightVec.push_back(stoi(rdigit));
                }
                
                //x1:leftVec[0]
                //x2:rightVec[0]
                //y1:leftVec[1]
                //y2:rightVec[1]
                
                //Display the answer
                cout << sqrt(pow(rightVec[0]-leftVec[0],2) + pow(rightVec[1]-leftVec[1],2)) << endl;
                
                //Clear the string streams and vectors for the next trimmed strings
                ssleftDigits << "";
                ssrightDigits << "";
                ssleftDigits.clear();
                ssrightDigits.clear();
                leftVec.clear();
                rightVec.clear();
            }
            //clear the remaining stringstreams for the next line
            ssleftSide << "";
            ssrightSide << "";
            ssleftSide.clear();
            ssrightSide.clear();
        }
    } file.close();
    return 0;
}
