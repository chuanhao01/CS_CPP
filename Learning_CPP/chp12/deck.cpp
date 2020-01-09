#include <vector>
#include <iostream>

#include "deck.h"

bool cardEquals(const Card& card_a, const Card& card_b);
int randomLowHigh(const int& low, const int& high);
Deck merge(const Deck& deck_1, const Deck& deck_2);

// Init functions for the object
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

Deck::Deck(const int& size){
    // Creating the vector of cards
    std::vector<Card> temp (size);
    cards = temp;
}

// Utility functions 
void Deck::swapCards(const int low_index, const int high_index){
    Card temp = cards[low_index];
    cards[low_index] = cards[high_index];
    cards[high_index] =  temp;
    return;
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

// Main functions
void Deck::print () const{
    for(int i=0; i<cards.size(); i++){
        cards[i].print();
    }
}

void Deck::shuffleDeck(){
    for(int lower_index=0; lower_index<cards.size(); lower_index++){
        // Going through all the indexes
        int higherIndex = randomLowHigh(lower_index, cards.size());
        swapCards(lower_index, higherIndex);
    }
    return;
}

void Deck::simpleSort() {
    for(int i=0; i<cards.size(); i++){
        int swap_index;
        // Here we find the smallest card to the right of the choosen card
        for(int j=i+1; j<cards.size(); j++){
            if(j == i+1){
                swap_index = j;
            }
            else{
                if(cards[swap_index].greaterThan(cards[j])){
                    // If the current card is bigger than the right card
                    swap_index = j;
                }
            }
            
        }
        // After we find the card to swap with
        swapCards(i, swap_index);
    }
    return;
}

Deck Deck::subdeck(const int& low, const int& high) const{
    Deck sub (high - low + 1);

    for(int i=0; i<sub.cards.size(); i++){
        sub.cards[i] = cards[low + i];
    }
    return sub;
}

Deck Deck::mergeSort() const{
    Deck hand_1 = subdeck(0, 4);
    Deck hand_2 = subdeck(5, 9);

    hand_1.simpleSort();
    hand_2.simpleSort();

    Deck final_deck = merge(hand_1, hand_2);

    return final_deck;
}

Deck Deck::recMergeSort(Deck deck) const{
    // Base case
    if(deck.cards.size() < 2){
        return deck;
    }

    int mid_point = deck.cards.size() / 2;
    Deck hand_1 = deck.subdeck(0, mid_point - 1);
    Deck hand_2 = deck.subdeck(mid_point, deck.cards.size() - 1);
    std::cout << hand_1.cards.size() << ' ' << hand_2.cards.size() << std::endl;
    return merge(recMergeSort(hand_1), recMergeSort(hand_2));
    
}