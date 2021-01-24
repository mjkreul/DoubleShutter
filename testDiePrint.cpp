//
// Created by Matt Kreul on 12/15/20.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int num;
	string line1, line2, line3;
	
	cout << "input a valid num: ";
	cin >> num;
	if(num%2 == 1){
		line2 = "|   o   |";
	}
	if(num == 1){
		line1 = "|       |";
		line3 = "|       |";
	}
	else if (num > 1 && num < 4){
		line1 = "| o     |";
		line3 = "|     o |";
		if(num == 2){
			line2 = "|       |";
		}
	}
	else if(num > 3){
		line1 = "| o   o |";
		line3 = "| o   o |";
		if(num%2 == 0){
			if(num == 4){
				line2 = "|       |";
			}
			else{
				line2 = "| o   o |";
			}
		}
	}
	
	cout << line1 << endl << line2 << endl << line3 << endl;
	
	return 0;
}
