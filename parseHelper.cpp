//
// Created by Matt Kreul on 12/17/20.
//

#include "parseHelper.h"
#include <exception>

int parseHelper::parseNumItem(string s) {
//	try {
		return stoi(s);
//	}
//	catch (exception e){
//		cout << "Incorrect format" << endl << endl;
//	}
}

tile parseHelper::parseTileItem(string s) {
	if(s == "b" || s == "B" || s == "back" || s == "Back" || s == "BACK"){
		return back;
	}
	else if(s == "f" || s == "F" || s == "front" || s == "Front" || s == "FRONT"){
		return front;
	}
	else return back; //TODO fix both of these to error check better
}
