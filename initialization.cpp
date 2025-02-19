#include <iostream>
#include <string>
#include <tuple>

// Part 4: Define a struct with three members
struct Point {
    int p, q, r;
};

int main() {
    // Part 1: Variable Initialization
    int a = 10; // Direct initialization
    double b{3.14}; // Uniform initialization
    std::string c("Hello"); // Direct initialization
    bool d = true; // Copy initialization
    
    // Print initial values
    std::cout << "Initial values:\n";
    std::cout << "int: " << a << ", double: " << b << ", string: " << c << ", bool: " << d << "\n";
    
    // Part 2: Pointer modification
    int* ptrA = &a;
    *ptrA = 100;
    std::cout << "Pointer modification:\n";
    std::cout << "int: " << a << "\n";
    
    // Part 3: References and modifications
    int& refA = a;
    refA = 20; // Modify through reference
    double& refB = b;
    refB = 2.71;
    std::string& refC = c;
    refC = "World";
    bool& refD = d;
    refD = false;
    
    // Print modified values
    std::cout << "Modified values:\n";
    std::cout << "int: " << a << ", double: " << b << ", string: " << c << ", bool: " << d << "\n";
    
    // Part 4: Structured Binding
    Point s = {5, 10, 15};
    auto [p, q, r] = s;
    std::cout << "Structured Binding:\n";
    std::cout << "p: " << p << ", q: " << q << ", r: " << r << "\n";
    
    // Part 5: Identifying l-values and r-values (comments only)
    // a = 42; // 'a' is an l-value, '42' is an r-value
    // int x = a + b; // 'a' and 'b' are l-values, '(a + b)' is an r-value
    // &a; // 'a' is an l-value
    // std::string s = c + " World"; // 'c' is an l-value, "World" is an r-value, '(c + " World")' is an r-value
    // int& refX = x; // 'x' is an l-value
    // int&& rref = 100; // '100' is an r-value, 'rref' is an r-value reference
    return 0;
}
