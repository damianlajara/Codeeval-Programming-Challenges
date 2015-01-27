//
//  main.cpp
//  queryBoard
//
//  Created by Damian Lajara on 1/1/15.
//  Copyright (c) 2015 codeeval. All rights reserved.
//  NOTES: http://stackoverflow.com/questions/1730961/convert-a-2d-array-index-into-a-1d-index

/*
 QUERY BOARD
 CHALLENGE DESCRIPTION:
 
 
 There is a board (matrix). Every cell of the board contains one integer, which is 0 initially.
 
 The next operations can be applied to the Query Board:
 SetRow i x: it means that all values in the cells on row "i" have been changed to value "x" after this operation.
 SetCol j x: it means that all values in the cells on column "j" have been changed to value "x" after this operation.
 QueryRow i: it means that you should output the sum of values on row "i".
 QueryCol j: it means that you should output the sum of values on column "j".
 
 The board's dimensions are 256x256
 "i" and "j" are integers from 0 to 255
 "x" is an integer from 0 to 31
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. Each line in this file contains an operation of a query. E.g.
 
 SetCol 32 20
 SetRow 15 7
 SetRow 16 31
 QueryCol 32
 SetCol 2 14
 QueryRow 10
 SetCol 14 0
 QueryRow 15
 SetRow 10 1
 QueryCol 2
 OUTPUT SAMPLE:
 
 For each query, output the answer of the query. E.g.
 
 5118
 34
 1792
 3571
 */

//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <time.h>
//using namespace std;
////256x256 = width(256), height(256)
//const int width = 256;
//const int height = 256;
//
//void setCol(vector<int>& grid, int colNum, int initializer) {
//    for(int i = 0; i < height; i++) {// ++i
//        grid[i * width + (colNum-1)] = initializer;
//    }
//}
//
//void setRow(vector<int>& grid, int rowNum, int initializer) {
//    for(int i = 0; i < width; i++) {// ++i
//        grid[(rowNum-1) * width + i] = initializer;
//    }
//}
//
//int queryCol(vector<int>& grid, int colNum) {
//    /*sum of values on column "j".*/
//    int sum = 0;
//    for(int i = 0; i < height; i++) {// ++i
//        sum+= grid[i * width + (colNum-1)];
//    } return sum;
//}
//
//int queryRow(vector<int>& grid, int rowNum) {
//    /*sum of values on row "i".*/
//    int sum = 0;
//    for(int i = 0; i < width; i++) {// ++i
//        sum += grid[(rowNum-1) * width + i];
//    } return sum;
//}
//
//void displayGrid(vector<int>& grid) { //5x3 grid
//    /* Because we converted the 2D vector to 1D, we have to keep track of every
//     * element with 'counter' since the vector is now linear
//     * (one long line, connected by the end of each row)
//     * so row 1 is indexes (0, 1 , 2), row 2 is indexes (3, 4, 5), etc
//     * all the way up till length (rows(width) * columns(height))
//     */
//    for(int i = 0, counter = 0; i < height; i++) { //column
//        for(int j = 0; j < width; j++, counter++) { //row
//            cout << grid[counter] << " ";
//        } cout << endl;
//    } cout << endl;
//}
//
//int main(int argc, const char * argv[]) {
//    ifstream file("input.txt");
//    vector<int> grid(width*height, 0); //initialize a W*H grid with 0's
//    vector<int> fileContents;
//    stringstream ss;
//    string line;
//    string num;
//    string operation;
//    if(file.is_open()) {
//        int lineCounter = 1;
//        int k = 0;
//        while(getline(file, line)) {
//            k++;
//            //if(lineCounter == 20) exit(0);
//            ss << line; //read line into stream
//            ss >> operation; //Get operation from stream
//            while(ss >> num) { //get the rest of the input from stream
//                fileContents.push_back(stoi(num));
//            } cout << k << ") LINE NUM: " << lineCounter << "--> ";
//            if(operation == "SetCol") {
//                setCol(grid, fileContents[0], fileContents[1]);
//            } else if(operation == "SetRow") {
//                setRow(grid, fileContents[0], fileContents[1]);
//            } else if(operation == "QueryCol") {
//                cout << "[DEBUG] In query Column! Sum = ";
//                cout << queryCol(grid, fileContents[0]) << endl;
//                lineCounter++;
//            } else if(operation == "QueryRow") {
//                cout << "[DEBUG] In query Row! Sum = ";
//                cout << queryRow(grid, fileContents[0]) << endl;
//                lineCounter++;
//            }
//            //Reset values for next line
//            cout << endl; //for k
//            ss << "";
//            ss.clear();
//            fileContents.clear();
//        }
//    } file.close();
//    
//    /* Example on using the functions: */
//    //setRow(grid, 2, 1); // set row 2 to 1's
//    //setCol(grid, 3, 1); // set col 3 to 1's
//    //displayGrid(grid);  // displays grid in a 2d format
//    
//    return 0;
//}



