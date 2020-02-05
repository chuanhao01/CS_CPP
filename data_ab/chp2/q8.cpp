#include <iostream>

// Functions
int removeZeroElements(int scores[], int nScores){
    for(int i=nScores - 1; i>-1; i--){
        if(scores[i] == 0){
            for(int j=i; j<nScores - 1; j++){
                // For current i until nScores-1
                // Replace current with next, until nScores - 2 and nScores - 1
                scores[j] = scores[j+1];
            }
            nScores--;
        }
    }
    return nScores;
}

int main(){
    int nScores = 13;
    int arr[20] = {65, 0, 95, 0, 0, 79, 82, 0, 84, 94, 86, 90, 0};
    nScores = removeZeroElements(arr, nScores);
    std::cout << "nSCores:" << nScores << std::endl;
    for(int i=0; i<nScores; i++){
        std::cout<< arr[i] << ", ";
    }
    std::cout << std::endl;
    return 1;
}