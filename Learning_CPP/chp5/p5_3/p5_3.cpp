#include <iostream>
#include <cmath>

int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }
    else
    {
        int current_term = fib(n-1) + fib(n-2);
        return current_term;
    }
    
}

int main(){
    std::cout << fib(7);
    return 1;
}