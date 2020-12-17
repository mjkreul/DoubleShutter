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
		front_tile[i] = (i+1);
		back_tile.push_back(i+1);
	}
}

/**
 *
 * @param choice
 * @param t
 */
bool DSBoard::hitTile(vector<tile> choice, vector<int> t) {
	int sum =0;
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
 *
 */
void DSBoard::roll() {
	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
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
 *
 * @return
 */
bool DSBoard::gameFinished() {
	return this->gameStatus;
}

/**
 *
 */
void DSBoard::printDie() {
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
	return winStatus;
}


