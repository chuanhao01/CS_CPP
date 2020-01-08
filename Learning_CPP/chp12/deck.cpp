#include <vector>

#include "deck.h"

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