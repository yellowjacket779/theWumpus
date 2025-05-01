/*********************************************************************
** Program Filename: Room.hpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: This file contains the declaration of the Room class, which represents a room in a game. The Room class holds an event that can affect the player's experience in the room. It provides functions to interact with the event, including setting, checking, and removing the event. The class also offers functions to print the event, handle percepts, and process encounters.
** Input: none
** Output: None 
*********************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP
#include <vector>
#include "event.hpp"

// Room interface
class Room {
private:
	// TODO private members
    event* thyevents;
public:    
    /*
    ** Function: Room
    ** Description: Default constructor that initializes thyevents to nullptr
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The Room object is created with thyevents set to nullptr
    */
    Room();

    /*
    ** Function: ~Room
    ** Description: Destructor that deletes the thyevents object and sets it to nullptr if it exists
    ** Parameters: None
    ** Pre-Conditions: The Room object may or may not have a thyevents object assigned
    ** Post-Conditions: If the thyevents object exists it is deleted and set to nullptr
    */
    ~Room();

    /*
    ** Function: Room& Room
    ** Description: Assignment operator that copies the thyevents object from another Room object ensuring no self-assignment occurs
    ** Parameters: const Room& other: The Room object whose thyevents is to be copied
    ** Pre-Conditions: other is a valid Room object and its thyevents may or may not be null
    ** Post-Conditions: The current Room object will have its thyevents replaced with a deep copy of other's thyevents
    */
    Room(const Room& other);

     /*
    ** Function: Room(const Room& other)
    ** Description: Copy constructor that creates a deep copy of the thyevents object from another Room object
    ** Parameters: const Room& other: The Room object to be copied
    ** Pre-Conditions: other is a valid Room object and its thyevents may or may not be null
    ** Post-Conditions: The current Room object will have its thyevents set to a deep copy of other's thyevents (if it exists)
    */
    Room& operator=(const Room& other);

    /*
    ** Function: print() const
    ** Description: Prints the event associated with the room if it exists; otherwise prints a blank space
    ** Parameters: None
    ** Pre-Conditions: The Room object may or may not have an event (thyevents) assigned
    ** Post-Conditions: Prints either the event details or a blank space
    */
    void print()const;

    /*
    ** Function: set_event
    ** Description: Sets the event of the room to the given event pointer
    ** Parameters: event* e: A pointer to an event object to be assigned to thyevents
    ** Pre-Conditions: The e pointer must be a valid event object
    ** Post-Conditions: The thyevents pointer will be assigned to e
    */
    void set_event(event*);

    /*
    ** Function: checktheroom
    ** Description: Checks if the room has an event and updates the integer reference accordingly
    ** Parameters: int& a: A reference to an integer that will be updated based on whether thyevents is null
    ** Pre-Conditions: thyevents may or may not be assigned
    ** Post-Conditions: The integer a will be set to 1 if thyevents is null or 0 if it is not
    */
    void checktheroom(int& a);

    /*
    ** Function: percepts
    ** Description: Calls the percepts function of the thyevents object if it exists
    ** Parameters: None
    ** Pre-Conditions: thyevents may or may not be assigned
    ** Post-Conditions: If thyevents exists its percepts function is called
    */
    void percepts();

    /*
    ** Function: Powumpus
    ** Description: Calls the encounter function of the thyevents object if it exists and passes the integer reference
    ** Parameters: int& a: A reference to an integer passed to encounter
    ** Pre-Conditions: thyevents may or may not be assigned
    ** Post-Conditions: If thyevents exists its encounter function is called with the reference integer
    */
    void Powumpus(int& a) const;

    /*
    ** Function: removethyevent
    ** Description: Deletes the event associated with the room and sets thyevents to nullptr
    ** Parameters: None
    ** Pre-Conditions: thyevents may or may not be assigned
    ** Post-Conditions: If thyevents exists it is deleted and set to nullptr
    */
    void removethyevent();

    /*
    ** Function: encounters
    ** Description: Checks if the room's event has an encounter with a specified integer value
    ** Parameters: int& a: A reference to an integer passed to encounter for checking
    ** Pre-Conditions: thyevents may or may not be assigned
    ** Post-Conditions: Returns true if an encounter occurs otherwise false
    */
    bool encounters(int& a);
};

#endif
