#include <iostream>
using namespace std;

template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maxValue(5, 10) << endl;          // Should print 10
    cout << maxValue(3.5, 2.1) << endl;       // Should print 3.5
    cout << maxValue(string("apple"), string("orange")) << endl; // Should print "orange"
}