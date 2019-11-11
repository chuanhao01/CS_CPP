#include <iostream>
#include <cmath>

struct Point{
    double x, y;
};

struct Rectangle{
    Point corner;
    double width, height;    
};

void changePoint(Point& a){
    a.x = 10.0;
    return;
}

double distance(Point p1, Point p2){
    double x_d = p2.x - p1.x;
    double y_d = p2.y - p1.y;
    return std::sqrt((x_d * x_d) + (y_d * y_d));
}

void printPoint(Point p){
    std::cout << p.x << p.y << std::endl;
    return;
}

Point findCenter (Rectangle box){
    double cx = box.corner.x + (box.width / 2);
    double cy = box.corner.y - (box.height / 2);
    Point center = {cx, cy};
    return center;
}

int main(){
    // Point a = {3.0, 4.0};
    Point b = {0.0, 0.0};
    Rectangle box = {b, 5.0, 10.0};
    Point a = findCenter(box);
    std::cout << findCenter(box).x << std::endl;
    // printPoint(b);
    // std::cout << distance(a, b) << std::endl;
    return 1;
}