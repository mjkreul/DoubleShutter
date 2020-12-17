//
// Created by Matt Kreul on 12/14/20.
//

#ifndef DOUBLESHUTTER_DSBOARD_H
#define DOUBLESHUTTER_DSBOARD_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <vector>

using namespace std;

typedef enum tile_e {front = 0, back = 1} tile;

class DSBoard {
	private:
//		char front_tile[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
//		char back_tile[9] = {'9', '8', '7', '6', '5', '4', '3', '2', '1'};
		vector<int> front_tile;
		vector<int> back_tile;
		bool gameStatus = true;
		bool winStatus = false;
		int die1 = -1;
		int die2 = -1;
		//game won or not
		
		
	public:
		DSBoard();
		~DSBoard();
		bool hitTile(vector<tile> choice, vector<int> t);
		void roll();
		
//		bool checkValidMove(tile choice, int * t);
		bool gameFinished();
		bool gameWon();
		void printDie();
		void printBoard();
		
		
		void printDieTS();
		void printTiles();
		
		
};


#endif //DOUBLESHUTTER_DSBOARD_H
