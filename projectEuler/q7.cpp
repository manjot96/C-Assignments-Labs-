#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(const int& n) {
    
    if(n % 2 == 0 && n != 2)
        return false;
    
    for(int i = 2; i < n /2 + 1; ++i)
        if(n % i == 0)
            return false;     

    return true;
}

int main() {
    size_t total = 0;
    int lastPrime, i;
    for(i = 0; total <= 10001; ++i)
        if(isPrime(i)) {
            total++;
            lastPrime = i;
        }
    cout << total << endl;
    cout << i << endl;
    cout << lastPrime << endl;
    
}
