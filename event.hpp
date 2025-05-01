
/*********************************************************************
** Program Filename: event.hpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: This is an abstract class that serves as the base class for various event types in the game. It provides pure virtual functions that all derived classes (such as Gold, Flashlight, etc.)
** Input: None
** Output: None
*********************************************************************/
#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>

// Event interface
class event{
private:
	// TODO private members, if relevant
protected:
	// TODO protected members, if relevant
public:
    /*
    ** Function:encounter
    ** Description:the abstract class function to be inherited by every class
    ** Parameters: a: does the following action game.
    ** Pre-Conditions:none
    ** Post-Conditions:none
    */ 
	virtual bool encounter(int& a) const = 0;
    /*
    ** Function:print
    ** Description:the abstract class function to be inherited by every class
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    */ 
	virtual void print()const = 0;
   	/*
    ** Function:percepts
    ** Description:the abstract class function to be inherited by every class
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions:none
    */ 
	virtual void percepts()const = 0;
	virtual  ~event()= default;
	// TODO: public members
};

#endif
