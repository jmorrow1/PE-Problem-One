#include <iostream>
#include "problems.h"
using namespace std;

void itSolution() {
    
}

bool eq(int a, int b) {
    return (a == b || a == 6 && b == 9 || a == 9 && b == 6); 
}

void solveProblemNinety() {
    int digitPairs [][2] = {{0, 1}, {0, 4}, {0, 9}, {1, 6}, {2, 5}, {3, 6}, {4, 9}, {6, 4}, {8, 1}}; 
    //iterate through all the possible cubes
    /*
     * the iteration sequence will look something like this: 
     * 1 2 3 4 5 6
     * 1 2 3 4 5 7 
     * 1 2 3 4 5 8 
     * 1 2 3 4 5 9
     * 1 2 3 4 6 7
     * 1 2 3 4 6 8
     * ...
     */
    int count=0; 
    for (int i = 0; i <= 4; i++) {
        for (int j = i+1; j <= 5; j++) {
            for (int k = j+1; k <= 6; k++) {
                for (int l = k+1; l <= 7 ; l++) {
                    for (int m = l+1; m <= 8; m++) {
                        for (int n = m+1; n <= 9; n++) {
                            //iterate through all the possible cubes again to get a 2nd cube
                            for (int a = 0; a <= 4; a++) {
                                for (int b = a+1; b <= 5; b++) {
                                    for (int c = b+1; c <= 6; c++) {
                                        for (int d = c+1; d <= 7; d++) {
                                            for (int e = d+1; e <= 8; e++) {
                                                for (int f = e+1; f <= 9; f++) {
                                                    bool valid=false; 
                                                    //check if the combination of the 1st cube 
                                                    //and the 2nd cube is a valid arrangement
                                                    for (int x = 0; x<9; x++) {
                                                        if (eq(i, digitPairs[x][0]) || eq(j, digitPairs[x][0]) ||
                                                                eq(k, digitPairs[x][0]) || eq(l, digitPairs[x][0]) ||
                                                                eq(m, digitPairs[x][0]) || eq(n, digitPairs[x][0]) ) 
                                                        {
                                                            if (eq(a, digitPairs[x][1]) || eq(b, digitPairs[x][1]) ||
                                                                    eq(c, digitPairs[x][1]) || eq(d, digitPairs[x][1]) ||
                                                                    eq(e, digitPairs[x][1]) || eq(f, digitPairs[x][1])) 
                                                            {
                                                                if (x == 8) valid = true; 
                                                                continue; 
                                                            }
                                                        }
                                                        
                                                        if (eq(i, digitPairs[x][1]) || eq(j, digitPairs[x][1]) ||
                                                                eq(k, digitPairs[x][1]) || eq(l, digitPairs[x][1]) ||
                                                                eq(m, digitPairs[x][1]) || eq(n, digitPairs[x][1])) 
                                                        {
                                                            if (eq(a, digitPairs[x][0]) || eq(b, digitPairs[x][0]) ||
                                                                    eq(c, digitPairs[x][0]) || eq(d, digitPairs[x][0]) ||
                                                                    eq(e, digitPairs[x][0]) || eq(f, digitPairs[x][0])) 
                                                            {
                                                                if (x == 8) valid = true; 
                                                                continue; 
                                                            }
                                                            
                                                        }
                                                        break; 
                                                    }
                                                    if (valid) {
                                                        count++; 
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }                       
                    }
                }
            }
        }
    }
    count /= 2; //eliminate repeats
    cout << "count = " << count << endl; 
}