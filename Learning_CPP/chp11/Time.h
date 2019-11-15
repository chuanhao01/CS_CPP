// Header for Time struct
struct Time{
    // Declaring Structure of the object
    int hour, minute;
    double second;

    // Initialising obejct
    Time (double seconds);
    Time (int h, int min, double s);

    // Modifiers
    void increment (double seconds) ;

    // Functions
    void print () const;
    double convertToSeconds () const;
    Time add(const Time& t2) const;
};
