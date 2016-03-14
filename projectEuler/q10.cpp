#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
#define N 2000000

int main() {
    bitset<N>   isprime;
    long        sum = 0;
    isprime.set();

    for(size_t i = 2; i < sqrt(N); i++)
        if(isprime[i])
            for(size_t j = i; j*i < N; j++)
                isprime[j * i] = 0;

    for(int i = 2; i < N; ++i)
        if(isprime[i])
            sum += i;
    cout << sum << endl;
}
