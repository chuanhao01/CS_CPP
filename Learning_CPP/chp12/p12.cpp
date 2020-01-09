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

Deck merge(const Deck& deck_1, const Deck& deck_2){
    if(deck_1.cards.size() == 0){
        return deck_2;
    }
    else if(deck_2.cards.size() == 0){
        return deck_1;
    }

    // Creating the final deck with enough length
    Deck final_deck (deck_1.cards.size() + deck_2.cards.size());

    // i is the index for deck_1 and j is the index for deck_2
    int i=0, j=0;
    for(int k=0; k<final_deck.cards.size(); k++){
        // For every space in the final_deck
        if(i == deck_1.cards.size()){
            // If deck 1 is done
            final_deck.cards[k] = deck_2.cards[j];
            j++;
        }
        else if(j == deck_2.cards.size()){
            final_deck.cards[k] = deck_1.cards[i];
            i++;
        }
        else{
            if(deck_1.cards[i].greaterThan(deck_2.cards[j])){
                // Check if the deck 1 card is smaller than deck 1
                final_deck.cards[k] = deck_2.cards[j];
                j++;
            }
            else{
                final_deck.cards[k] = deck_1.cards[i];
                i++;
            }
        }
    }

    return final_deck;
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

    // deck.shuffleDeck();
    // deck.print();

    // deck.simpleSort();
    // deck.print();

    deck.shuffleDeck();

    // Deck hand_1 = deck.subdeck(0, 4);
    // Deck hand_2 = deck.subdeck(5, 9);

    // hand_1.simpleSort();
    // hand_2.simpleSort();

    // Deck final_deck = merge(hand_1, hand_2);
    // final_deck.print();

    // Deck final_deck = deck.mergeSort();
    // final_deck.print();

    Deck final_deck = deck.recMergeSort(deck);
    final_deck.print();

    return 1;
}