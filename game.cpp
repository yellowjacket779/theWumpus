/*********************************************************************
** Program Filename: game.cpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: This program simulates a Wumpus game where the player navigates a grid, avoids traps, and tries to defeat the Wumpus using arrows. The game includes various events like encountering gold, a flashlight, or bat swarms, and the player can move in different directions or fire arrows.
** Input: User inputs actions to move, fire arrows, or interact with events.
** Output: The game state is displayed, showing the player's current position, remaining arrows, and events in the game grid(only if the game is in debug mode or if player has flashlight). The program ends when the player wins, loses, or the Wumpus is killed.
*********************************************************************/

#include <iostream>


#include "game.hpp"
#include "gold.hpp"
#include "bat_swarm.hpp"
#include "bottomless_pit.hpp"
#include "wumpus.hpp"
#include "escape_rope.hpp"
#include "arrow.hpp"
#include "baby_wumpus.hpp"
#include "flashlight.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


void game::setevents(int height, int width)
{
	locationsetters(height, width, new bottomless_pit);
	locationsetters(height, width, new bottomless_pit);
	locationsetters(height, width, new Bat_swarm);
	locationsetters(height, width, new Bat_swarm);
	set_wumpus(height, width, new Wumpus);
	locationsetters(height, width, new Gold);
	locationsetters(height, width, new Escape_rope);
	locationsetters(height, width, new Arrow);
	locationsetters(height, width, new Arrow);
	locationsetters(height, width, new flashlight);

}

void game::set_wumpus(int height, int width, event* e){
	int i, j, a, playlocate;
		a = 1;
		do{
			helperofsetter(height, width, i, j, playlocate);
			this->lavectora.at(i).at(j).checktheroom(a);
		}while(a != 1);

		this->lavectora.at(i).at(j).set_event(e);
		this->xwumpus = j;
		this->ywumpus = i;
}
void game::arrow_setter(int arrowlocationy, int arrowlocationx, event* e){
	int a;
	a = 1;
	this->lavectora.at(arrowlocationy).at(arrowlocationx).checktheroom(a);
		if(a == 1){
			this->lavectora.at(arrowlocationy).at(arrowlocationx).set_event(e);
		}
		else{
				locationsetters(this->height, this->width, e);
		}
}

void game::helperofsetter(int height, int width, int& i, int& j, int& playlocate) {
			do{
			i = (rand()%height);
			j = (rand()%width);
			if(i == this->locationy){
				if(j == this->locationx){
					playlocate = 0;
				}
				else{
					playlocate = 1;
				}
			}
			else{
				playlocate = 1;
			}
			}while(playlocate != 1);
}

void game::locationsetters(int height, int width, event* e){
	int i, j, a, playlocate;
		a = 1;
		do{
			helperofsetter(height, width, i, j, playlocate);
			this->lavectora.at(i).at(j).checktheroom(a);
		}while(a != 1);

		this->lavectora.at(i).at(j).set_event(e);
}

game::game(int width, int height, bool debug) : width(width), height(height), debug(debug), xwumpus(0), ywumpus(0), wumpusisdead(false), num_arrows(0), p{false, false, false}
{
		get_locationy();
		this->locationy = (rand()%height);
		get_locationx();
		this->locationx = (rand()%width);
		//create an empty game board 
		std::vector<std::vector<Room> > temp_board(height, std::vector<Room> (width));
		this->lavectora = temp_board;
		setevents(height, width);

}

void game::hasflashlight(int i, int j)const{

	if(this->get_locationy() == i){
		this->lavectora.at(i).at(j).print();
	}

	else if((this->get_locationx() == j)){
		this->lavectora.at(i).at(j).print();
	}
	else{
		cout << " ";
	}

}
void game::help_display(int i, int j) const{
			if ((this->get_locationy() == i) and (this->get_locationx() == j)){
				cout << "* ";
				}
			else {
				if (!this->debug) {
						if(p.flashlights){
						hasflashlight(i, j);
						}
						else{
							cout << " ";
						}
						
				}
				else if(this->debug){
					this->lavectora.at(i).at(j).print();
				}
				cout << " ";
			}
			cout << "|| ";
}
void game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	string row_border = "--";
	for (int i = 0; i < this->width; ++i) {
		row_border += "-----";
	}
	cout << row_border << endl;
	for (int i = 0; i < this->height; ++i) {
		cout << "|| ";
		for (int j = 0; j < this->width; ++j) {
			help_display(i, j);
		}
		cout << endl;
		cout << row_border << endl;
	}
}

bool game::check_win() const{
	int a = 0;
	int i = this->locationy;
	int j = this->locationx;
	cout << "Checking position (" << i << ", " << j << ")" << endl; 
	//TODO: fix this
				this->lavectora.at(i).at(j).Powumpus(a);
				if(a == 6 && p.gold == true){
					return true;
				}
	return false;
}

