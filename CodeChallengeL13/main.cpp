#include <iostream>
#include <vector>
#include "buffer.h"
#include <chrono>

int main() {
    
    // Part 1: Introduction to Copy vs. Move
    std::cout << "\nPart 1: Introduction to Copy vs. Move" << std::endl;
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = v1;        // Copy
    std::vector<int> v3 = std::move(v1); // Move

    std::cout << "v1 size: " << v1.size() << std::endl;
    std::cout << "v2 size: " << v2.size() << std::endl;
    std::cout << "v3 size: " << v3.size() << std::endl;

    // Part 3: Using Your Class
    std::cout << "\nPart 3: Using Your Class" << std::endl;
    Buffer b1(100);
    Buffer b2 = b1;           // Should call copy constructor
    Buffer b3 = std::move(b1); // Should call move constructor

    Buffer b4(50);
    b4 = b2;                  // Should call copy assignment
    b4 = std::move(b2);       // Should call move assignment

    // Part 4: Performance Comparison
    std::cout << "\nPart 4: Performance Comparison" << std::endl;
    Buffer bmill1(10000000);

    auto start = std::chrono::high_resolution_clock::now();
    Buffer bmill2 = bmill1;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    Buffer bmill3 = std::move(bmill1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";

    return 0;
}
