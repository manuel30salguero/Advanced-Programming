// Task 1
// Write a function to solve a quadratic equation:


#include <iostream>
#include <cmath>
#include <iomanip>  // Para std::setprecision

void solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        std::cout << "This is not a quadratic equation." << std::endl;
        return;
    }
    
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "The roots are real and different: " 
                  << std::fixed << std::setprecision(6) 
                  << root1 << " and " << root2 << std::endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        std::cout << "The roots are real and equal: " 
                  << std::fixed << std::setprecision(6) 
                  << root << std::endl;
    } else {
        double realPart = b == 0 ? 0.0 : -b/(2*a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        std::cout << "The roots are complex: " 
                  << std::fixed << std::setprecision(6) 
                  << std::noshowpos << realPart << " "
                  << "+/-" << " " << imaginaryPart << "i" 
                  << std::endl;
    }
}

int main() {
    double a, b, c;
    std::cout << "Enter the coefficients a, b and c: ";
    std::cin >> a >> b >> c;
    solveQuadratic(a, b, c);
    return 0;
}


