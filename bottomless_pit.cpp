/*
** Program Filename: bottomless_pit.cpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: It provides behavior for the encounter, how it is printed, and percepts that give hints when the player is near it.
** Input: 
** Output: Prints out p if in debug mode. also hands the logic if player enter a room with a pit class 
*/
#include <iostream>
#include "event.hpp"
#include "bottomless_pit.hpp"

using std::cout;
using std::endl;

// TODO Bottomless Pit implementation (define bottomless_pit member functions
// below)

bool bottomless_pit:: encounter(int& a) const {
    int d = 0;
    if(a != 3 && a != 0)
    d = (rand()%100) + 1;
    if(d < 51){
        cout << "You got extremely lucky adventurer and notice at the last second notice that there is bottomeless pit. I advise moving out of this location" << endl;
        a = 0;
    }
    else if(d > 51){
        a = 3;
        cout << "here dead" << endl;
    }
    return false;
};

void bottomless_pit::print() const {
    cout << "P";
};

void bottomless_pit::percepts() const{
    cout << "you feel a breeze." << endl;
}
