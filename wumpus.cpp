/*********************************************************************
** Program Filename: Wumpus.cpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: This class provides the behavior for what happens when the player encounters the wumpus, how it is printed, and percepts that give hints.
** Input: None
** Output: prints out W if in debug mode. Also handles all logic in the same room.
*********************************************************************/
#include "wumpus.hpp"

using std::cout;
using std::endl;

bool Wumpus:: encounter(int& a) const {
a = 1;
    return false;
};

void Wumpus::print() const {
    std::cout << "W";
};
void Wumpus::percepts() const{
    cout << "The hairs stand up on the back of your neck." << endl;
}
// TODO Wumpus implementation (define wumpus member functions below)

