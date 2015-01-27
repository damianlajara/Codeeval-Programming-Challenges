//
//  main.cpp
//  splitTheNumber
//
//  Created by Damian Lajara on 12/27/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 SPLIT THE NUMBER
 CHALLENGE DESCRIPTION:
 
 You are given a number N and a pattern. 
 The pattern consists of lowercase latin letters and one operation "+" or "-". 
 The challenge is to split the number and evaluate it according to this pattern e.g.
 
 1232 ab+cd -> a:1, b:2, c:3, d:2 -> 12+32 -> 44
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. 
 Each line of the file is a test case, 
 containing the number and the pattern separated by a single whitespace. E.g.
 
 3413289830 a-bcdefghij
 776 a+bc
 12345 a+bcde
 1232 ab+cd
 90602 a+bcde
 
 OUTPUT SAMPLE:
 
 For each test case print out the result of pattern evaluation. E.g.
 -413289827
 83
 2346
 44
 611
 Constraints:
 N is in range [100, 1000000000]
 */

//#include <iostream>
//#include <fstream>
//using namespace std;
//
//struct Operator {
//    size_t position;
//    char _operator;
//};
//
//Operator searchForOperator(string pattern) {
//    Operator op;
//    op.position = pattern.find('-');
//    op._operator = '-';
//    if(op.position == string::npos) {
//        cout << "Couldnt find -" << endl;
//        op.position = pattern.find('+');
//        op._operator = '+';
//        if(op.position == string::npos) {
//            cout << "Couldnt find either!" << endl;
//            //Default value for error checking
//            op._operator = '~';
//            op.position = -1;
//        }
//        else cout << "found + at position " << op.position << endl;
//    } else cout << "found - at position " << op.position << endl;
//    
//    return op;
//}
//
//long calculate(long lhs, long rhs, char operatorType) {
//    if(operatorType == '-') { //if it's '-', perform subtraction
//        return lhs - rhs;
//    } else { //it's '+', so perform addition
//        return lhs + rhs;
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    ifstream file("input.txt");
//    Operator op;
//    string num;
//    string string_lhs;
//    string string_rhs;
//    long num_lhs;
//    long num_rhs;
//    string pattern;
//    if(file.is_open()) {
//        while(file >> num >> pattern) {
//            op = searchForOperator(pattern);
//            if(op.position != -1 && op._operator != '~') {
//                //we succesfully found an operator and it's position
//                string_lhs = pattern.substr(0,op.position);
//                string_rhs = pattern.substr(op.position+1, pattern.length());
//                num_lhs = stol(num.substr(0, string_lhs.size()));
//                num_rhs = stol(num.substr(string_lhs.size(), num.size()));
//                cout << calculate(num_lhs, num_rhs, op._operator) << endl;
//            }
//        }
//    }
//    file.close();
//    return 0;
//}

#include <iostream>
#include <fstream>
using namespace std;

struct Operator {
    size_t position;
    char _operator;
};

//Operator searchForOperator(string pattern) {
//    Operator op;
//    if((op.position = pattern.find('-')) == string::npos) {
//        //cout << "[DEBUG] Couldnt find -" << endl;
//        if((op.position = pattern.find('+')) == string::npos) {
//            //cout << "[DEBUG] Couldnt find a valid operator!" << endl;
//            //Default values for error checking
//            op._operator = '~';
//            op.position = -1;
//        } else {
//            op._operator = '+';
//            //cout << "[DEBUG] found + at position " << op.position << endl;
//        }
//    } else {
//        op._operator = '-';
//        //cout << "[DEBUG] found - at position " << op.position << endl;
//    }
//    
//    return op;
//}

Operator searchForOperator(string pattern) {
    Operator op;
    if((op.position = pattern.find('-')) == string::npos) {
        if((op.position = pattern.find('+')) == string::npos) {
            //Default values for error checking
            op._operator = '~';
            op.position = -1;
        } else op._operator = '+';
    } else op._operator = '-';
    
    return op;
}

long calculate(long lhs, long rhs, char operatorType) {
    if(operatorType == '-') { //if it's '-', perform subtraction
        return lhs - rhs;
    } else { //it's '+', so perform addition
        return lhs + rhs;
    }
}

int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    Operator op;
    string num;
    string string_lhs;
    string string_rhs;
    long num_lhs;
    long num_rhs;
    string pattern;
    if(file.is_open()) {
        while(file >> num >> pattern) {
            op = searchForOperator(pattern);
            if(op.position != -1 && op._operator != '~') {
                //we succesfully found an operator and it's position
                string_lhs = pattern.substr(0,op.position);
                string_rhs = pattern.substr(op.position+1, pattern.length());
                num_lhs = stol(num.substr(0, string_lhs.size()));
                num_rhs = stol(num.substr(string_lhs.size(), num.size()));
                cout << calculate(num_lhs, num_rhs, op._operator) << endl;
            }
        }
    }
    file.close();
    return 0;
}