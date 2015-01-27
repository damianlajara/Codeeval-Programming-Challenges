//
//  main.cpp
//  ageDistribution
//
//  Created by Damian Lajara on 10/4/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

/*
 You're responsible for providing a demographic report for your local school district based on age. To do this, you're going determine which 'category' each person fits into based on their age.
 The person's age will determine which category they should be in:
 
 If they're from 0 to 2 the child should be with parents print : 'Still in Mama's arms'
 If they're 3 or 4 and should be in preschool print : 'Preschool Maniac'
 If they're from 5 to 11 and should be in elementary school print : 'Elementary school'
 From 12 to 14: 'Middle school'
 From 15 to 18: 'High school'
 From 19 to 22: 'College'
 From 23 to 65: 'Working for the man'
 From 66 to 100: 'The Golden Years'
 If the age of the person less than 0 or more than 100 - it might be an alien - print: "This program is for humans
 */

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
        while(file>>line) {
            if((line >= 0) && (line <= 2)) {
                cout << "Still in Mama's arms" << endl;
            }
            else if( (line == 3) || (line == 4) ) {
                cout << "Preschool Maniac" << endl;
            }
            else if((line >= 5) && (line <= 11)) {
                cout << "Elementary school" << endl;
            }
            else if((line >= 12) && (line <= 14)){
                cout << "Middle school" << endl;
            }
            else if((line >= 15) && (line <= 18)){
                cout << "High school" << endl;
            }
            else if((line >= 19) && (line <= 22)){
                cout << "College" << endl;
            }
            else if((line >= 23) && (line <= 65)) {
                cout << "Working for the man" << endl;
            }
            else if((line >= 66) && (line <= 100)) {
                cout << "The Golden Years" << endl;
            }
            else {
                //if its 0 or greater than 100
                cout << "This program is for humans" << endl;
            }
            line++;
        }
        file.close();
    }
    

    return 0;
}
