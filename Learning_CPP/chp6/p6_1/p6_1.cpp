#include <iostream>

int main(){
    int i = 10;
    while(i > 0){
        std::cout << i << '!' << std::endl;
        i--;
    }
    std::cout << "Blastoff!" << std::endl;
    return 1;
}