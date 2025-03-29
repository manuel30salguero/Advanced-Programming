#include <iostream>

template<typename T>
concept Numeric = std::integral <T> || std::floating_point <T>;

template<Numeric T>
T sum(const T& a, const T& b){
    return a + b;
}

template<Numeric T, Numeric... Args>
T sum(const T& a, const Args&... args){
    return a + sum(args...);
}

int main(){
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;            
    std::cout << sum(1.1, 2.2, 3.3) << std::endl;

    return EXIT_SUCCESS;
}