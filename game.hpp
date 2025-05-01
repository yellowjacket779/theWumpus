/********************************************************************* 
** Program Filename: game.hpp
** Author: jJackson Bennett
** Date: 11/25/2024
** Description: Header file defining the 'game' class and associated functions for a text-based adventure game where the player navigates a grid, encounters events, and attempts to survive various challenges (such as a Wumpus, bats, and gold). The game features elements such as movement, shooting arrows, flashlight discovery, and more.
** Input: Game grid dimensions (width, height), player actions (movement, shooting arrows, etc.)
** Output: Text-based game output displayed in the terminal, including game state, events, and percepts of nearby rooms.
*********************************************************************/


#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "room.hpp"
using std::vector;

struct player{
	bool flashlights;
	bool gold;
	bool confuse;
};
// game interface
class game {
private:
	// TODO declare a 2D vector of Room objects:
	vector<vector<Room> > lavectora;
	// Suggested member variables:
	int num_arrows; 	// keep track of number of arrows remaining
	int width;				// width of the game grid
	int height;				// height of the game grid
	bool debug;				// debug mode or not
	int locationx;
	int locationy;
	//bool gold;
	//bool confuse;
	int xwumpus;
	int ywumpus;
	bool wumpusisdead;
	player p;
	//bool flashlights;

	// TODO Feel free to add more member variables if you'd like


public:


	/*
	* Function: hitwumpus
	* Description:check if the player has hit the wumpus
	* Parameters:
	* 		x : Current x of traveling arrow
	* 		y : Current y of travling arrow
	* Post-Conditions:return if the arrow hit the wumpus or not.
	*/
	void hitwumpus(int x, int y);

	/*
	* Function: helperofsetter
	* Description:checks if the room is empty
	* Parameters:
	* 		width : Width of the grid
	* 		height : Height of the grid
	* 		event* e : a event pointer that is pointing to the event held in a Room.
	* Returns indiviual event in the cave.
	*/
	void helperofsetter(int height, int width, int& i, int& j, int& playlocate);
	/*
	* Function: flashlight_found
	* Description: is activated when player walk into room with flashlight
	* Parameters: none
	* Return flashlight as true and player can now see events that are in there row or colum
	*/
	void flashlight_found();

	/*
	* Function: hasflashlight
	* Description: is activated when flashlight is true
	* Parameters: 
			 i: is the y cordinate in the current display function.
			 j: is the x cordinate in the current display function.
	* Prints out event that are present in a players row and colum 
	*/
	void hasflashlight(int i, int j)const;

	/*
	* Function: releasethebabies
	* Description: Create new objects in the vector that are baby wumpusi. This is only activated after 15 turns
	* Parameters: none
	* Return 3 new baby wumpusi in the vector. These act like the bottomless pit and have a 50% chance of killing the player
	*/
	void releasethebabies();

	/*
	* Function: arrow_setter
	* Description: Create new objects in the vector that are baby wumpusi. This is only activated after 15 turns
	* Parameters: 
	*	arrowlocationy: the y location where the arrow was dropped.
	*	arrowlocationx: he x location where the arrow was dropped.
	*	event* e:  contains the arrow event and is helpful to in event into a second function if xy location is full
	* Precondition: player has shot arrow
	* Postcondition; new arrow event is created. 
	*/
	void arrow_setter(int, int, event* e);

	/**
	** Function:help_display
	** Description: Help to display the game board
	** Parameters:
	*	i: the current y location in the vector
	*	j: the current x location in the vector
	** Pre-Conditions: i and j have been declared and are running properly.
	** Post-Conditions: prints the player a space or the object in the vector if in debug mode or has flashlight is true
	**/
	void help_display(int, int) const;

	/*
	** Function: wumpus_dead
	** Description:Set wumpus to dead if player has successfully hit the wumpus with an arrow
	** Parameters: none
	** Pre-Conditions: player has hit the wumpus.
	** Post-Conditions: Game is over and the game congratlates wumpus
	*/ 

	void wumpus_dead();
	/*
	** Function: set_wumpus
	** Description: Works just like the locationsetters function but recorded specifically the wumpus location.
	** Parameters: 
	*	height; The height of the vector
	*	width; The width of the vector 
	*	event* e; a event pointer
	** Pre-Conditions: players location has not been set or the player has just shot an arrow and missed.
	** Post-Conditions: new location is set for the wumpus
	*/ 
	void set_wumpus(int height, int width, event* e);

