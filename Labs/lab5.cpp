#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Grade {
    string              id;
    map<string, int>    grades;
};

ostream&
operator<<(ostream& os, const Grade& r) {
    os << r.id << endl << r.grades.size() << endl;
    for(auto& x: r.grades)
        os << x.first << ' ' << x.second << endl;
    return os;
}

istream&
operator>>(istream& is, Grade& g) {
    size_t  size = 0;
    g.grades.clear();
    if(is >> g.id >> size) {
        string  course;
        int     score;
        for(size_t i = 0; i < size; i++) {
            is >> course >> score;
            g.grades.insert(make_pair(course, score));
        }
    }
    return is;
}

struct Cmp {
    string temp;
    Cmp(const string& s): temp(s) {}
    
    bool operator()(const Grade& lhs, const Grade& rhs) const {
        auto lh = lhs.grades.find(temp), rh = rhs.grades.find(temp);
        if(lh == lhs.grades.end())
            return false;
            
        if(rh == rhs.grades.end())
            return true;
            
        return lh->second < rh->second;
    }
};

struct MaxFinder {
    string          temp;
    vector<string>  s;
    int             max;
    MaxFinder(const string& s):temp(s) {}
    
    void operator()(const Grade& x) {
        auto iterator = x.grades.find(temp);
        if(iterator != x.grades.end()) {
            if(iterator->second > max) {
                s.clear();
                max = iterator->second;
                s.push_back(x.id);
            } else if(iterator->second == max)
                s.push_back(x.id);
        }
    }
};

int main() {
    vector<Grade>   v;
    Grade           g;
    
    while(cin >> g)
        v.push_back(g);
    
    sort(v.begin(), v.end(), Cmp("COMP3512"));
    
    for(auto& x: v)
        cout << x << endl;
    
    MaxFinder m = for_each(v.begin(), v.end(), MaxFinder("COMP3512"));
    
    cout << "Max Score: " << m.max << endl;
    
    cout << "Students that have the max score: " << endl;
    for(auto& y: m.s)
        cout << y << endl; 
}