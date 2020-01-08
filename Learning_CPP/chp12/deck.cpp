#include <vector>
#include <iostream>

#include "deck.h"

bool cardEquals(const Card& card_a, const Card& card_b);
int randomLowHigh(const int& low, const int& high);

Deck::Deck(){
    // Declare empty temp vector
    std::vector<Card> temp (52);

    cards = temp;
    for(int suit=0; suit<4; suit++){
        // Getting suits
        for(int rank=1; rank<14; rank++){
            // Getting rank
            cards[suit * 13 + rank].suit = suit;
            cards[suit * 13 + rank].rank = rank;
        }
    }
}

void Deck::print () const{
    for(int suit=0; suit<4; suit++){
        for(int rank=1; rank<14; rank++){
            cards[suit * 13 + rank].print();
        }
    }
}

int Deck::find(const Card& card) const{
    for(int i=0; i<cards.size(); i++){
        if(cardEquals(cards[i], card)){
            return i;
        }
    }
    // If the card does not match anything
    return -1;
}

void Deck::swapCards(const int low_index, const int high_index){
    Card temp = cards[low_index];
    cards[low_index] = cards[high_index];
    cards[high_index] =  temp;
    return;
}

void Deck::shuffleDeck(){
    for(int lower_index=0; lower_index<cards.size(); lower_index++){
        // Going through all the indexes
        int higherIndex = randomLowHigh(lower_index, cards.size());
        swapCards(lower_index, higherIndex);
    }
    return;
}