bool game::check_lose() const{
	int a, i, j;
	a = 0;
	i = this->locationy;
	j = this->locationx;
	this->lavectora.at(i).at(j).Powumpus(a);
	if(a == 1){
	cout << "YOU RAN INTO THE WUMPUS. GAME OVER" << endl;
		return true;
	}
	else if(a == 3){
	cout << "You fell into a pit and died. Good try adventurer." << endl;
		return true;
	}
	return false;
}

bool game::is_direction(char c) {
	return c == 'w' ||
		c == 'a' ||
		c == 's' ||
		c == 'd';
}

char game::to_lower(char direction) {
	if (direction >= 'A' && direction <= 'Z') {
		return direction + ('a' - 'A');
	}
	return direction;
}

bool game::can_move_in_direction(char direction) {
	int wid, hig;
	wid = this->width;
	hig = this->height;
	if(!p.confuse){
		if (direction == 'a' && this->locationx <= 0) {
			return false; // Cannot move left; already at edge of board
		} else if (direction == 'd' &&  this->locationx == wid - 1) {
			return false; // Cannot move right; already at edge of board
		}
		if (direction == 'w' && this->locationy <= 0) {
			return false; // Cannot move left; already at edge of board
		} else if (direction == 's' && this->locationy == hig - 1) {
			return false; // Cannot move right; already at edge of board
		}
	}
	return true;
}

bool game::is_valid_action(char action) {
	if (this->is_direction(action)) {
		char direction = action;
		return this->can_move_in_direction(direction);
	} else if (action == 'f') {
		return this->num_arrows > 0;
	}
	return false;
}

void game::print_action_error(char action) {
	if (this->is_direction(action)) {
		cout << "Are you okay you just smacked into a wall? Try again and don't walk into a wall." << endl << endl;
		// cout << "You can't move in that direction!" << endl <<
		// 	endl;
	} else if (action == 'f') {
		cout << "You're out of arrows!" << endl << endl;
	} else {
		cout << endl << "That's an invalid input!" << endl
			<< endl;
	}
}

char game::get_player_action() {
	char action;
	bool first = true;
	do {
		if (!first) {
			char previous_action = action;
			this->print_action_error(previous_action);
		}
		first = false;

		cout << endl << endl << "What would you like to do?" <<
			endl << endl;
		cout << "w: move up" << endl;
		cout << "a: move left" << endl;
		cout << "s: move down" << endl;
		cout << "d: move right" << endl;
		cout << "f: fire an arrow" << endl;

		cin >> action;
		action = this->to_lower(action);
	} while (!this->is_valid_action(action));

	return action;
}

char game::get_arrow_fire_direction() {
	char direction;
	bool first = true;
	do {
		if (!first) {
			cout << endl << "That's an invalid input!" <<
				endl << endl;
		}
		first = false;

		cout << endl <<
			"What direction would you like to fire the arrow?" << endl << endl;
		cout << "w: up" << endl;
		cout << "a: left" << endl;
		cout << "s: down" << endl;
		cout << "d: right" << endl;

		cin >> direction;
		direction = this->to_lower(direction);
	} while (!this->is_direction(direction));

	return direction;
}

void game::move_up() {
	// TODO Delete the below placeholder code. Move the player up one
	// space in the grid, however you choose to do that.
	this->locationy--;
}

void game::move_down() {
	// TODO Delete the below placeholder code. Move the player down one
	// space in the grid, however you choose to do that.

	this->locationy++;

}

void game::move_left() {
	// TODO Delete the below placeholder code. Move the player left one
	// space in the grid, however you choose to do that.
	this->locationx--;
}

void game::move_right() {
	// TODO Delete the below placeholder code. Move the player right one
	// space in the grid, however you choose to do that.
	this->locationx++;
}

void game::randmove() {
    int worked = 0;
    int i = (rand() % 4) + 1; // Random number between 1 and 4
    cout << i << endl;

    int wid = this->width;
    int hig = this->height;

    do {
int i = (rand() % 4) + 1; // Random number between 1 and 4
    cout << i << endl;
        if (i == 1 && this->locationy > 0) { // Move up
            this->move_up();
            cout << "Move up" << endl;
            worked = 1;
        } 
        else if (i == 2 && this->locationy < hig - 1) { // Move down
            this->move_down();
            cout << "Move down" << endl;
            worked = 1;
        } 
        else if (i == 3 && this->locationx < wid - 1) { // Move right
            this->move_right();
            cout << "Move right" << endl;
            worked = 1;
        } 
        else if (i == 4 && this->locationx > 0) { // Move left
            this->move_left();
            cout << "Move left" << endl;
            worked = 1;
        }
    } while (worked != 1); // Repeat until a valid move is made

}

void game::move(char direction) {
	if(!p.confuse){
		if (direction == 'w') {
			this->move_up();
		} else if (direction == 'a') {
			this->move_left();
		} else if (direction == 'd') {
			this->move_right();
		} else {
			this->move_down();
		}
	}
	else{
		randmove();
	}
}

void game::wumpus_dead(){
		this->wumpusisdead = true;
}

