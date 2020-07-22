#ifndef FIGHT_H
#define FIGHT_H

#include <bits/stdc++.h>
#include <stdlib.h>
#include "board.h"
#include "input.h"
#include "EngineConnector.h"

using namespace std; 

void fight(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool player1Turn = true;
	string position = "0000";
	player1Name = "Stockfish";
    player2Name = "Stockfish";
	
	while(true){		
		cout << "asfs";
		if(isMate(player1Turn)) {
			cout << (player1Turn ? "Player 2 Wins.\n" : "Player 1 Wins.\n");
			break;
		}
		//PrintBoard();
		cout << flush;
		if(player1Turn){
		cout << "asfdasfasdsdafa";
		string command = getEngineMove(position, player1Turn);
		position += " " + command;
		player1Turn = !player1Turn;
		}else{
			cout << flush;
			string command = getEngineMove(position, player1Turn);
			position += " " + command;
			player1Turn = !player1Turn;
		}

	}

	return;
}
#endif

