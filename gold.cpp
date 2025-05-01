/*********************************************************************
** Program Filename: Gold.cpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: The Gold class represents an item that can be encountered in the game. It provides functionality to handle encounters with the player, print the representation of the Gold, and offer percepts to the player when they are near it.
** Input: None
** Output: Prints out G if in debug mode. Also handles all logic in the same room.
*********************************************************************/
#include "gold.hpp"

// TODO Gold implementation (define gold member functions below)
using std::cout;
using std::endl;

bool Gold:: encounter(int& a) const {
    a = 4;
    cout << "You found gold! Either kill the Wumpus or escape safely" << endl;
    return true;
};

void Gold::print() const {
    std::cout << "G";
};

void Gold::percepts() const{
    cout << "You stub your toe on something heavy." << endl;
}