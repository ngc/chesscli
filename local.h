#ifndef LOCAL_H
#define LOCAL_H

#include <bits/stdc++.h>
#include <stdlib.h>
#include "board.h"
#include "input.h"

using namespace std; 

void localMode(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool player1Turn = true;
	
    player1Name = "Nathan";
    player2Name = "Test";

	//cout << "Example command: A7A5 \n";
	
	while(true){
		PrintBoard();
		if(isMate(player1Turn)) {
			cout << (player1Turn ? "Player 2 Wins.\n" : "Player 1 Wins.\n");
			break;
		}
		
		string command = pause(player1Turn);
		player1Turn = !player1Turn;
	}

	return;
}
#endif
