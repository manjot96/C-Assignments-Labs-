#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

bool get_word(const string& prompt, string& word, bool (*is_valid)(const string&)) {
    string         temp;
    istringstream  iss;
    
    while(1) {
        cout << prompt << endl;
        if(!getline(cin, temp)) {
            cin.clear();
            break;
        }
        
        iss.str(temp);
        
        if(iss >> word && is_valid(word)) {
            return true;
        }
        
        word.clear();
        temp.clear();
        iss.clear();
    }
    return false;
    
}

bool is_valid_word(const string& word) {
    if(word.length() != 9 || word[0] != 'a') {
        return false;
    }
    
    for(size_t i = 1; i < word.length(); i++) {
        if(!(isdigit(word[i]))) {
            return false;
        }
    }
    return true;
}

bool is_valid_score(int score) {
    return (score <= 100 && score >= 0);
}

bool get_int(const string& prompt, int& n, bool (*is_valid)(int) ) {
    string         temp;
    istringstream  iss;
    
    while(1) {
        cout << prompt << endl;
        if(!getline(cin, temp)) {
            cin.clear();
            break;
        }
        
        iss.str(temp);
        
        if(iss >> n && is_valid(n)) {
            return true;
        } else {
            cout << "Invalid input!" << endl;
        }
        
        temp.clear();
        iss.clear();
    }
    
    return false;
}

int main() {
    ostringstream  oss;
    string         id;
    int            score;
    
    while(1) {
        
        oss << setw(4);
        
        if( !(get_word("Enter an ID:", id, is_valid_word)) ) {
            return 1;
        }
        
        if( !(get_int("Enter an score:", score, is_valid_score)) ) {
            return 2;
        }
        
        oss << score;
        
        cerr << id << oss.str() << " ";
        
        oss.clear();
        oss.str("");
    }
}