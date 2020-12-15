//
// Created by Matt Kreul on 12/14/20.
//

#include "DSBoard.h"

using namespace std;

void DSBoard::hitTile(tile choice, int nTiles) {
	if(checkValidMove(choice, nTiles)){
		if(choice == front){
			if(nTiles == 1){
				front_tile[(die1 + die2) - 1] = 'X';
			}
			else{
				front_tile[die1 - 1] = 'X';
				front_tile[die2 - 1] = 'X';
			}
		}
		else {
		
		}
	}
	
}

void DSBoard::roll() {
	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
}


bool DSBoard::checkValidMove(tile choice, int nTiles) {

}

bool DSBoard::gameFinished() {
	return this->gameStatus;
}
