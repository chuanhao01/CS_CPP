#include <iostream>

// Declaring enum tyoes
enum weekdayT {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

// Decalring and initialising functions
weekdayT nextDay(weekdayT day){
    weekdayT next_day = weekdayT((day + 1) % 7);
    return next_day;
}

weekdayT previousDay(weekdayT day){
    weekdayT previous_day = weekdayT((day - 1 + 7) % 7);
    return previous_day;
}

weekdayT incrementDay(const weekdayT &day, int delta){
    weekdayT final_day;
    delta = delta % 7;
    if(delta != 0){
        // If delta is not 0
        final_day = weekdayT((day + 7 + delta) % 7);
    }
    else{
        // If delta is 0
        final_day = day;
    }
    return final_day;
}

int main(){
    weekdayT day = Monday;
    day = incrementDay(day, 0);
    std::cout << day << std::endl;
    return 1;
}