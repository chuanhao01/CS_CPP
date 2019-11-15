#include <iostream>
#include "Time.h"

int main(){
    Time a (5000.0);
    Time b (10, 20, 10.1);
    // a.print();
    // std::cout << a.convertToSeconds() << std::endl;
    a.print();
    a.increment(200.0);
    b.print();
    return 1;
}