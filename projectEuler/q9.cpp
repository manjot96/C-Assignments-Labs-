#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
/*
Misunderstood question:
    vector<int> v;
    for(int i = 0; i < 32; ++i)
        v.push_back(pow(i, 2));

    cout << v[30] << endl;
    for(size_t i = v.size() - 1; i > 0; --i)
        for(size_t j = i -1; j > 0; --j)
            for(size_t k = j - 1; k > 0; --k)
                if((v[i] + v[j] + v[k]) == 1000)
                    cout << i+j+k << endl;
*/

    for(int a = 1; a < 1000; ++a)
        for(int b = a+1; b < 1000; ++b) {
            int c = 1000-a-b;
            if(pow(a,2) + pow(b,2) == pow(c,2))
                cout << a*b*c << endl;
        }
}
