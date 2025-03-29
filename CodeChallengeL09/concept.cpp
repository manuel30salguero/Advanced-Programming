#include <iostream>
#include <concepts>
using namespace std;

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(3, 4) << endl;       // Should print 7
    cout << add(2.5, 3.1) << endl;   // Should print 5.6
    //cout << add("a", "b");        // Should fail at compile time
}