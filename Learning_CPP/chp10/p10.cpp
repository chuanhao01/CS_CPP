#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<int> randomVector(int n, int upper_bound){
    std::vector<int> vec (n);
    for(int i=0; i<n; i++){
        vec[i] = random() % upper_bound;
    }
    return vec;
}

void printVector(const std::vector<int> vec){
    int vec_len = vec.size();
    for(int i=0; i<vec_len; i++){
        std::cout << vec[i] << ',';
    }
    std::cout << std::endl;
    return;
}

int main(){
    // Part 1
    // std::vector<int> a (3, 1);
    // std::vector<int> b = a;
    // a[0] = 2;
    // std::cout << a[0] << std::endl << b[0] << std::endl;

    // Part 2
    // std::vector<int> values;
    // int c, i, len;
    // while(c != -1){
    //     std::cin >> c;
    //     values.push_back(int(c));
    // }
    // std::cout << std::endl;
    // len = values.size();
    // std::cout << "Length" << len << std::endl;
    // for(i=0; i<len; i++){
    //     std::cout << values[i];
    // }
    // std::cout << std::endl;

    // Part 3
    // std::vector<int> vec = randomVector(5, 50);
    // printVector(vec);

    // Part 4
    int upper_bound = 50, n = 50000;
    std::vector<int> vec = randomVector(n, upper_bound);
    std::vector<int> histogram (upper_bound, 0);
    for(int i=0; i<n; i++){
        int index = vec[i];
        histogram[index]++;
    }
    printVector(histogram);

    return 1;
}