/// Author: Matt Kreul

#include <iostream>
#include <sstream>
#include "DSBoard.h"
#include "parseHelper.h"

using namespace std;

void toUpper(string s);

int main() {
	cout << "Made it past main" << endl;
	DSBoard * b = new DSBoard();
	cout << "Made a board" << endl;
	bool gameContinue = true;
	
	string ans, inputString;
	
	int nWins, nLosses;
	while(gameContinue){
		while(b->gameFinished()){
			b->roll();
			b->printDieTS();
			b->printBoard();
			vector<tile> tempTiles;
			vector<int> tempNums;
			vector<string> tokens;
			
			cout << "What would you like to do?" << endl;
			getline(cin, inputString);
			stringstream ss(inputString);
			int i = 0;
			while(getline(ss, ans, ' ')){
				if(i%2 ==0) tempTiles.push_back(parseHelper::parseTileItem(ans));
				else tempNums.push_back(parseHelper::parseNumItem(ans));
				i++;
			}
			if(!b->hitTile(tempTiles, tempNums)){
				cout << "invalid move please try again" << endl;
			}
		}
		cout << "Thanks for playing!  Would you like to play again? Y/N: ";
		cin >> ans;
		if(ans == "YES" || ans == "Y"){
			b = new DSBoard();
		}
		else{
			gameContinue = false;
		}
	}
	
	cout << "Thanks for playing. Here are the stats of the sets:" << endl;
	cout << "Wins: " << nWins;
	cout << "Losses: " << nLosses;
	
	return 0;
}

