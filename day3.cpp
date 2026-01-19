#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
    ifstream input; 
    input.open("day3_input.txt"); 

    if (!input){
        cerr << "unable to open input"; 
        exit(1); 
    }

    
    string line; 
    vector<int> joltages; 

    while (getline(input, line)) {
        // find biggest digit  
        char first = '1';  
        for (int i = 0; i < line.length()-1; i++){
            if (first < line[i]){
                first = line[i]; 
            }
        }

        // find second behind the first biggest digit
        int pos = line.find(first); 
        char second = '1'; 
        for (int i = pos+1; i < line.length(); i++){
            if (second < line[i]){
                second = line[i]; 
            }
        } 
        

        string jolt = "";
        jolt.push_back(first); 
        jolt.push_back(second); 
        
        int jolt_i = stoi(jolt); 
         

        joltages.push_back(jolt_i); 

    }
    int code = 0; 
    while (!joltages.empty()){
        code += joltages.back(); 
        joltages.pop_back(); 
    }
    cout << "Code: "<< code << endl; 
}