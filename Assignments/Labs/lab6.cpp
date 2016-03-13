#include <iostream>
#include <bitset>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define N 10000000
bitset<N> isprime;

int main(){

    isprime.set();
    size_t nprimes = 0;
    Map<string, set<int>>  m;
 
    for(size_t i = 2; i < sqrt(N); i++){
        if(isprime[i]){
            for(size_t j = i; j*i < N; j++){
                isprime[j * i] = 0;
            }
        }
    }
 
    for(int i = 1000000; i < N; i++){
        if(isprime[i]){
            sort(x.begin(), x.end());
            cout << i << endl;
            ++nprimes;
        }
    }
    cout << nprimes << endl;

}