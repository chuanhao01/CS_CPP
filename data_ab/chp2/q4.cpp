#include <iostream>

bool isSorted(const int array[], const int n){
    for(int i=0; i<n-1; i++){
        if(array[i] > array[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    const int MAX_SIZE = 10;
    int n = 5;
    int array[MAX_SIZE];
    array[0] = 1;
    array[1] = 5;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    std::cout << isSorted(array, n) << std::endl;
    return 1;
}