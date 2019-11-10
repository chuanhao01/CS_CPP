#include <iostream>
#include <cmath>

int factorial(int x){
    if(x <= -1){
        return -1;
    }
    else if(x > 0){
        return factorial(x-1) * x;
    }
    else
    {
        return 1;
    }
}

int main(){
    std::cout << factorial(10);
    return 1;
}