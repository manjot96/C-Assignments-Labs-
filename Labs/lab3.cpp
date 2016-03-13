#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

string rtrim(const string& s) {
    string::size_type i;
    
    for(i = s.size(); i > 0; i--)
        if(i == 0 || !isspace(s[i-1]) )
            break;
    
    return s.substr(0, i);
}

string replace_all(const string& s, const string& oldstr, const string& newstr) {
    string::size_type  i = 0;
    string             str = s;
    
    while((i = str.find(oldstr, i)) != string::npos) {
        str.replace(i, oldstr.size(), newstr);
        i += newstr.size();
    }
    
    return str;
}

string squeeze(const string& s, char c) {
    string             str = s;
    string::size_type  i = 0;
    
    for(i = 0; i < s.size(); i++){
        if(str[i] == c && str[i+1] == c) {
            str.erase(i, 1);
            i -= 1;
        }
    }
    
    return str;
}

vector<string> split(const string& s, const string& delim) {
    vector<string> v;
    string::size_type start = 0, pos;
    
    while((pos = s.find_first_of(delim, start)) != string::npos) {
        v.push_back(s.substr(start, (pos - start)));
        start = pos + 1;
    }
    v.push_back(s.substr(start));
    
    return v;
}

int main() {
    vector<string> v;
    //cout << replace_all("alley-dalley", "al", "oke") << endl;
    //cout << rtrim("    hello woorldd\t       ") << endl;
    cout << squeeze("", 'a') << endl;
    /*
    v = split("ab<cd>ef<gh>i", "<>");
    for(auto& x : v)
        cout << x << endl;
    
    v = split("<ab><>cd<", "<>");
    
    for(auto& x : v)
        cout << x << endl;
        */
}