/*********************************************************************
** Program Filename: escape_rope.hpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: It provides functionality to handle the encounter, print a representation of the escape rope, and give percepts when the player is near it.
** Input: None
** Output:none
*********************************************************************/
#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP
#include "event.hpp"

// TODO Escape rope interface (define the escape_rope class and declare its
// member functions below)
class Escape_rope : public event{
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
    ** Description: prints out E
    ** Parameters: none
    ** Pre-Conditions: escape rope exist and has not yet been removed
    ** Post-Conditions: E is printed
    */ 
    void print() const;
    /*
    ** Function:percepts
    ** Description: here to make sure arrow doesnt become abstract class.
    ** Parameters: none
    ** Pre-Conditions: escape rope exist and has not yet been removed
    ** Post-Conditions:none
    */    
    void percepts() const;
};

#endif
