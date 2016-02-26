//
//  main.cpp
//  Concurso2
//
//  Created by Angel Avila on 2/25/16.
//  Copyright © 2016 Angel Avila. All rights reserved.
//

#include <iostream>

using namespace std;

struct Height {
    double meters;
    int freq;
};

bool inArray(Height heights[], int N, double height) {
    
    for (int i = 0; i < N; i++)
        if (heights[i].meters == height)
            return true;
    
    return false;
}

void addFreq(Height heights[], int N, double height) {
    
    for (int i = 0; i < N; i++)
        if (heights[i].meters == height)
            heights[i].freq++;
    
}

void printModes(Height heights[], int N) {
    
    int first = heights[0].freq;
    int firstI = 0;
    
    for (int i = 1; i < N; i++)
        if (heights[i].freq > first) {
            first = heights[i].freq;
            firstI = i;
        }
    
    double second = -1;
    int doubleI = 0;
    
    for (int i = 0; i < N; i++) {
        if (heights[i].freq > second && i != firstI) {
            second = heights[i].freq;
            doubleI = i;
        }
    }
    
    cout << "First: " << heights[firstI].meters << " -> " << heights[firstI].freq << ". Second: "  << heights[doubleI].meters << " -> " << heights[doubleI].freq << "." << endl;
}

int main(int argc, const char * argv[]) {
    
    int cases = 1;
    
    cin >> cases;
    
    while (cases != 0) {
        Height heights[cases];
        int N = 0;
        
        for (int i = 0; i < cases; i++) {
            double heightTemp;
            cin >> heightTemp;
            
            if (!inArray(heights, N, heightTemp)) {
                heights[N].meters = heightTemp;
                heights[N].freq = 1;
                N++;
            }
            
            else
                addFreq(heights, N, heightTemp);
          
        }
        
        printModes(heights, N);
        
        
        cin >> cases;
    }
    
    return 0;
}