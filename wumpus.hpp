/*********************************************************************
** Program Filename: Wumpus.hpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: This class provides the behavior for what happens when the player encounters the wumpus, how it is printed, and percepts that give hints.
** Input: None
** Output: none
*********************************************************************/
#ifndef WUMPUS_HPP
#define WUMPUS_HPP
#include "event.hpp"

class Wumpus : public event {
    public:
    /*
    ** Function:encounter
    ** Description:arrow encounter
    ** Parameters: a: does the following action game.
    ** Pre-Conditions: player has not grabbed this arrow yet.
    ** Post-Conditions:player now has another arrow
    */ 
    bool  encounter(int& a) const;
    /*
    ** Function:print
    ** Description: Prints out W
    ** Parameters: 
    ** Pre-Conditions: Wumpus exist
    ** Post-Conditions: W is printed
    */ 
    void print() const;
    /*
    ** Function:percepts
    ** Description: Called when near the wumpus and give the player a hint that they are near an objects
    ** Parameters: none
    ** Pre-Conditions: wumpus exist and has not yet been removed
    ** Post-Conditions: prints out The hairs stand up on the back of your neck.
    */ 
    void percepts() const;

};
// TODO Wumpus interface (define the wumpus class and declare its member
// functions below)
#endif
