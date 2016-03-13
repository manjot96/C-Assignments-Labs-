#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    string        input, word1, word2;
    char          char1, char2;
    int           width, precision = 0, intOutput;
    double        fltOutput;
    bool          flag = false;
    
    
    while(1) {
        istringstream ss, ss1, ss2;
        flag = false;   
        
        cout << "Enter input" << endl;
        if(!getline(cin, input)) {
            cin.clear();
            break;
        }
        
        
        ss.str(input);
        if(!(ss >> word1)) {
            cout << "invalid input(1)" << endl; 
            continue; 
        }
        if(!(ss >> word2)) {
            cout << "invalid input(2)" << endl; 
            continue; 
        }
        
        
        ss1.str(word1);
        ss2.str(word2);
        
        if(!(ss1 >> width)) {
            cout << "invalid input(3)" << endl; 
            continue; 
        }
        if(!(ss1 >> char1)) {
            cout << "invalid input(4)" << endl; 
            continue; 
        }
        
        if(char1 == '.') {
            //ss1.seekg(ios::off_type(1), ios_base::cur);
            if(!(ss1 >> precision)) {
                cout << precision << " invalid input(5)" << endl;
                continue; 
            }
            ss1 >> char1;
            flag = true;
        }
        cout << setw(width);
        
        if(flag == true) {
            ss2 >> fltOutput;
            cout << setprecision(precision);
            if(char1 == 'f') {
                cout << nouppercase << fixed << fltOutput << endl;
            } else if(char1 == 'e') {
                cout << nouppercase << scientific << fltOutput << endl;
            } else if(char1 == 'E') {
                cout << uppercase << scientific << fltOutput << endl;
            } else {
                cout << "whats happening?!?!?!?!?!" << endl;
                continue;
            }
        } else {
            ss2 >> intOutput;
            if(char1 == 'd') {
                cout << nouppercase << dec << intOutput << endl;
            } else if(char1 == 'o') {
                cout << nouppercase << oct << intOutput << endl;
            } else if(char1 == 'x') {
                cout << nouppercase << hex << intOutput << endl;
            } else if(char1 == 'X') {
                cout << uppercase << hex << intOutput << endl;
            } else {
                cout << "whats happening?!?!?!?!?!" << endl;
                continue;
            }
        }
    }
        
        
    
}