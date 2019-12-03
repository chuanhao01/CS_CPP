#include <iostream>
#include <vector>

#include "card.h"

Card::Card(){
    suit = 0;
    rank = 0;
    return;
}

Card::Card(int s, int r){
    suit = s;
    rank = r;
    return;
}

void Card::print() const{
    // Creating the vector and populating the vector
    std::vector<std::string> suits (4);
    suits[0] = "Clubs";
    suits[1] = "Diamonds";
    suits[2] = "Hearts";
    suits[3] = "Spades";
    std::vector<std::string> ranks (14);
    ranks[1] = "Ace";
    for(int i=2; i<11; i++){
        ranks[i] = std::to_string(i);
    }
    ranks[11] = "Jack";
    ranks[12] = "Queen";
    ranks[13] = "King";
    std::cout <<  ranks[rank]<< " of " << suits[suit ]<< std::endl;
    return;
}

bool Card::greaterThan(const Card& c1) const {
    if(suit > c1.suit){
        return true;
    }
    else if (suit == c1.suit){
        if(rank > c1.rank){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Card::greaterThanReal(const Card& c1) const {
    if(suit > c1.suit){
        return true;
    }
    else if(suit == c1.suit){
        if(c1.rank == 1){
            return false;
        }
        else if(rank == 1){
            return true;
        }
        else if(rank > c1.rank){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}