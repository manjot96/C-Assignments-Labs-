#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int kth_selection(const vector<int>& v, size_t k) {
    vector<int>  left, mid, right;
    int          a = v[0];

    if(v.size() == 1)
        return a;

    for(vector<int>::size_type i = 0; i < v.size(); i++)
        if(a > v[i])
            left.push_back(v[i]);
        else if(a == v[i])
            mid.push_back(v[i]);
        else
            right.push_back(v[i]);
        
    if(k <= left.size())
        return kth_selection(left, k);
    if (k <= (mid.size()+left.size()))
        return a;
        
    return kth_selection(right, k-(left.size() + mid.size()));
}

vector<string> subset(size_t n) {
    vector<string> first;
    if(n == 0)
        return {""};
    
    first = subset(n-1);
    vector<string> second;
    transform(first.begin(), first.end(), back_inserter(second), [](const string& s) {return "0" + s;});
    transform(first.rbegin(), first.rend(), back_inserter(second), [](const string& s) {return "1"+s;});  

    return second;
}

int main() {
    vector<int> v{3,5,6,3,7,5};
    
    for(vector<int>::size_type i = 1; i <= v.size(); i++)
        cout << kth_selection(v, i);
    cout << endl;
    auto x = subset(4);

    for(auto& y : x)
        cout << y << ' ';
    cout << endl;
}
