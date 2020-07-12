#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std; 
typedef pair<int, int> pii;

int board[8][8] = {
	-1, -2, -3, -4, -5, -3, -2, -1,
	-6, -6, -6, -6, -6, -6, -6, -6,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	1, 2, 3, 4, 5, 3, 2, 1,
};

int printCell(int val){
	switch(val){
		case 1: cout << "♖"; break;
		case 2: cout << "♘︎"; break;
		case 3: cout << "♗︎"; break;
		case 4: cout << "♕︎"; break;
		case 5: cout << "♔"; break;
		case 6: cout << "♙"; break;
		
		case 0: cout << "⠀"; break;
		
		case -1: cout << "♜"; break;
		case -2: cout << "♞︎"; break;
		case -3: cout << "♝︎"; break;
		case -4: cout << "♛"; break;
		case -5: cout << "♚"; break;
		case -6: cout << "♟︎"; break;
	}
	cout << "⠀";
	return 0;
}

vector<pii> movementTemp;

void pieceMovement(int rd, int cd, int r, int c){
	r += rd;
	c += cd;
	if(r > 7 || r < 0) return;
	if(c > 7 || c < 0) return;
	movementTemp.push_back(pii(r, c));
	if(board[r][c] != 0) return;
	return pieceMovement(rd, cd, r, c);
}

vector<pii> getMoves(int i, int j){
	movementTemp.clear();
	int r, c, side;
	int knight_values[2][8] = {
		{-2, -1, 1, 2, 2, 1, -1, -2},
		{-1, -2, -2, -1, 1, 2, 2, 1}
	};
	
	if(board[i][j] > 0) side = 1;
	else side = -1;

		switch(abs(board[i][j])){
		case 1: /*♖*/
			pieceMovement(-1, 0, i, j);
			pieceMovement(1, 0, i, j);
			pieceMovement(0, 1, i, j);
			pieceMovement(0, -1, i, j);
			break;
			
		case 2:/*♘︎*/
			for(int f = 0; f < 8; f++){
				r = i + knight_values[0][f];
				c = j + knight_values[1][f];
				if(r < 0 || r > 7 || c < 0 || c > 7) continue;
				movementTemp.push_back(pii(r, c));
			}
			break;
		
		case 3:/*♗︎*/
			pieceMovement(-1, -1, i, j);
			pieceMovement(1, -1, i, j);
			pieceMovement(-1, 1, i, j);
			pieceMovement(1, 1, i, j);
			break;
		
		case 4:/*♕*/
			pieceMovement(-1, -1, i, j);
			pieceMovement(1, -1, i, j);
			pieceMovement(-1, 1, i, j);
			pieceMovement(1, 1, i, j);
			
			pieceMovement(-1, 0, i, j);
			pieceMovement(1, 0, i, j);
			pieceMovement(0, 1, i, j);
			pieceMovement(0, -1, i, j);
			break;
		
		case 5:/*♔*/
			movementTemp.push_back(pii(i + 1, j + 1));
			movementTemp.push_back(pii(i - 1, j - 1));
			movementTemp.push_back(pii(i - 1, j + 1));
			movementTemp.push_back(pii(i + 1, j - 1));
			movementTemp.push_back(pii(i + 1, j));
			movementTemp.push_back(pii(i - 1, j));
			movementTemp.push_back(pii(i, j + 1));
			movementTemp.push_back(pii(i, j - 1));
			break;
		
		case 6:/*♙*/
			pieceMovement(0, 0, i + side, j + side);
			pieceMovement(0, 0, i + side, j + side * -1);
		break;
	}
	return movementTemp;
}

bool checkMove(string command, bool isPlayer1){
	if(command.length() != 6) return false;
	
	int side;
	int r1 = 7 - (command[1] - '0' - 1);
	int c1 = abs(command[0] - 'A');
	int r2 = 7 - (command[5] - '0' - 1);
	int c2 = abs(command[4] - 'A');
	if(isPlayer1) side = 1; 
	else side = -1;
	
	if(r1 == r2 && c1 == c2) return false;
	if(abs(board[r2][c2]) == 5) return false;
	if(c2 > 7 || c2 < 0 || c1 > 7 || c1 < 0 || r2 > 7 || r2 < 0 || r1 > 7 || r1 < 0) return false;
	if((board[r1][c1] * side) < 0) return false;
	if(board[r2][c2] * side > 0) return false;
	
	vector<pii> possibleMoves = getMoves(r1, c1);
	for(int i = 0; i < possibleMoves.size(); i++){
		if(possibleMoves[i].first == r2 && possibleMoves[i].second == c2){
			board[r2][c2] = board[r1][c1];
			board[r1][c1] = 0;
			return true;
		}
	}
	
	return false;
}

void PrintBoard(){
	system("clear");
	for(int i = 0; i < 8; i++){
		cout << 8 - i << " ";
		for(int j = 0; j < 8; j++){
			printCell(board[i][j]);
		}
		cout << "\n";
	}
	cout << "• A B C D E F G H\n";
	return;
}

string pause(bool isPlayer1, bool recursive = false) {
	//Player 1 = 1
	//Player 2 = -1
    cin.clear();
    if(!recursive) cout << endl << "Last move: ";
    string command;
    getline(cin, command);
    string command_display = command;
    
	command.erase(remove(command.begin(), command.end(), ' '), command.end()); 
	for_each(command.begin(), command.end(), [](char & c){
		c = ::toupper(c);
	});
	
	if(checkMove(command, isPlayer1)){
		return command_display;
	}else{
		return pause(isPlayer1, true);
	}
	
	return command_display;
	
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool player1Turn = true;

	cout << "Example command: A7 -> A5 \n";
	cout << "TURN: " << (player1Turn ? "Player 1\n" : "Player 2\n");
	
	while(true){
		PrintBoard();
		cout << "Command: ";
		//cout << (isMate(player1Turn) ? "True\n" : "False\n");
	/*	if(isMate(player1Turn)) {
			cout << (player1Turn ? "Player 2 Wins.\n" : "Player 1 Wins.\n");
			break;
		}*/
		
		string command = pause(player1Turn);
		player1Turn = !player1Turn;
		cout << command << "\n";
		cout << "TURN: " << (player1Turn ? "Player 1\n" : "Player 2\n");
	}

	return 0;
}
