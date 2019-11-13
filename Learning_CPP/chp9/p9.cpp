#include <iostream>

struct Time{
    int hour, minute;
    double seconds;
};

Time makeTime(double seconds){
    Time time;
    time.hour = int(seconds / 3600);
    time.minute = int((seconds - (time.hour * 3600)) / 60);
    time.seconds = seconds - time.hour * 3600 - time.minute * 60;
    return time;
}

double convertSeconds(Time time){
    double total_seconds = time.hour * 3600 + time.minute * 60 + time.seconds;
    return total_seconds;
}

Time addTime(const Time& t1, const Time& t2){
    double total_seconds = convertSeconds(t1) + convertSeconds(t2);
    return makeTime(total_seconds);
}

int main(){
    Time t1 = makeTime(5000);
    Time t2 = makeTime(1000);
    // std::cout << time.minute << std::endl;
    // std::cout << convertSeconds(time) << std::endl;
    std::cout << addTime(t1, t2).minute << std::endl;
    return 1;
}