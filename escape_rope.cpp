/*********************************************************************
** Program Filename: escape_rope.cpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: this class provides the behavior for what happens when the player encounters the rope, how it is printed, and percepts that give hints.
** Input: None
** Output: prints out Eif in debug mode. Also handles all logic in the same room.
*********************************************************************/
#include "escape_rope.hpp"
#include <iostream>

// TODO Escape rope implementation (define escape_rope member functions below)
using std::cout;
using std::endl;

bool Escape_rope:: encounter(int& a) const{
    a = 6;
return false;
};

void Escape_rope::print() const {
    std::cout << "E";
};
void Escape_rope::percepts() const{
    
}