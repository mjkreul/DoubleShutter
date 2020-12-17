/// Author: Matt Kreul

#include <iostream>
#include "DSBoard.h"

using namespace std;

void toUpper(string s);

int main() {
	DSBoard * b = new DSBoard();
	bool gameContinue = true;
	string ans;
	int nWins, nLosses;
	while(gameContinue){
		while(b->gameFinished()){
			b->roll();
			b->printBoard();
			cout << "What would you like to do?" << endl;
			
		}
		if(b.)
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

