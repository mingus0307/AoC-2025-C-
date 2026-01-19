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
         

        // number extraction and transforming them to int64_t  
        size_t pos = line.find('-'); 

        string beginString = line.substr(0, pos);
        int64_t  begin = stoll(beginString); 


        string endString = line.substr(pos+1);
        int64_t end = stoll(endString); 
        
         

        // iterate over the given range 
        for (int64_t i = begin; i <= end; i++ ){
            
            // take a group and make it bigger everytime until you reach half 
            string s = to_string(i);
            size_t n = s.size();

            
            for (size_t len = 1; len <= n / 2; ++len) {
                if (n % len != 0) continue;              

                string subgroup = s.substr(0, len);
                bool ok = true;

                for (size_t pos = 0; pos < n; pos += len) {
                    if (s.substr(pos, len) != subgroup) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    
                    cout << s << " is repetition of " << subgroup << "\n";
                    invalid.push_back(i);
                    break;
                }
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