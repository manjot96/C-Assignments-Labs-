#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, line;
    long max = 0, current;
    while(cin >> s)
        line += s;

    for(size_t i = 0; i + 13 < line.size(); i++) {
        current = 1;
        for(size_t j = i; j < i+13; j++) { 
            current = current * ((int) line[j] - 48); //subtracting 48 gives us the integer value;
        }
        if(current > max) 
            max = current;
    }

    cout << max;
}
