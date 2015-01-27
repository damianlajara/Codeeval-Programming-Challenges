//
//  main.cpp
//  happyNumbers
//
//  Created by Damian Lajara on 1/6/15.
//  Copyright (c) 2015 codeeval. All rights reserved.
//

/*
 HAPPY NUMBERS
 CHALLENGE DESCRIPTION:
 
 
 A happy number is defined by the following process. Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers, while those that do not end in 1 are unhappy numbers.
 
 INPUT SAMPLE:
 
 The first argument is the pathname to a file which contains test data, one test case per line. Each line contains a positive integer. E.g.
 
 1
 7
 22
 
 OUTPUT SAMPLE:
 
 If the number is a happy number, print out 1. If not, print out 0. E.g
 
 1
 1
 0
 For the curious, here's why 7 is a happy number: 7->49->97->130->10->1. Here's why 22 is NOT a happy number: 22->8->64->52->29->85->89->145->42->20->4->16->37->58->89 ...
 

 */

#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <vector>
using namespace std;
const vector<int> pattern {4, 16, 37, 58, 89, 145, 42, 20};

//bool isPresent(vector<int> vec, int i) {
//    const vector<int>::iterator it;
//        it = find(pattern.begin(), pattern.end(), i);
//        if(it != vec.end()) {
//            cout << "Found " << i << " at position: " << *it << endl;
//        } else {
//            return false;
//        }
//    return true;
//}
bool isPresent(int i) {
        if(find(pattern.begin(), pattern.end(), i) != pattern.end()) {
            cout << "Found " << i << endl;
        } else {
            return false;
        }
    return true;
}

bool inPreviousPattern(vector<int>& vec, int sum) {
    for(int i = 0; i < pattern.size(); i++) {
        if(vec[i] == pattern[i]) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    ifstream file("input.txt");
    vector<int> prevPattern;
    string line;
    int num;
    int sum = 0;
    if(file.is_open()) {
        while(getline(file, line)) {
            num = 0;
            if(line.empty()) continue;
            cout << "~~~~~~~~~~~~NEW INPUT!!!!!!!!!!!!!!!!!~~~~~~~~~~" << endl;
            while( num != 1) {
                for(int i = 0; i < line.length(); i++) {
                    //cout << "Num: " << line << " Sum: " << sum << endl;
                    sum += pow(static_cast<int>(line[i])-48, 2);
                    cout << "Num: " << line << " Sum: " << sum << endl;
                    prevPattern.push_back(sum);
                    cout << "Pushed " << sum << " into prevPattern vector" << endl;
                }
                //TODOOOOOOOO!!!!!
                //if(prevPattern > 0 && all of the elements in pattern are present in prevPattern) then exit the loop, cout 0 and read the next line
//                int count = 0;
//                for_each(prevPattern.begin(), prevPattern.end(), [&](int num) {
//                    if(isPresent(prevPattern, num)) {//if(count == pattern.size()) {
//                        cout << "ALL ELEMENTS ARE IN THE VECTOR! STOP THE LOOOP!!!!!!!!!!!!" << endl;
//                        return;
//                    }
//                    if (find(pattern.begin(), pattern.end(), num) != pattern.end()) {
//                        cout << "Found Num: " << num << endl;
//                        count++;
//                    } else {
//                        
//                    }
//                });
                bool test = true;
                if(any_of(pattern.begin(), pattern.end(), [sum](int i){return sum == i;})) {
                    // if sum is equal to any of the repetitive ints, then check
                    for(int i = 0; i < prevPattern.size(); i++) {
                        cout << "Checking to see if " << sum << " Is in the repetitive vector" << endl;
                        if(isPresent(sum)) {//prevPattern[i]
                            cout << "Found " << sum << endl;//prevPattern[i]
                            continue;
                        } else {
                            cout << "Didn't find " << sum << " in loop...." << endl;//prevPattern[i]
                            test = false;
                            break;
                        }
                    }
                    if(test) cout << "ALL ELEMENTS ARE IN THE VECTOR! STOP THE LOOOP!!!!!!!!!!!!" << endl;
                }
                
                cout << "Num: " << line << " Sum: " << sum << endl;
                num = sum;
                line = to_string(sum);
                sum = 0;
                prevPattern.clear();
            }
            //num = stoi(line);
        }
    } file.close();
    return 0;
}

//#include <iostream>
//#include <fstream>
//#include <math.h>
//#include <sstream>
//#include <vector>
//using namespace std;
//const vector<int> pattern {4, 16, 37, 58, 89, 145, 42, 20};
//
//bool test(vector<int> vec, int i) {
//    return pattern[i] == vec[i];
//}
//bool inPreviousPattern(vector<int>& vec, int sum) {
//    for(int i = 0; i < pattern.size(); i++) {
//        if(vec[i] == pattern[i]) {
//            continue;
//        } else {
//            return false;
//        }
//    }
//    return true;
//}
//int main(int argc, const char * argv[]) {
//    ifstream file("input.txt");
//    vector<int> prevPattern;
//    string line;
//    int num;
//    int sum = 0;
//    bool continueLoop = true;
//    if(file.is_open()) {
//        while(getline(file, line)) {
//            num = 0;
//            if(line.empty()) continue;
//            while( num != 1 && continueLoop) {
//                for(int i = 0; i < line.length(); i++) {
//                    cout << "Num: " << line << " Sum: " << sum << endl;
//                    sum += pow(static_cast<int>(line[i])-48, 2);
//                    prevPattern.push_back(sum);
//                }
//                //TODOOOOOOOO!!!!!
//                //if(prevPattern > 0 && all of the elements in pattern are present in prevPattern) then exit the loop, cout 0 and read the next line
//                for_each(prevPattern.begin(), prevPattern.end(), [](int num) {
//                    if (find(pattern.begin(), pattern.end(), num) != pattern.end()) {
//                        cout << "Found Num: " << num << endl;
//                    }
//                });
//                if(prevPattern.size() == 8) {
//                    //check pattern
////                    if(inPreviousPattern(prevPattern, sum)) {
////                        cout << "Pattern is repeating!" << endl;
////                        continueLoop = false;
////                        break;
////                    }
//                    if(all_of(prevPattern.begin(), prevPattern.end(), [](int i){return test;})) {
//                        cout << "MATCH FOUND!" << endl;
//                    }
//                }
//                //continueLoop = true;
//                cout << "Num: " << line << " Sum: " << sum << endl;
//                num = sum;
//                line = to_string(sum);
//                sum = 0;
//                prevPattern.clear();
//            }
//            //num = stoi(line);
//        }
//    } file.close();
//    return 0;
//}





//#include <fstream>
//#include <iostream>
//#include <sstream>
//#include <stdlib.h>
//#include <map>
//
//using namespace std;
//
//bool isHappyNumber(int number, map<int, bool> &previousNumbers) {
//    if (number == 1) {
//        return true;
//    }
//    if (previousNumbers.count(number) > 0) {
//        return false;
//    }
//    previousNumbers[number] = true;
//    int newNumber = 0;
//    while (number > 0) {
//        newNumber += (number % 10)*(number % 10);
//        number = number / 10;
//    }
//    return isHappyNumber(newNumber, previousNumbers);
//}
//
//int main(int argc, char** argv) {
//    ifstream file;
//    file.open("input.txt");
//    while (!file.eof())
//    {
//        string line;
//        getline(file, line);
//        if (line.length() == 0) {
//            break;
//        }
//        int number = atoi(line.c_str());
//        map<int, bool> previousNumbers;
//        cout << (int)isHappyNumber(number, previousNumbers) << endl;
//    }
//    return 0;
//}