#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool  isEvenSized(int64_t& n) {
    string num = to_string(n);
    
    if (num.length() % 2 == 0){
        return true; 
    }
    return false; 
}

int main(void){
    ifstream input; 
    input.open("day2_input.txt"); 

    if (!input){
        cerr << "unable to open input"; 
        exit(1); 
    }

    
    string line; 
    vector<int64_t> invalid; 

    while (getline(input, line, ',')){
        //cout << line << endl; 

        // number extraction and transforming them to int64_t  
        size_t pos = line.find('-'); 

        string beginString = line.substr(0, pos);
        int64_t  begin = stoll(beginString); 


        string endString = line.substr(pos+1);
        int64_t end = stoll(endString); 
        
        //cout << begin << " - " << end << endl; 

        // iterate over the given range 
        for (int64_t i = begin; i <= end; i++ ){
            // check number if its even in length
            // if not skip it anyways 
            if (!isEvenSized(i)){
                continue; 
            } 
            //cout << "wir sind hier" << endl; 
            // else half it and look if both halfs are identical
            string i_str = to_string(i); 
            int i_length = i_str.length(); 
            int i_mid =  i_length / 2; 

            string firstHalf = i_str.substr(0, i_mid);
            
            string secHalf = i_str.substr(i_mid); 

            //cout << firstHalf << " + " << secHalf << endl; 

            // if identical add to list
            if (firstHalf.compare(secHalf) == 0){
                invalid.push_back(stoll(i_str)); 
            }
             
        }



    }

            // add up the invalid ids 
        int64_t count = 0; 
        while (!invalid.empty()){
            count += invalid.back();
            invalid.pop_back();  
        }

        cout << "Code: " << count << endl; 
}