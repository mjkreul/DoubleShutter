//
// Created by Matt Kreul on 12/14/20.
//

#include "DSBoard.h"

using namespace std;

/**
 * This initializes the vectors containing both of the tiles
 */
DSBoard::DSBoard() {
	for(int i = 0; i < 9; i++){
		front_tile.push_back(i + 1);
		back_tile.push_back(9 - i);
	}
}

/**
 * This is the main function for each turn.  After the dice are rolled, this can be played.  The inputs are for which
 * tile parameter to hit and which number for each.  As are the rules for the standard game, the back tiles cannot be
 * knocked down until the front tile at that specific index is knocked down.  Attempting to doing so will return from
 * the function early with a false boolean.
 *
 * The checks for a valid move set is in the private helper method "checkValidMove".
 *
 * @param choice
 *  the choice of front or back tile
 * @param tile
 *  the tile number to knock over
 * @return
 *  true or false if a valid move set was input
 */
bool DSBoard::hitTile(const vector<tile>& choice, const vector<int>& tile) {
	return checkValidMove(choice, tile);
}

/**
 * This is the valid move checker.  It copies over the current board and then simulates the move set entered by
 * the user.  If the simulated game is invalid, then it will return false.  If it runs through the game without any
 * issues, then it will copy the simulated board to the instance variables and return true.
 *
 * @param choice
 * @param tile
 * @return
 */
bool DSBoard::checkValidMove(const vector<tile> &  choice, const vector<int> & tile) {
	//TODO there has to be an easier method
	vector<int> tempFront(this->front_tile.size());
	vector<int> tempBack(this->back_tile.size());
	for(int i = 0; i < this->front_tile.size(); i ++){
		tempFront[i] = this->front_tile[i];
		tempBack[i] = this->back_tile[i];
	}
	int sum = 0;
	for(int i : tile){
		sum += i;
	}
	if(sum != (die1 + die2)){
		return false;
	}
	else{
		for(int i = 0; i < tile.size(); i++){
			tile_e tempChoice = choice[i];//for some reason this won't let me do just "tile" idk
			int tempNum = tile[i];
			if(tempChoice == back){
				if(tempFront[9 - tempNum] == 0 && tempBack[9 - tempNum] != 0) tempBack[9 - tempNum] = 0;
				else return false;
			}
			else{
				if(tempFront[tempNum - 1] != 0) tempFront[tempNum - 1] = 0;
				else return false;
			}
		}
	}
	//TODO change this to pointers so you can just make the instance variables equal to the temp board values
	for(int i = 0; i < this->front_tile.size(); i ++){
		this->front_tile[i] = tempFront[i];
		this->back_tile[i] = tempBack[i];
	}
	return true;
}

/**
 * This rolls the dice.  This function must be run for each turn.
 */
void DSBoard::roll() {
	die1 = this->r()%6 + 1;
	die2 = this->r()%6 + 1;
	//TODO check for if any valid move can be played.  If not game is finished and the game is lost.
	//TODO make this so that if the total number of tiles are less than 6 then only one die can be cast
	//TODO make this so that there is score being kept
}



/**
 * Returns whether the game can still be played or not.
 *
 * @return
 */
bool DSBoard::gameFinished() {
	return this->gameStatus;
}

/**
 *
 */
void DSBoard::printBoard() {
	cout << "\t=== Game Board ===" << endl;
	cout << "Tiles: " << endl;
	printTiles();
	cout << "Die: " << endl;
	printDie();
}

/**
 *
 */
void DSBoard::printTiles() {
	//TODO change this
	cout << " ";
	for(int i : back_tile){
		if(i != 0 ) cout << "|" << i << "| ";
		else cout << "|X| ";
	}
	cout << endl;
	for(int i : front_tile){
		if(i != 0 ) cout << "|" << i << "| ";
		else cout << "|X| ";
	}
	cout << endl;
}

/**
 * This function prints the die to the console
 */
void DSBoard::printDie() {
	
	//TODO this can be made more concise
	string line11, line21, line31, line12, line22, line32;
	if(die1%2 == 1){
		line21 = "|   o   |";
	}
	if(die1 == 1){
		line11 = "|       |";
		line31 = "|       |";
	}
	else if (die1 > 1 && die1 < 4){
		line11 = "| o     |";
		line31 = "|     o |";
		if(die1 == 2){
			line21 = "|       |";
		}
	}
	else if(die1 > 3){
		line11 = "| o   o |";
		line31 = "| o   o |";
		if(die1%2 == 0){
			if(die1 == 4){
				line21 = "|       |";
			}
			else{
				line21 = "| o   o |";
			}
		}
	}
	if(die2%2 == 1){
		line22 = "|   o   |";
	}
	if(die2 == 1){
		line12 = "|       |";
		line32 = "|       |";
	}
	else if (die2 > 1 && die2 < 4){
		line12 = "| o     |";
		line32 = "|     o |";
		if(die2 == 2){
			line22 = "|       |";
		}
	}
	else if(die2 > 3){
		line12 = "| o   o |";
		line32 = "| o   o |";
		if(die2%2 == 0){
			if(die2 == 4){
				line22 = "|       |";
			}
			else{
				line22 = "| o   o |";
			}
		}
	}
	cout << line11 << " " << line12 << endl;
	cout << line21 << " " << line22 << endl;
	cout << line31 << " " << line32 << endl;
}

DSBoard::~DSBoard() {
//	delete front_tile;

}

/**
 *
 *
 * @return
 */
bool DSBoard::gameWon() {
	for(int i = 0; i < front_tile.size(); i++){
		int temp1 = front_tile[i];
		int temp2 = back_tile[i];
		if(temp1 != 0 || temp2 != 0) return false;
	}
	return true;
}

const DSBoard &DSBoard::operator=(const DSBoard & rhs) {
	if(this != &rhs){
		delete this;
		this->die1 = rhs.die1;
		this->die2 = rhs.die2;
		this->front_tile = rhs.front_tile;
		this->back_tile = rhs.back_tile;
		this->gameStatus = rhs.gameStatus;
		this->winStatus = rhs.winStatus;
	}
	return *this;
}

void DSBoard::printDieTS() {
	cout << "Die1: " << this->die1 << " Die2: " << this->die2 << endl;
	
}







