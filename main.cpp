/*********************************************************************
** Program Filename: main.cpp
** Author: Jackson Bennett
** Date: 11/25/2024
** Description: This program serves as the main entry point for a Wumpus game. It prompts the user to input the game board dimensions (width and height) and whether they wish to play in debug mode. The game is then initialized and played, with the option for the user to play again after a session ends.
** Input: User inputs for game board dimensions (width and height), and whether to enable debug mode.
** Output: Displays the game interface, prompts the user for actions, and shows the results of the game (win, lose, or continue). It also allows the user to restart the game if desired.
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "bottomless_pit.hpp"

#include "game.hpp"

using std::cout;
using std::cin;
using std::endl;

/*
 * Function: get_width
 * Description: Prompts the user for the game board width (# of columns)
 * Returns (int): Valid width supplied by user
 */
int get_width() {
	int width;
	
	bool first = true;
	do {
		if (!first) {
			cout << endl << "Invalid width!" << endl <<
				endl;
		}
		first = false;
		cout << "Enter the game board width between 4 and 30: ";
		cin >> width;
	} while(width < 4 || width > 30);
	return width;
}

/*
 * Function: get_height
 * Description: Prompts the user for the game board height (# of columns)
 * Returns (int): Valid height supplied by user
 */
int get_height() {
	int height;
	bool first = true;
	do {
		if (!first) {
			cout << endl << "Invalid height!" << endl <<
				endl;
		}
		first = false;
		cout << "Enter the game board height between 4 and 30: ";
		cin >> height;
	} while(height < 4 || height > 30);
	return height;
}

/*
 * Function: get_debug
 * Description: Prompts the user whether they want to play in debug mode
 * Returns (bool): True if the user wants to play in debug mode. False
 * 		otherwise.
 */
bool get_debug() {
	int debug_input;
	bool first = true;
	do {
		if (!first) {
			cout << endl << "Invalid input!" << endl <<
				endl;
		}
		first = false;
		cout << "Would you like to play in debug mode? (1-yes, 0-no): ";
		cin >> debug_input;
	} while(debug_input != 0 && debug_input != 1);
	return debug_input == 1;
}

void play_again(){
	cout << "print out play again 1 yes or 2 anything else" << endl;
}
int main()
{
	int again = 1;
	do{
	srand(time(nullptr));

	int width = get_width();

	int height = get_height();

	bool debug = get_debug();

	game g(width, height, debug);

	g.play_game();

	play_again();

	cin >> again;
	
	}while(again == 1);
	return 0;
}
