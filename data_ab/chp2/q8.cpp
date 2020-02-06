#include <iostream>

// Functions
int removeZeroElements(int scores[], int n_scores){
    for(int i=n_scores - 1; i>-1; i--){
        if(scores[i] == 0){
            for(int j=i; j<n_scores - 1; j++){
                // For current i until n_scores-1
                // Replace current with next, until n_scores - 2 and n_scores - 1
                scores[j] = scores[j+1];
            }
            n_scores--;
        }
    }
    return n_scores;
}

int main(){
    int n_scores = 13;
    int arr[20] = {65, 0, 95, 0, 0, 79, 82, 0, 84, 94, 86, 90, 0};
    n_scores = removeZeroElements(arr, n_scores);
    std::cout << "nSCores:" << n_scores << std::endl;
    for(int i=0; i<n_scores; i++){
        std::cout<< arr[i] << ", ";
    }
    std::cout << std::endl;
    return 1;
}