/********************************************************************* 
** Program Filename: Arrow.hpp
** Author: Jackson Bennett 
** Date: 11/25/2024 
** Description: This class provides functionality to handle the encounter with the arrow, print its symbol, and give percepts when the player is near it. The Arrow class is essential for managing arrow objects that players can collect and use.
** Input: None 
** Output: Prints out A if in debug mode. Also handles all logic in the same room.
*********************************************************************/ 
#ifndef ARROW_HPP
#define ARROW_HPP
#include <iostream>
#include "event.hpp"
// TODO Arrow interface (define the arrow class and declare its member functions
// below)
class Arrow : public event{
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
    ** Pre-Conditions: Arrow exist and has not yet been removed
    ** Post-Conditions: A is printed
    */ 
    void print() const;
     /*
    ** Function:percepts
    ** Description: here to make sure arrow doesnt become abstract class.
    ** Parameters: none
    ** Pre-Conditions: arrow exist and has not yet been removed
    ** Post-Conditions:none
    */ 
    void percepts() const;
};

#endif
