
/*********************************************************************
** Program Filename: Flashlight.hpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: This file defines the Flashlight class, which is derived from the event class. The Flashlight class represents an item in the game that the player can encounter. It provides functionality to handle the encounter, print a representation of the flashlight, and define the percepts when the player is near it.
** Input: None 
** Output: None
*********************************************************************/
#ifndef FLASHLIGHT_HPP
#define FLASHLIGHT_HPP

#include <iostream>
#include "event.hpp"
class flashlight : public event {
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
    ** Description: prints out F
    ** Parameters: none
    ** Pre-Conditions: flashlight exist and has not yet been removed
    ** Post-Conditions: F is printed
    */ 
    void print() const;
    /*
    ** Function:percepts
    ** Description: here to make sure flashlight doesn't become abstract class.
    ** Parameters: none
    ** Pre-Conditions: flashlight exist and has not yet been removed
    ** Post-Conditions:none
    */ 
    void percepts() const;
    
};
// TODO Bat Swarm interface (define the bat_swarm class and declare its member
// functions below)


#endif