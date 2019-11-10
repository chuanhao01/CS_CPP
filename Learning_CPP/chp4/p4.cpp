#include <iostream>

void countdown(int x){
    if(x > 0){
        std::cout << x << '!' << std::endl;
        countdown(x-1);
        return;
    }
    else
    {
        std::cout << "Blastoff" << std::endl;
        return;
    }
}

int main(){
    countdown(10);
    return 1;
}