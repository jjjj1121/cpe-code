#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace std;
using namespace boost::multiprecision; 

int main() {
    int n;
    vector<cpp_int> fibonacci; 
    fibonacci.push_back(0);
    fibonacci.push_back(1);
    while (cin >> n) {
        if (n >= fibonacci.size()) {
            for (int i = fibonacci.size(); i <= n; i++) {
                fibonacci.push_back(fibonacci[i - 1] + fibonacci[i - 2]);
            }
        }
        cout << "The Fibonacci number for " << n << " is " << fibonacci[n] << endl;
    }
    return 0;
}

