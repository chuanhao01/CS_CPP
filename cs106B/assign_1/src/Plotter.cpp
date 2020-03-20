#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    (void) input;
    PenStyle pen = {1, "black"};
    float x = 0, y = 0;
    // Bool position false -> up, true -> down
    bool position = false;
    for (string line; getline(input, line); ) {
        Vector<string> args = stringSplit(line, " ");
        string command = args[0];
        command = toLowerCase(command);
        args.remove(0);
//        cout << line << endl;
//        cout << command << endl;
//        cout << args.toString() << endl;
//        cout << "x: " << x << " | y: " << y << endl;
//        cout << endl;
        // Check for command and then change accordingly
        if(command == "pendown"){
            position = true;
        }
        else if(command == "penup"){
            position = false;
        }
        else if(command == "moveabs"){
            float new_x = stof(args[0]), new_y = stof(args[1]);
            if(position){
                drawLine(x, y, new_x, new_y, pen);
            }
            x = new_x;
            y = new_y;
        }
        else if(command == "moverel"){
            float new_x = x + stof(args[0]), new_y = y + stof(args[1]);
            if(position){
                drawLine(x, y, new_x, new_y, pen);
            }
            x = new_x;
            y = new_y;
        }
        else if(command == "pencolor"){
            pen.color = args[0];
        }
        else if(command == "penwidth"){
            pen.width = stof(args[0]);
        }
    }
    return;
}
