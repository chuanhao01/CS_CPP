class Complex{
    // Private here
    private: 
    // Instance variables
    // For the cartesian cords
    double real, imag;
    // For polar cords
    double theta, mag;
    // Bool to check if mode is done
    bool polar, cartesian;

    // Helper functions
    // Calculating stuff
    void calculateCartesian();
    void calculatePolar();

    public:
        Complex (){};
        // Setter functions
        void setCartesian(double r, double i);
        void setPolar(double t, double m);
        // Getter functions
        // Cartesian
        double getReal();
        double getImaginary();
        // Polar
        double getTheta();
        double getMagnitude();
        // Helper functions
        // Print functions
        void printPolar();
        void printCartesian();
};

