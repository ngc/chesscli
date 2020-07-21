#ifndef INPUT_H
#define INPUT_H

#include <bits/stdc++.h>
#include <stdlib.h>
#include "board.h"
using namespace std;

string pause(bool isPlayer1) {
    cin.clear();
    cout << flush;
    string command;
    getline(cin, command);
    
	if(command == "quit"){
		cout << "Exiting...\n";
		exit(0);
	}else if(command == "moves"){
		cout << moveLog << "\n";
	}

	command.erase(remove(command.begin(), command.end(), ' '), command.end()); 
	
	if(checkMove(command, isPlayer1)){
		return command;
	}else{
		return pause(isPlayer1);
	}
	system("clear");
	return command;
}
#endif
