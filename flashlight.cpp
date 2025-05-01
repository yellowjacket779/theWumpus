/*********************************************************************
** Program Filename: Flashlight.cpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: This file contains the implementation of the Flashlight class, which is derived from the event class. The Flashlight class represents an item that the player can encounter in the game. It provides functionality to handle the encounter, print a representation of the flashlight, and define percepts when the player is near it.
** Input: None 
** Output: prints out f if in debug mode
*********************************************************************/
#include "flashlight.hpp"

// TODO flashlight implementation (define flashlight member functions below)
using std::cout;
using std::endl;

bool flashlight:: encounter(int& a) const {
    a = 10000;
    return true;
};

void flashlight::print() const {
    std::cout << "F";
};

void flashlight::percepts() const{

}