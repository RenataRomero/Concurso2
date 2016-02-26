//
//  Minusculas.cpp
//  Concurso2
//
//  Created by Angel Avila on 2/25/16.
//  Copyright © 2016 Angel Avila. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    
    int cases;
    cin >> cases;
    
    while (cases--) {
        int wordCases;
        cin >> wordCases;
        int outputs = wordCases - 1;
        cin.ignore();
        
        vector<string> words;
        vector<string> answers;
        answers.reserve(answers.capacity() + wordCases);
        for (int i = 0; i < wordCases; i++) {
            string temp;
            getline(cin, temp);
            words.push_back(temp);
        }
        
        int j = 0;
        for (int i = 0; i < wordCases; i+=2) {
            char arrTemp[words[i].length() + words[i + 1].length()];
            
            string temp = words[i];
            temp.append(words[i + 1]);
            
            strncpy(arrTemp, temp.c_str(), sizeof(temp));
            
            sort(arrTemp, arrTemp+sizeof(arrTemp));
            
            answers.push_back(arrTemp);
            j++;
        }
        
        for(int i = 0; i < j; i++)
            cout << answers[i] << endl;
        
        int cycles = j / 2;
        
        while (j < outputs) {
            
            for (int i = j; i < cycles + j; i += 2) {
                char arrTemp[answers[i - 1].length() + answers[i - 2].length()];
                
                string temp = answers[i - 1];
                temp.append(answers[i - 2]);
                
                strncpy(arrTemp, temp.c_str(), sizeof(temp));
                arrTemp[sizeof(arrTemp)] = '\0';
                sort(arrTemp, arrTemp+sizeof(arrTemp));
                
                /*cout << "Temp: " << endl;*/
                
                
                
                for (int h = 0; h < sizeof(arrTemp); h++) {
                    if (arrTemp[h] >= 'a' && arrTemp[h] <= 'z')
                        cout << arrTemp[h];
                }
                
                cout << endl;
                
                answers.push_back(arrTemp);
                j++;
            }
            
            cycles /= 2;
        }
        
    }
    
    return 0;
}