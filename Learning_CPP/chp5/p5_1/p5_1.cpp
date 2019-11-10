#include <iostream>
#include <cmath>

double distance(double x1, double y1, double x2, double y2){
    double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return d;
}

double area(double radius){
    double a = M_PI * pow(radius, 2);
    return a;
}

double area(double xp, double yp, double xc, double yc){
    double radius = distance(xp, yp, xc, yc);
    double a = area(radius);
    return a;
}

int main(){
    double a = area(5, 5, 0, 0);
    std::cout << a << std::endl;
    return 1;
}