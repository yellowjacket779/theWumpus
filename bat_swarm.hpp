/*********************************************************************
** Program Filename: bat_swarm.hpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: The class provides functionality to handle the encounter, print a representation of the swarm, and give percepts when the player is near it.
** Input: None (this is a header file for the Bat_swarm class).
** Output:
*********************************************************************/
#ifndef BAT_SWARM_HPP
#define BAT_SWARM_HPP

#include <iostream>
#include "event.hpp"

class Bat_swarm : public event {
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
    ** Description: prints out B
    ** Parameters: none
    ** Pre-Conditions: Bat_swarm exist and has not yet been removed
    ** Post-Conditions: B is printed
    */ 
    void print() const;
     /*
    ** Function:percepts
    ** Description: here to make sure arrow doesnt become abstract class.
    ** Parameters: none
    ** Pre-Conditions: Bat_swarm exist and has not yet been removed
    ** Post-Conditions: prints out You hear screeching.
    */ 
    void percepts() const;
    
};
// TODO Bat Swarm interface (define the bat_swarm class and declare its member
// functions below)


#endif
