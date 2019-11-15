struct Card{
    // Declare instance variables
    int suit, rank;

    // Init function
    Card ();
    Card (int s, int r);

    // Instance variables
    void print () const;
    bool greaterThan(const Card& c1) const;
};