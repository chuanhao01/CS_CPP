#include <vector>

#include "card.h"

struct Deck{
    // Declare instance vars
    std::vector<Card> cards;

    // Init func
    Deck();

    // Member func
    void print () const;
};