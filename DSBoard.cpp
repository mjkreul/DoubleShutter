//
// Created by Matt Kreul on 12/14/20.
//

#include "DSBoard.h"

using namespace std;

/**
 *
 */
DSBoard::DSBoard() {
	for(int i = 0; i < 9; i++){
		front_tile.push_back(i+1);
		back_tile.push_back(9 - i);
	}
}

/**
 * This is the main function for each turn.  After the dice are rolled, this can be played.  The inputs are for which
 * tile parameter to hit and which number for each.  As are the rules for the standard game, the back tiles cannot be
 * knocked down until the front tile at that specific index is knocked down.  Attempting to doing so will return from
 * the function early with a false boolean.
 *
 * @param choice
 * @param t
 */
bool DSBoard::hitTile(vector<tile> choice, vector<int> t) {
	int sum = 0;
	for(int i : t){
		sum += i;
	}
	if(sum != (die1 + die2)){
		return false;
	}
	else{
		for(int i = 0; i < t.size(); i++){
			tile tempChoice = choice[i];
			int tempNum = t[i];
			if(tempChoice == back){
				if(front_tile[(9 - tempNum)] == 0){
					back_tile[tempNum - 1] = 0;
				}
				else{
					return false;
				}
			}
			else{
				if(front_tile[tempNum - 1] != 0){
					front_tile[tempNum - 1] = 0;
				}
				else{
					return false;
				}
			}
		}
	}
	return true;
}

/**
 * This rolls the dice.  This function must be run for each turn.
 */
void DSBoard::roll() {
	die1 = this->r()%6 + 1;
	die2 = this->r()%6 + 1;
}

/**
 *
 * @param choice
 * @param t
 * @return
 */
//bool DSBoard::checkValidMove(tile choice, int * t) {
//	return false;
//}

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
	cout << " ";
	for(int i : back_tile){
		if(i != 0 ) cout << "|" << i << "| ";
		else cout << "|X| ";
	}
	cout << endl;
//	cout << "|";
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





