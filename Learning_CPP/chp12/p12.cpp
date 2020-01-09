#include <iostream>
#include <vector>
#include <stdlib.h>

// #include "card.h"
#include "deck.h"

// std::vector<Card> createDeck (){
//     std::vector<Card> deck (52);
//     for(int suit=0; suit<4; suit++){
//         for(int rank=1; rank<14; rank++){
//             deck[suit * 13 + (rank - 1)].suit = suit;
//             deck[suit * 13 + (rank - 1)].rank = rank;
//         }
//     }
//     return deck;
// }

// void printDeck (const std::vector<Card>& deck){
//     int deck_length = deck.size();
//     for(int i=0; i<deck_length; i++){
//         deck[i].print();
//     }
//     return;
// }

// int linearFind(const std::vector<Card>& deck, const Card& c1){
//     int deck_length = deck.size();
//     for(int i=0; i<deck_length; i++){
//         if(deck[i].suit == c1.suit && deck[i].rank == c1.rank){
//             return i;
//         }
//     }
//     return -1;
// }

// Global functions

// Function to compare 2 cards
bool cardEquals(const Card& card_a, const Card& card_b){
    if(card_a.suit == card_b.suit && card_a.rank == card_b.rank){
        return true;
    }
    else{
        return false;
    }
}

// Function to get a random between low and high
int randomLowHigh(const int& low, const int& high){
    int rand_num = (random() % (high - low + 1)) + low; 
    return rand_num;
}

int main(){
    // Card c1 (2, 3);
    // Card c2 (2, 2);
    // std::cout << c1.greaterThanReal(c2) <<std::endl;
    // std::vector<Card> deck = createDeck();
    // printDeck(deck);
    // std::cout << linearFind(deck, c1) << std::endl;

    Deck deck;
    // int a = deck.find(c2);
    // std::cout << a << std::endl;
    // deck.swapCards(1, 2);

    deck.shuffleDeck();
    deck.print();

    deck.simpleSort();
    deck.print();
    return 1;
}