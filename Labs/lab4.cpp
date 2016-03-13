#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> 
interleave(int x, const vector<int>& v) {
    vector< vector<int> >   retVec;
    vector<int>             tempVec;
    
    for(size_t i = 0; i <= v.size(); i++) {
        tempVec = v; //reseting tempVec
        tempVec.insert(tempVec.begin() + i, x);
        retVec.push_back(tempVec);
    }
    
    return retVec;
}

vector<vector<int>>
permutate(size_t n) {
    if(n == 1)
        return vector<vector<int>> {vector<int>{1}};
    
    vector<vector<int>> result;
    
    for(auto& x : permutate(n-1))
        for(auto& y : interleave(n, x))
            result.push_back(y);
            
    return result;
}

int main() {
    vector<vector<int>> v2 = permutate(4);
    
    for(auto& x : v2) {
        for(auto& c : x)
            cout << c << ' ';
        cout << endl;
    }
}