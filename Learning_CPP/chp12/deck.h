#include <vector>

#include "card.h"

struct Deck{
    // Declare instance vars
    std::vector<Card> cards;

    // Init func
    Deck();

    // Member func
    void print () const;
    int find(const Card& card) const;
    void swapCards(const int low_index, const int high_index);
    void shuffleDeck();
    void simpleSort();
};