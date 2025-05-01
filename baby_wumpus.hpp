/********************************************************************* 
** Program Filename: baby_wumpus.hpp
** Author: Jackson Bennett 
** Date: 11/25/2024 
** Description: 
** This file contains the declaration of the baby_wumpus class, which is derived 
** from the event class. 
** Input: None
** Output: None
*********************************************************************/ 
#ifndef BABY_WUMPUS
#define BABY_WUMPUS
#include "event.hpp"

class baby_wumpus : public event {
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
    ** Description: arrow prints out A
    ** Parameters: none
    ** Pre-Conditions: Arrow exist and has not yet been removed
    ** Post-Conditions: A is printed
    */ 
    void print() const;
    /*
    ** Function:percepts
    ** Description: here to make sure arrow doesnt become abstract class.
    ** Parameters: none
    ** Pre-Conditions: arrow exist and has not yet been removed
    ** Post-Conditions:prints out You feel like you’re being watched.
    */ 
    void percepts() const;

};
// TODO Wumpus interface (define the wumpus class and declare its member
// functions below)
#endif
