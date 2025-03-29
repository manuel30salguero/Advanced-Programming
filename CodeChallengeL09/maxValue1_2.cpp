#include <iostream>
using namespace std;

template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T maxValue(T a, T b, T c) {
    return maxValue(a, maxValue(b, c));
}

int main() {
    cout << maxValue(1, 5, 3) << endl;          // Should print 5
    cout << maxValue(2.1, 3.7, 1.9) << endl;    // Should print 3.7
}