#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
using namespace std;
//256x256 = width(256), height(256)
const int width = 256;
const int height = 256;

void setCol(vector<int>& grid, int colNum, int initializer) {
    for(int i = 0; i < height; i++) {// ++i
        grid[i * width + (colNum+1)] = initializer;
    }
}

void setRow(vector<int>& grid, int rowNum, int initializer) {
    for(int i = 0; i < width; i++) {// ++i
        grid[(rowNum+1) * width + i] = initializer;
    }
}

int queryCol(vector<int>& grid, int colNum) {
    /*sum of values on column "j".*/
    int sum = 0;
    for(int i = 0; i < height; i++) {// ++i
        sum+= grid[i * width + (colNum+1)];
    } return sum;
}

int queryRow(vector<int>& grid, int rowNum) {
    /*sum of values on row "i".*/
    int sum = 0;
    for(int i = 0; i < width; i++) {// ++i
        sum += grid[(rowNum+1) * width + i];
    } return sum;
}

void displayGrid(vector<int>& grid) { //5x3 grid
    /* Because we converted the 2D vector to 1D, we have to keep track of every
     * element with 'counter' since the vector is now linear
     * (one long line, connected by the end of each row)
     * so row 1 is indexes (0, 1 , 2), row 2 is indexes (3, 4, 5), etc
     * all the way up till length (rows(width) * columns(height))
     */
    for(int i = 0, counter = 0; i < height; i++) { //column
        for(int j = 0; j < width; j++, counter++) { //row
            cout << grid[counter] << " ";
        } cout << endl;
    } cout << endl;
}

int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    vector<int> grid(width*height, 0); //initialize a W*H grid with 0's
    vector<int> fileContents;
    stringstream ss;
    string line;
    string num;
    string operation;
    if(file.is_open()) {
        int lineCounter = 1;
        while(getline(file, line)) {
            ss << line; //read line into stream
            ss >> operation; //Get operation from stream
            while(ss >> num) { //get the rest of the input from stream
                fileContents.push_back(stoi(num));
            }
            if(operation == "SetCol") {
                setCol(grid, fileContents[0], fileContents[1]);
            } else if(operation == "SetRow") {
                setRow(grid, fileContents[0], fileContents[1]);
            } else if(operation == "QueryCol") {
                cout << lineCounter << ") " << queryCol(grid, fileContents[0]) << endl;
                lineCounter++;
            } else if(operation == "QueryRow") {
                cout << lineCounter << ") " << queryRow(grid, fileContents[0]) << endl;
                lineCounter++;
            }
            //Reset values for next line
            ss << "";
            ss.clear();
            fileContents.clear();
        }
    } file.close();
    
    /* Example on using the functions: */
    //setRow(grid, 0, 1); // set row 1 to 1's
    //setCol(grid, 2, 1); // set col 3 to 1's
    //displayGrid(grid);  // displays grid in a 2d format
    
    return 0;
}