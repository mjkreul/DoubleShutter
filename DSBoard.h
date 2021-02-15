//
// Created by Matt Kreul on 12/14/20.
//

#ifndef DOUBLESHUTTER_DSBOARD_H
#define DOUBLESHUTTER_DSBOARD_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <random>

using namespace std;

/**
 * This is the prototype for the DoubleShutter board
 */
typedef enum tile_e {front = 0, back = 1} tile;

class DSBoard {
	private:
		vector<int> front_tile;
		vector<int> back_tile;
		bool gameStatus = true;
		bool winStatus = false;
		int die1 = -1;
		int die2 = -1;
		random_device r;
		//game won or not
		bool checkValidMove(const vector<tile>& , const vector<int>& );
	public:
		DSBoard();
		~DSBoard();
		const DSBoard& operator=(const DSBoard &);
		
		bool hitTile(const vector<tile>& , const vector<int>& );
		void roll();
		
//		bool checkValidMove(tile choice, int * t);
		bool gameFinished();
		bool gameWon();
		void printDie();
		void printBoard();
		void printTiles();
		void printDieTS();
};


#endif //DOUBLESHUTTER_DSBOARD_H
