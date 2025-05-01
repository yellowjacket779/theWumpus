/*
** Program Filename: baby_wumpus.cpp
** Author: Jackson Bennett 
** Date: 11/25/2024 
** Description: This file contains the implementation of the baby_wumpus class, which is  derived from the event class.
** Input: None 
** Output: Prints out b if in debug mode. Also handles all logic in the same room.
*/
#include "baby_wumpus.hpp"

using std::cout;
using std::endl;

bool baby_wumpus:: encounter(int& a) const {
        int d;
        d = (rand()%100) + 1;
        if(d < 51){
            cout << "You got extremely lucky adventurer. You walked into a room with a baby wumpus. I advise moving out of this location  ASAP" << endl;
            a = 1000;

        }
        else if(d > 51){
            a = 1;
        }
    return false;
};

void baby_wumpus::print() const {
    std::cout << "b";
};
void baby_wumpus::percepts() const{
    cout << "You feel like youre being watched." << endl;
}
// TODO Wumpus implementation (define wumpus member functions below)
