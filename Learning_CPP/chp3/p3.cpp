#include <iostream>

void checkout (int i1) {
    int show = i1 * 10;
    std::cout << show << std::endl;
    return;
}

int main () {
    std::cout << "Below me is by the function" << std::endl;
    checkout(3);
    return 1;
}