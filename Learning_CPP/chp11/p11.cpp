#include <iostream>
#include <vector>

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

// Part 1
// Explicit declaration
// void Time::print () {
//     Time time = *this;
//     std::cout << time.hour << ':' << time.minute << ':' << time.second << std::endl;
// }

// Part 2
// Implicit declaration

// Init
Time::Time (double seconds){
    hour = int(seconds / 3600.0);
    seconds -= hour * 3600.0;
    minute = int(seconds/60.0);
    seconds -= minute * 60.0;
    second = seconds;
}

Time::Time (int h, int min, double s){
    hour = h;
    minute = min;
    second = s;
}

// Modifiers
void Time::increment(double secs) {
    double total_seconds = convertToSeconds() + secs;
    Time new_time (total_seconds);
    hour = new_time.hour;
    minute = new_time.minute;
    second = new_time.second;
    print();
    return;
}

// Functions
void Time::print() const{
    std::cout << hour << ':' << minute << ':' << second << std::endl;
}

double Time::convertToSeconds () const {
    double seconds = hour * 3600;
    seconds += minute * 60;
    seconds += second;
    return seconds;
}

Time Time::add(const Time& t2) const{
    double total_secs = convertToSeconds() + t2.convertToSeconds();
    Time new_time (total_secs);
    return new_time;
}

int main(){
    // Time a = {2, 30, 20.1};
    Time a (5000.0);
    Time b (10, 20, 10.1);
    // a.print();
    // std::cout << a.convertToSeconds() << std::endl;
    a.print();
    a.increment(200.0);
    b.print();
    return 1;
}