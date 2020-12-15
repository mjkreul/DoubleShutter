//
// Created by Matt Kreul on 12/14/20.
//

#ifndef DOUBLESHUTTER_DSBOARD_H
#define DOUBLESHUTTER_DSBOARD_H
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


typedef enum tile_e {front = 0, back = 1} tile;

class DSBoard {
	private:
		char front_tile[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
		char back_tile[9] = {'9', '8', '7', '6', '5', '4', '3', '2', '1'};
		bool gameStatus = true;
		int die1 = -1;
		int die2 = -1;
		//game won or not
		
		
	public:
//		DSBoard() {}
		
		void hitTile(tile choice, int nTiles);
		void roll();
		void printDie();
		void printBoard();
		bool checkValidMove(tile choice, int nTiles);
		bool gameFinished();
		void printDieTS();
		void printTiles();
		
		
};


#endif //DOUBLESHUTTER_DSBOARD_H
