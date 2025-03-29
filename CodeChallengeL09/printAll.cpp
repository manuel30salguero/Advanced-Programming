#include <iostream>

using namespace std;

template<typename T>
void printAll(const T& val){
    cout << val << endl;
}

template<typename T, typename... Args>
void printAll(const T& val, const Args&... args){
    cout << val << ' ';
    printAll(args...);
}

int main() {
    printAll(1, 2.5, "Hello", 'c'); // Should print: 1 2.5 Hello c

    return EXIT_SUCCESS;
}