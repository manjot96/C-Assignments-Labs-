#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s) {
    for(size_t i = 0, j = s.size() -1; i < s.size() / 2; ++i, --j)
        if(s[i] != s[j])
            return false;
    return true;
}

int main() {
    size_t max = 0;
    for(size_t i = 100; i <= 999; ++i) {
        for(size_t j = 100; j <= 999; ++j) {
            string s = to_string(i*j);
            if(isPalindrome(s))
                if((i*j) > max)
                    max = i*j;
        }
    }
    cout << max << endl;
}
