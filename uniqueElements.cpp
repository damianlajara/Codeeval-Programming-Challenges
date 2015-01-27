//
//  main.cpp
//  uniqueElements
//
//  Created by Damian Lajara on 10/26/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 You are given a sorted list of numbers with duplicates. 
 Print out the sorted list with duplicates removed.
 
 INPUT SAMPLE:
 File containing a list of sorted integers, comma delimited, one per line. E.g.

 1,1,1,2,2,3,3,4,4
 2,3,4,5,5
 
 OUTPUT SAMPLE:
 Print out the sorted list with duplicates removed, one per line. E.g.
 
 1,2,3,4
 2,3,4,5

 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> //unique
using namespace std;

void deleteDuplicates(vector<int>& numbers) {
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
}

void printVector(vector<int>& numbers) {
    //put commas before the number, only if NOT the first number
    //creates effect of comma seperated values
    for(auto i = 0; i < numbers.size(); i++) {
        if(i > 0) {
            cout << "," << numbers[i];
        } else {
           cout << numbers[i];
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> numbers;
    ifstream file;
    string line;
    string csvLine; //comma seperated value line
    int num = 0;
    file.open(argv[1]);
    if(file.is_open()) {
        while(getline(file, line)) { //get the whole line and use string stream to break at commas
            //using stringstream to seperate at commas
            istringstream ss(line);
            /**
             * Another way of converting to a num and extracting csv at the same time
             * for (; ss >> num; ss.ignore(std::numeric_limits<std::streamsize>::max(), ',')) {
             *    // do something with the number
             * }
             */
            while(getline(ss, csvLine, ',')) {
                //convert to int
                
                //ss >> num; //WRONG! Do not mix getline and >>
                num = stoi(csvLine);//do this instead
                
                //add numbers to vector
                numbers.push_back(num);
            }
            deleteDuplicates(numbers);
            printVector(numbers);
            numbers.clear();
            cout << endl;
        }
    }
    return 0;
}

