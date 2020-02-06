#include <iostream>

std::string onlyConnectize(std::string phrase) {
    // In this function we will remove the vowels and any other none alphabets characters in the string, then turn all the characters into uppercase
    if(phrase == ""){
        return "";
    }
    else{
        if(isalpha(phrase[0])){
            // Checking if the current char is ann alphabet
            // Get the cureent char in upper case
            char current_char = putchar(toupper(phrase[0]));
            std::cout << current_char << std::endl;
            if(current_char == 'A' || current_char == 'E' || current_char == 'I' || current_char == 'O' || current_char == 'U'){
                // if the char is a vowel, remove it
                return onlyConnectize(phrase.substr(1));
            }
            else{
                return current_char + onlyConnectize(phrase.substr(1));
            }
        }
        else{
            return onlyConnectize(phrase.substr(1));
        }
    }
}

int main(){
    std::string test = "aghghgheioughgh";
    std::string final = onlyConnectize(test);
    std::cout << final << std::endl;
    return 1;
}