	/*
	** Function: randmove
	** Description: move player in direction. up down left or right.
	** Parameters:
	*	confused: player must walk into a bat swarm to make this true.
	** Pre-Conditions: player walked into a bat swarm
	** Post-Conditions: move player in random direction
	*/ 
	void randmove();

	/*
	** Function: tick
	** Description: set confused to false
	** Parameters:none
	** Pre-Conditions: none.
	** Post-Conditions: set confused to false. happens after every turn.
	*/ 
	void tick();
	
	/*
	** Function: confused
	** Description: set confused to false
	** Parameters:none
	** Pre-Conditions: none.
	** Post-Conditions: set confused to false. happens after every turn.
	*/ 
	void confused();

	/*
	** Function: goldfound
	** Description: set gold to true
	** Parameters:none
	** Pre-Conditions: gold is set to false.
	** Post-Conditions: Set gold to true and give the player the ability to win the game by finding the escape rope.
	*/ 
	void goldfound();

	/*
	** Function: Eventupdown
	** Description: check if there is an event above and below the player.
	** Parameters:none
	** Pre-Conditions: player is near an event. Otherwise nothing will print out.
	** Post-Conditions: Prints out corsponding percepts for event that is above or below the player
	*/ 
	void Eventupdown();

	/*
	** Function: Eventleftright
	** Description: check if there is an event left and right the player.
	** Parameters:none
	** Pre-Conditions: player is near an event. Otherwise nothing will print out.
	** Post-Conditions: Prints out corsponding percepts for event that is left or right the player
	*/ 
	void Eventleftright();

	/*
	** Function: Events
	** Description: print if there is an event around the player
	** Parameters:none
	** Pre-Conditions: player is near an event. Otherwise nothing will print out.
	** Post-Conditions: Prints out corsponding percepts for event that is around player
	*/ 
	void Events();

	/*
	** Function: trigger_encounter
	** Description: does the corrospoding action to the player class or the game class
	** Parameters:none
	** Pre-Conditions: if player is inside of an event 
	** Post-Conditions: does the correspoding action from the event.
	*/ 
	void trigger_encounter();
	
	// Suggested functions (there are no required functions here):
	/*
	* Function: setevents
	* Description: Set all game element to random location in the cave
	* Parameters:
	*	lavectora: vector of the cave
	*	height : height of the cave
	*	width : width of the cave
	* Returns cave with events
	*/
	void setevents(int height, int length);
	/*
	* Function: locationsetters
	* Description: Creates event in the lavectora. Just a helper function
	* Parameters:
	*	width: Width of the grid
	*	height: Height of the grid
	*	event* e : a event pointer that is pointing to the event held in a Room.
	* Returns indiviual event in the cave.
	*/
	void locationsetters(int height, int length, event* e);

	/*
	* Function: Constructor
	* Description: Constructs game object with a grid matching the given width and height
	* Parameters:
	*	width: Width of the grid
	*	height: Height of the grid
	*	debug: Whether or not debug mode should be enabled
	*/
	game(int width, int height, bool debug);

	/*
	* Function: display_game
	* Description: Displays the game grid in the terminal
	*/
	void display_game() const;

	/*
	* Function: check_win
	* Description: Determines whether the player has won the game
	* Returns: True if the player has won, false otherwise
	*/
	bool check_win() const;

	/*
	* Function: check_lose
	* Description: Determines whether the player has lost the game
	* Returns: True if the player has lost, false otherwise
	*/
	bool check_lose() const;

	/*
	* Function: is_direction
	* Description: Returns true if the given character is a valid direction character (w/a/s/d) and false otherwise
	* Parameters:
	*	c (char): The character to check
	* Returns (bool): Boolean indicating whether the character is a valid direction character (w/a/s/d)
	*/
	bool is_direction(char c);

	/*
	* Function: to_lower
	* Description: Converts a given character to lowercase. Used to standardize
	* 		a user's character input.
	* Parameters:
	*	direction (char): Character to convert to lowercase
	* Returns (char): Character converted to lowercase
	*/
	char to_lower(char direction);

