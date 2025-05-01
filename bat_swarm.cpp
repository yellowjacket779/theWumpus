/*********************************************************************
** Program Filename: Bat_swarm.cpp
** Author: [Your Name]
** Date: [Date of Creation]
** Description: This file contains the implementation of the Bat_swarm class, which is derived from the event class.
** Input: none
** Output: Prints out B if in debug mode. Also handles all logic in the same room.
*********************************************************************/
#include "event.hpp"
#include "bat_swarm.hpp"
using std::cout;
using std::endl;

bool Bat_swarm:: encounter(int& a) const {
a = 5;
    cout << "You walked into a bat swarm" << endl;
return false;
};

void Bat_swarm::print() const {
    cout << "B";
};
void Bat_swarm::percepts() const{
    cout << "You hear screeching." << endl;
}
// TODO Bat Swarm implementation (define bat_swarm member functions below)
