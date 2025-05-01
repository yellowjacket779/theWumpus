/*
** Program Filename: Arrow.cpp
** Author: Jackson Bennett 
** Date: 11/25/2024 
** Description: 
** This file contains the implementation of the Arrow class, which is derived from the event class.
** Input: None
** Output: Prints out A if in debug mode. Also handles all logic in the same room.
*/ 
#include "arrow.hpp"

using std::cout;
using std::endl;
bool Arrow:: encounter(int& a) const {
    a = 2;
    cout <<"You found an arrow. This can be used to kill the Wumpus. Good luck adventurer" << endl;
    return true;
};

void Arrow::print() const {
    std::cout << "A";
};
void Arrow::percepts() const{

}
// TODO Arrow implementation (define arrow member functions below)
