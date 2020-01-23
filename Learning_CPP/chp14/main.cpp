// Some main libs
#include <iostream>
#include <vector>

// Our own classes
#include "complex.h"

Complex addComplex(Complex& c1, Complex& c2){
    Complex sum;
    double real_sum = c1.getReal() + c2.getReal();
    double real_imag = c1.getImaginary() + c2.getImaginary();
    sum.setCartesian(real_sum, real_imag);
    return sum;
}

Complex multiplyComplex(Complex c1, Complex c2){
    Complex product;
    double theta = c1.getTheta() * c2.getTheta();
    double mag = c1.getMagnitude() + c2.getMagnitude();
    product.setPolar(theta, mag);
    return product;
}

int main(){
    Complex c1, c2;
    c1.setCartesian(2.0, 3.0);
    c2.setCartesian(3.0, 4.0);
    // c1.setPolar(0.5, 1);
    // c2.setPolar(-0.5, 5);
    Complex c3 = addComplex(c1, c2);
    // Complex c3  = multiplyComplex(c1, c2);
    c3.printPolar();
    c3.printCartesian();
    return 1;
}