#include <iostream>
#include "problems.h"
using namespace std;

//n is exclusive here
int order_n_solution(int n) {
    int currentSum = 0; 
    for (int i=0; i<n; i+=3) {
        if (i % 5 != 0) currentSum += i;
    }
    for (int i=0; i<n; i+=5) {
        currentSum += i;
    }
    return currentSum;
}

int order_1_solution(int n) {
    n--; 
    int currentSum = 0; 
    if (n >= 3) {
        int largestDivBy3 = n - (n % 3);     
        currentSum = currentSum + ((n/3) * (largestDivBy3+3))*.5; 
    }
    if (n >= 5) {
        int largestDivBy5 = n - (n % 5);   
        currentSum = currentSum + ((n/5) * (largestDivBy5+5))*.5; 
    } 
    if (n >= 15) {
        int largestDivBy15 = n - (n % 15); 
        currentSum = currentSum - ((n/15) * (largestDivBy15+15))*.5;  
    }
    return currentSum; 
}

void solveProblem1(int n) {
    int answer = order_n_solution(n); 
    cout << "o(n) solution : " << endl; 
    cout << answer << endl; 
    answer = order_1_solution(n); 
    cout << "o(1) solution : " << endl; 
    cout << answer << endl;   
}


