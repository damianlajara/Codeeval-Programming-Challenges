//
//  main.cpp
//  oddNumbers
//
//  Created by Damian Lajara on 10/4/14.
//  Copyright (c) 2014 codeeval. All rights reserved.
//

#include <iostream>
using namespace std;

//Print the odd numbers from 1 to 99, one number per line.
int main() {
 
    for (int k; k<100; k++) {
        //its even
        if(!(k % 2 == 0)){
            cout << k << endl;
        }
    }
    
    return 0;
}