void game::hitwumpus(int x, int y){
	if(y == this->ywumpus){
			if(x == this->xwumpus){
				cout << "YOU HIT THE WUMPUS. IT falls to the floor with a great thud. Congratulations great adventurer." << endl;
				wumpus_dead();
			}
	}
}

void game::fire_arrow_up() {
	int y = this->locationy;
	int x = this->locationx;
	int i = 3;
	do{
		if(y  <= 0){
			break;
		}
		else {
			hitwumpus(x, y);
		}
		y--;
		i--;;
	}while(i != 0);
	this->lavectora.at(this->ywumpus).at(this->xwumpus).removethyevent();
	arrow_setter(y, x, new Arrow);
	set_wumpus(height, width, new Wumpus);
}

void game::fire_arrow_down() {
	int y = this->locationy;
	int x = this->locationx;
	int hig = this->height;
	int i = 3;
	do{
		if(y  == hig - 1){
			break;
		}
		else {
			hitwumpus(x, y);
		}
		y++;
		i--;
	}while(i != 0);
	this->lavectora.at(this->ywumpus).at(this->xwumpus).removethyevent();
	arrow_setter(y, x, new Arrow);
	set_wumpus(height, width, new Wumpus);
}

void game::fire_arrow_left() {
	int y = this->locationy;
	int x = this->locationx;
	int i = 3;
	do{
		if(x  == 0){
			break;
		}
		else{ 
			hitwumpus(x, y);
		}
		x--;
		i--;
	}while(i != 0);
	this->lavectora.at(this->ywumpus).at(this->xwumpus).removethyevent();
	arrow_setter(y, x, new Arrow);
	set_wumpus(height, width, new Wumpus);
}

void game::fire_arrow_right() {
	int y = this->locationy;
	int x = this->locationx;
	int wid = this->width;
	int i = 3;
	do{
		if(x  == wid -1){
			break;
		}
		else{
			hitwumpus(x, y);
		}
		x++;
		i--;;
	}while(i != 0);
	this->lavectora.at(this->ywumpus).at(this->xwumpus).removethyevent();
	arrow_setter(y, x, new Arrow);
	set_wumpus(height, width, new Wumpus);
}

void game::fire_arrow(char direction) {
	if (direction == 'w') {
		this->fire_arrow_up();
	} else if (direction == 'a') {
		this->fire_arrow_left();
	} else if (direction == 'd') {
		this->fire_arrow_right();
	} else {
		this->fire_arrow_down();
	}

	this->num_arrows--;
}

void game::releasethebabies(){
locationsetters(height, width, new baby_wumpus);
locationsetters(height, width, new baby_wumpus);
locationsetters(height, width, new baby_wumpus);
}

void game::play_game(){
	int canya = 0;
	do{
		this->display_game();
		char action = this->get_player_action();
		if (this->is_direction(action)) {
			char direction = action;
			this->move(direction);
		} else { char direction = this->get_arrow_fire_direction();
			this->fire_arrow(direction);
		}	
			tick();
			trigger_encounter();
			Events();
		if(canya ==15){ releasethebabies();
		}
		canya++;
	}while(!this->check_win() && !this->check_lose() && !this->wumpusisdead);
}

void game::tick() {
	p.confuse = false;
}
void game::flashlight_found(){
	p.flashlights = true;
}
void game::trigger_encounter() {
	int a = 99;
		bool should_remove = this->lavectora.at(this->locationy).at(this->locationx).encounters(a);
		if(should_remove){
			this->lavectora.at(this->locationy).at(this->locationx).removethyevent();
		}
		if(a == 2){
			this->num_arrows++;
		}
		else if(a == 4){
			goldfound();
		}
		else if(a == 5){
			confused();
		}
		else if (a == 10000){
			flashlight_found();
		}


}

void game::confused() {
	p.confuse = true;
}

void game::goldfound(){
	p.gold = true;
}

int game::get_locationx() const  {
	return this->locationx;
}
	
int game::get_locationy() const {
	return this->locationy;
}

void game::Events()
{
	Eventleftright();
	Eventupdown();
}

void game::Eventupdown(){
	int lotac1, he;
	he = this->height;
	lotac1 = this->locationy;
	lotac1 = lotac1 + 1;
	if(lotac1 <= he - 1){
	this->lavectora.at(lotac1).at(this->locationx).percepts();
	}
	lotac1 = lotac1 - 2;
	if(lotac1 >= 0){
	this->lavectora.at(lotac1).at(this->locationx).percepts();
	}
}
void game::Eventleftright(){
	int lotac2, com;
	lotac2 = this->locationx;
	lotac2 = lotac2 + 1;
	com = this->width;
	if(lotac2 <= com -1){
		this->lavectora.at(this->locationy).at(lotac2).percepts();
	}

	lotac2 = lotac2 - 2;

	if(lotac2 >= 0){
		this->lavectora.at(this->locationy).at(lotac2).percepts();
	}
}