	/*
	* Function: can_move_in_direction
	* Description: Determines whether the player can move in the given direction, based on their current location and the size of the grid.
	* Parameters:
	*	direction (char): Direction the player wishes to move in
	* Returns (bool): True if the player can move in the given direction without moving off the grid. False otherwise.
	*/
	bool can_move_in_direction(char direction);

	/*
	* Function: is_valid_action
	* Description: Determines whether the given action is valid.
	* Parameters:
	*	action (char): Action the player wishes to perform.
	* Returns (bool): True if the requested action is valid. False otherwise.
	*/
	bool is_valid_action(char action);

	/*
	* Function: print_action_error
	* Description: Prints a clear error message associated with the user's provided invalid action
	* Parameters:
	*	action (char): Invalid action that the user requested
	*/
	void print_action_error(char action);

	/*
	* Function: get_player_action
	* Description: Prompts the player for their action for the turn and returns it as a char (w, a, s, d, or f). If the player enters an invalid action, this function reprompts until a valid one is provided.
	* Returns (char): The valid action provided by the player.
	*/
	char get_player_action();

	/*
	* Function: get_arrow_fire_direction
	* Description: Prompts the player for the direction they want to fire an arrow (w, a, s, or d) and returns it as a char. If the player enters an invalid direction, this function reprompts until a valid one is provided.
	* Returns (char): The valid direction provided by the player.
	*/
	char get_arrow_fire_direction();

	/*
	* Function: move_up
	* Description: Moves the player up one grid space
	* Pre-condition: Player is capable of moving in this direction (without
	* 		hitting the edge of the board)
	* Post-condition: Player is moved accordingly.
	*/
	void move_up();

	/*
	* Function: move_down
	* Description: Moves the player down one grid space
	* Pre-condition: Player is capable of moving in this direction (without hitting the edge of the board)
	* Post-condition: Player is moved accordingly.
	*/
	void move_down();

	/*
	* Function: move_left
	* Description: Moves the player left one grid space
	* Pre-condition: Player is capable of moving in this direction (without hitting the edge of the board)
	* Post-condition: Player is moved accordingly.
	*/
	void move_left();

	/*
	* Function: move_right
	* Description: Moves the player right one grid space
	* Pre-condition: Player is capable of moving in this direction (without hitting the edge of the board)
	* Post-condition: Player is moved accordingly.
	*/
	void move_right();

	/*
	* Function: move
	* Description: Moves the player in the direction specified by the given
	* 		character
	* Parameters:
	* 		direction (char): Direction in which to move the player (a for west, s for south, d for east, w for north).
	* Pre-condition: Player is capable of moving in this direction (without hitting the edge of the board)
	* Post-condition: Player is moved accordingly.
	*/
	void move(char direction);

	/*
	* Function: fire_arrow_up
	* Description: Fires an arrow upward
	* Post-condition: Arrow is fired upward. Wumpus is killed if hit / moves if missed.
	*/
	void fire_arrow_up();

	/*
	* Function: fire_arrow_down
	* Description: Fires an arrow downward
	* Post-condition: Arrow is fired downward. Wumpus is killed if hit / moves if missed.
	*/
	void fire_arrow_down();

	/*
	* Function: fire_arrow_left
	* Description: Fires an arrow leftward
	* Post-condition: Arrow is fired leftward. Wumpus is killed if hit / moves if missed.
	*/
	void fire_arrow_left();

	/*
	* Function: fire_arrow_right
	* Description: Fires an arrow rightward
	* Post-condition: Arrow is fired rightward. Wumpus is killed if hit / moves if missed.
	*/
	void fire_arrow_right();

	/*
	* Function: fire_arrow
	* Description: Fires an arrow in the direction specified by the given character
	* Parameters:
	*	direction (char): Direction in which to fire arrow (a for west, s for south, d for east, w for north).
	* Post-condition: Arrow is fired. Wumpus is killed if hit and moves if
	* 		missed.
	*/
	void fire_arrow(char direction);

	/*
	* Function: play_game
	* Description: Runs one full iteration of the game
	*/
	void play_game();//game& p

	/*
	* Function: get_locationx
	* Description: gets x loction of player
	* Post-condition:return player locationx
	*/
	int get_locationx() const;

	/*
	* Function: get_locationx
	* Description: gets y loction of player
	* Post-condition:return player locationy
	*/
	int get_locationy() const;
	};

	#endif
