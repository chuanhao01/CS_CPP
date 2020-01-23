// Other libs
#include <math.h>
#include <iostream>
#include <assert.h>

#include "complex.h"

// Setter functions
void Complex::setCartesian(double r, double i){
    if(polar){
        polar = false;
    }
    real = r;
    imag = i;
    cartesian = true;
}
void Complex::setPolar(double t, double m){
    if(cartesian){
        cartesian = false;
    }
    theta = t;
    mag = m;
    polar = true;
}

// Getter functions
// Cartesian
double Complex::getReal(){
    if(cartesian == false){
        calculateCartesian();
    }
    return real;
}
double Complex::getImaginary(){
    if(cartesian == false){
        calculateCartesian();
    }
    return imag;
}

// Polar
double Complex::getTheta(){
    if(polar == false){
        calculatePolar();
    }
    return theta;
}
double Complex::getMagnitude(){
    if(polar == false){
        calculatePolar();
    }
    return mag;
}

// Helper functions
// Printing
void Complex::printPolar(){
    std::cout<< getMagnitude() << "e^" << getTheta() << 'i' << std::endl;
}
void Complex::printCartesian(){
    std::cout << getReal() << '+' << getImaginary() << 'i' << std::endl;
}

// Calculating stuff
void Complex::calculateCartesian(){
    assert(polar);
    cartesian = true;
    real = mag * cos(theta);
    imag = mag * sin(theta);
    assert(polar && cartesian);
}
void Complex::calculatePolar(){
    assert(cartesian);
    polar = true;
    if(real == 0 && imag == 0){
        // If the number is 0
        mag = 0;
        theta = 0;
    }
    else{
        mag = sqrt((pow(real, 2) + pow(imag, 2)));
        theta = atan(imag/real);
        if(real < 0 && imag > 0){
            theta = M_PI + theta;
        }
        else if(real < 0 && imag < 0){
            theta = M_PI + theta;
        }
        else if(real > 0 && imag < 0){
            theta = 2 * M_PI + theta;
        }
    }
    assert(cartesian && polar);
}

