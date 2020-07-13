#ifndef INPUT_H
#define INPUT_H

#include <bits/stdc++.h>
#include <stdlib.h>
#include "board.h"
using namespace std;

string pause(bool isPlayer1, bool recursive = false, bool isHuman = true) {
    cin.clear();
    if(!recursive) cout << endl << "Last command: ";
    string command;
    getline(cin, command);
    string command_display = command;
    
	if(command.length() == 1){
		switch(command[0]){
			case 'q':
				cout << "Exiting...\n";
				exit(0);
		}
	}
    
	command.erase(remove(command.begin(), command.end(), ' '), command.end()); 
	
	if(checkMove(command, isPlayer1)){
		return command_display;
	}else{
		return pause(isPlayer1, true);
	}
	
	return command_display;
}
#endif
