#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Recursive function:
int fib(int n) {
    if(n == 0)
        return 0; 
    else if(n == 1)
        return 1;
    
    return fib(n-1) + fib(n-2);
}

int main() {
    cout << fib(15) << endl;
    int sum = 2;
    int current = 1, next = 2, node, total = 0;
    
    while (current < 4000000) {
        node = current + next;
        cout << " + " << node;
        current = next;
        next = node;
        total += node;
        if( node % 2 == 0)
            sum += node;
    }
    cout << endl;

    cout << "Current: " << current
        << " Total: " << total << endl;
    
    cout << "sum: " << sum << endl;
}
