
/*********************************************************************
** Program Filename: Room.cpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: This file includes the destructor, copy constructor, assignment operator, and other member functions that manage the events and interactions within a room.
** Input: takes in new events set puts them into a vector. 
** Output: Destructors the vector of rooms, also removes any events that should be removed when the player interacts with them. 
*********************************************************************/

#include "room.hpp"


using std::cout;
using std::endl;

Room::~Room(){
    if(this->thyevents != nullptr){
        delete thyevents;
        thyevents = nullptr;
    }
};

// Copy constructor: Deep copies the event object
Room::Room(const Room& other) : thyevents(nullptr) {
    if (other.thyevents) {
        // Deep copy: Create a new event object by copying the other event
        thyevents = other.thyevents;  // Assuming the event class has a clone() method for deep copy
        cout << "Copy Construtor" << endl;
    }
}

Room& Room::operator=(const Room& other) {
    if (this != &other) {  // Check for self-assignment
        // First, clean up any existing event in the current object
        delete thyevents;

        // Now, copy the event from the other Room object
        thyevents = nullptr;  // Ensure thyevents is set to nullptr before deep copy
        if (other.thyevents) {
            thyevents = other.thyevents;  // Deep copy the event object
            cout << "AOO" << endl;
        }
    }
    return *this;  // Return *this to allow chained assignment
}
// TODO Room implementation (define room member functions below)

Room::Room(){
    this->thyevents = nullptr;

}

void Room::print()const{
    if(this->thyevents != nullptr){
    this->thyevents->print();
    }
    else{
        cout << "  ";
    }
}
void Room::set_event(event* e) {
    this->thyevents = e;
}
void Room::checktheroom(int& a){
 if(this->thyevents == nullptr){
    a = 1;
 }
 else if(this->thyevents != nullptr) {
    a = 0;
 }
}

void Room::percepts(){
    if(this->thyevents != nullptr){
        this->thyevents->percepts();
    }
}
void Room::Powumpus(int& a)const {
    if(this->thyevents != nullptr){
        this->thyevents->encounter(a);
    }
}

void Room::removethyevent(){
    if(this->thyevents != nullptr){
        delete this->thyevents;
        thyevents = nullptr;
    }
}

bool Room::encounters(int& a){
    if(this->thyevents != nullptr){
        if(this->thyevents->encounter(a)){
            return true;
            cout << this->thyevents->encounter(a) << endl;
        }
        else{
            return false;
        }
    }
    return false;
};
