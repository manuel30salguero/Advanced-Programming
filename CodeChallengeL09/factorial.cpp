#include <iostream>

template<int N>
struct Factorial{
    static constexpr int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0>{
    static constexpr int value = 1;
};

int main(){
    constexpr int result = Factorial<5>::value;
    std::cout << result << std::endl;
    
    return EXIT_SUCCESS;
}