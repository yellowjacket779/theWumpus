/*********************************************************************
** Program Filename: bottomless_pit.hpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: This file declares the bottomless_pit class, which represents an event in the game where the player encounters a bottomless pit. The class provides functionality to handle the encounter, print a representation of the pit, and give percepts when the player is near it.
** Input: None
** Output:none
*********************************************************************/
#ifndef BOTTOMLESS_PIT_HPP
#define BOTTOMLESS_PIT_HPP

#include <iostream>
#include "event.hpp"


class bottomless_pit : public event {
    private:
    int max;
    int min;
    bool isdead;

    public :
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
    ** Description: prints out B
    ** Parameters: none
    ** Pre-Conditions: Bottomless pit exist and has not yet been removed
    ** Post-Conditions: P is printed
    */ 
    void print() const;
    /*
    ** Function:percepts
    ** Description: Called when near the bottomless_pit and give the player a hint that they are near an objects
    ** Parameters: none
    ** Pre-Conditions: bottomless pit exist and has not yet been removed
    ** Post-Conditions: prints out You feel a breeze.
    */ 
    void percepts() const;

};



#endif
