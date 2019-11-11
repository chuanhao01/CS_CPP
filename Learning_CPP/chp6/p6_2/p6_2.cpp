#include <iostream>

void printMultiples(int x, int end){
    int i = 1;
    while(i < end + 1){
        std::cout << i * x << "\t";
        i++;
    }
    std::cout << std::endl;
    return;
}

void multiTable(int x){
    int i = 1;
    while(i < x + 1){
        printMultiples(i, x);
        i++;
    }
    return;
}

int main(){
    multiTable(6);
    return 1;
}