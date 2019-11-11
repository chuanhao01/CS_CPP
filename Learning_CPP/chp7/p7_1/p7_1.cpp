#include <iostream>
#include <string>

void travelString(std::string x){
    int i = 0;
    while(i < x.length()){
        std::cout << x[i] << std::endl;
        i++;
    }
    return;
}

int contains(std::string x, char a){
    int i = 0;
    while(i < x.length()){
        // If the char is found
        if(x[i] == a){
            return i;
        }
        i++;
    }
    // If char does not exists
    return -1;
}

// Count how many times a appears in x
int countMultiple(std::string x, char a){
    int i = 0, count = 0;
    while(i < x.length()){
        if(x[i] == a){
            count++;
        }
        i++;
    }
    return count;
}

int main(){
    std::string a = "helloll";
    std::cout << countMultiple(a, 'l') << std::endl;
    return 1;
}