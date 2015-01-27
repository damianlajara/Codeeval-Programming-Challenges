//
//  main.cpp
//  multiplicationTables
//
//  Created by Damian Lajara on 10/24/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

//int main(int argc, const char * argv[]) {
//    int integer = 0;
//    int counter = 1;
//    cout << setw(2); //for first row
//    for(int column = 1; column <= 12; column++) { //every row has 12 columns
//        for(int row = 1; row <= 12; row++) { //loop over 12 rows
//            integer += column;
//            //cout << setw(4) << integer;// << setw(4);
//            //counter == 12 ? cout << integer : cout << integer << setw(4);//<< "\t"; //remove trailing spaces
//            if(counter == 12) {
//                cout << setw(4) << integer << setw(2);
//            } else {
//                cout << integer << setw(4);
//            }
//            counter++;
//        }
//        //reset the counters
//        integer = 0;
//        counter = 1;
//        cout << endl;
//    }
//    return 0;
//}

int main(int argc, const char * argv[]) {
    int integer = 0;
    int counter = 1;
    cout << setw(2); //for first row
    for(int column = 1; column <= 12; column++) { //every row has 12 columns
        for(int row = 1; row <= 12; row++) { //loop over 12 rows
            integer += column;
            //cout << setw(4) << integer;// << setw(4);
            //counter == 12 ? cout << integer : cout << integer << setw(4);//<< "\t"; //remove trailing spaces
            if(counter == 12) {
                cout << setw(4) << integer << setw(2);
            } else {
                cout << integer << setw(4);
            }
            counter++;
        }
        //reset the counters
        integer = 0;
        counter = 1;
        cout << endl;
    }
    return 0;
}