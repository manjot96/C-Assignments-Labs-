#include <iostream>
#include <string>
using namespace std;


//Find the smallest positive number that is divisible by numbers ranging 1-20;

bool checkRange(const int& n) {
    for(size_t i = 20; i > 1; --i)
        if(n % i != 0)
            return false;
    
    return true;
}


int main() {
    int n = 20;
    while(true) {
        if(checkRange(n))
            break;
        n+= 20;
    }
    cout << n << endl;
}
