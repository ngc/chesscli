#ifndef ENGINE_H
#define ENGINE_H

#include <bits/stdc++.h>
#include <stdlib.h>
#include "board.h"
#include "input.h"
#include "EngineConnector.h"

using namespace std; 

void engineMode(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool player1Turn = true;
	string position = "";

	cout << "Example command: A7A5 \n";
	cout << "TURN: " << (player1Turn ? "Player 1\n" : "Player 2\n");
	
	while(true){		
		if(isMate(player1Turn)) {
			cout << (player1Turn ? "Player 2 Wins.\n" : "Player 1 Wins.\n");
			break;
		}
		
		if(player1Turn){
		PrintBoard();
		cout << "Command: ";
		string command = pause(player1Turn);
		position += " " + command;
		player1Turn = !player1Turn;
		cout << command << "\n";
		cout << "TURN: Player 1\n";
		}else{
			string command = getEngineMove(position, player1Turn);
			position += " " + command;
			player1Turn = !player1Turn;
		}
		
	}

	return;
}
#endif
