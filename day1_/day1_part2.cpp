#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(void){

    ifstream inFile;
    inFile.open("test.txt"); 
    
    if (!inFile){
        cerr << "unable to open input"; 
        exit(1); 
    }


    int arrow = 50; 
    int fin = 0; 

    string line; 
    while (getline(inFile, line)) {
        //direction where its turned
        string direction = line.substr(0,1); 
        //amount of clicks
        string rotations = line.substr(1);
         
        int rotCount = stoi(rotations);

        cout << "Dir:" << direction << " rot:" << rotCount << " arrow: " << arrow << endl;  
        
        // check for full cycles 
        int k = rotCount; 
        fin += k / 100; 
        // elmininate full cycles 

        
        rotCount = rotCount % 100; 

        if (rotCount % 100 > 0 && arrow != 0){
            if (direction == "L"){
                if (rotCount % 100 >= arrow){
                    fin++; 
                }
            }else {
                if (rotCount % 100 >= (100 -arrow)){
                    fin++; 
                }
            }
        }

        //decide which direction we are going to roll in 
        if(direction == "L"){
            rotCount *= -1; 

        }
        arrow += rotCount; 
        
        // modulo in c++ works a bit differently than in maths: -1 % 100 = -1, thats why we need a little workaround 
        arrow = (arrow % 100 + 100) % 100; 

        
        cout << "   arrow: " << arrow << endl << endl; 

    }
    cout << "Code: " << fin << endl; 

}