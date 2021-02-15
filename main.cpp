/// Author: Matt Kreul

#include <iostream>
#include <sstream>
#include <cstring>
#include "DSBoard.h"
#include "parseHelper.h"

using namespace std;

void toUpper(string s);

int main(int argv, char * argc[]) {
	if(argv > 1){
		if(strcmp(argc[0], "help") == 0 || strcmp(argc[0], "-h") == 0){
			//TODO make instructions here
		}
		else{
			cout << "To view instructions type \"help\" or \"-h\" as arguments in the command line" << endl << endl;
		}
	}
	else{
		DSBoard * b = new DSBoard();
		
		bool gameContinue = true;
		
		string ans, inputString;
		
		int nWins, nLosses;
		while(gameContinue){
			int turn = 1;
			while(b->gameFinished()){
				b->roll();
				b->printBoard();
				cout << "Turn: " << turn <<" What would you like to do?" << endl;
				bool validMove = true;
				do{
					vector<tile> tempTiles;
					vector<int> tempNums;
					int i = 0;
					getline(cin, inputString);
					stringstream ss(inputString);
					cout << inputString << endl;
					while(getline(ss, ans, ' ')){
						if(i%2 == 0) tempTiles.push_back(parseHelper::parseTileItem(ans));
						else tempNums.push_back(parseHelper::parseNumItem(ans));
						i++;
					}
					for(tile t : tempTiles){
						cout << t << " ";
					}
					cout << endl;
					for(int n : tempNums){
						cout << n << " ";
					}
					cout << endl;
					if(!b->hitTile(tempTiles, tempNums)){
						cout << "Invalid move please try again" << endl;
						validMove = false;
					}
					else{
						turn++;
					}
				}
				while(!validMove);
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
	
}

