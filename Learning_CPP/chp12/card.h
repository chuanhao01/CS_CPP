struct Card{
    // Declare instance variables
    int suit, rank;

    // Init function
    Card ();
    Card (int s, int r);

    // Member functions
    void print () const;
    bool greaterThan(const Card& c1) const;
    bool greaterThanReal(const Card& c1) const;
};
