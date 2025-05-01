/*********************************************************************
** Program Filename: Gold.hpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: The Gold class represents an item that can be encountered in the game. It provides functionality to handle encounters with the player, print the representation of the Gold, and offer percepts to the player when they are near it.
** Input: None
** Output: none
*********************************************************************/

#ifndef GOLD_HPP
#define GOLD_HPP
#include <iostream>
#include "event.hpp"

// TODO Gold interface (define the gold class and declare its member functions
// below)
class Gold : public event {
    public:
    /*
    ** Function:encounter
    ** Description:arrow encounter
    ** Parameters: a: does the following action game.
    ** Pre-Conditions: player has not grabbed this arrow yet.
    ** Post-Conditions:player now has another arrow
    */ 
    bool encounter(int& a) const;
    /*
    ** Function:print
    ** Description: arrow prints out A
    ** Parameters: 
    ** Pre-Conditions: Gold exist and has not yet been removed
    ** Post-Conditions: G is printed
    */ 
    void print() const;
    /*
    ** Function:percepts
    ** Description: Called when near the Gold and give the player a hint that they are near an objects.
    ** Parameters: none
    ** Pre-Conditions: Gold exist and has not yet been removed
    ** Post-Conditions: prints out You stub your toe on something heavy.
    */ 
    void percepts() const;
};

#endif
