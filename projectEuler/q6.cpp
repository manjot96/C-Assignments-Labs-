#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //sum of squares: (starting from 11);
    int sumSquares = 0, sum = 0;
    for(int i = 1; i <= 100; ++i) {
        sumSquares += pow(i, 2);
        sum += i;
    }
    
    int squareSum = pow(sum, 2);

    cout << (squareSum - sumSquares) << endl;
}
