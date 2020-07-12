#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std; 
typedef pair<int, int> pii;

vector<pii> movementTemp;
pii KingPosP1;
pii KingPosP2;
int kingmap1[8][8];
int kingmap2[8][8];

int board[8][8] = {
	-1, -2, -3, -4, -5, -3, -2, -1,
	-6, -6, -6, -6, -6, -6, -6, -6,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	6, 6, 6, 6, 6, 6, 6, 6,
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

void paintmap(int rd, int cd, int r, int c, int side){
	/**Takes two arguments for direction and location and marks kingmap**/
	
	r += rd;
	c += cd;
	//cout << r << " " << c << " | "<< rd << " " << cd << "\n";
	
	if(r > 7 || r < 0) return;
	if(c > 7 || c < 0) return;
	
	if(side == 1) kingmap1[r][c] -= 1;
	if(side == -1) kingmap2[r][c] -= 1;
	
	if(board[r][c] != 0) return;
	if(rd == 0 && cd == 0) return;
	paintmap(rd, cd, r, c, side);
}

bool generateKingmap(int side, int kingmap[8][8]){
	/** Generates map of places where the king can move on the board */
	memset(kingmap, 0, sizeof(kingmap[0][0]) * 8 * 8);
	
	/*
	 * UP = -1
	 * DOWN = 1
	 * LEFT = -1
	 * RIGHT = 1
	 */
	
	int r, c;
	int knight_values[2][8] = {
		{-2, -1, 1, 2, 2, 1, -1, -2},
		{-1, -2, -2, -1, 1, 2, 2, 1}
	};
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			switch(board[i][j] * side * -1){
			case 1: /*♖*/
				paintmap(-1, 0, i, j, side);
				paintmap(1, 0, i, j, side);
				paintmap(0, 1, i, j, side);
				paintmap(0, -1, i, j, side);
				break;
				
			case 2:/*♘︎*/
				for(int f = 0; f < 8; f++){
					r = i + knight_values[0][f];
					c = j + knight_values[1][f];
					if(r < 0 || r > 7 || c < 0 || c > 7) continue;
					kingmap[r][c] = -1;
				}
				break;
			
			case 3:/*♗︎*/
				paintmap(-1, -1, i, j, side);
				paintmap(1, -1, i, j, side);
				paintmap(-1, 1, i, j, side);
				paintmap(1, 1, i, j, side);
				break;
			
			case 4:/*♕*/
				paintmap(-1, -1, i, j, side);
				paintmap(1, -1, i, j, side);
				paintmap(-1, 1, i, j, side);
				paintmap(1, 1, i, j, side);
				
				paintmap(-1, 0, i, j, side);
				paintmap(1, 0, i, j, side);
				paintmap(0, 1, i, j, side);
				paintmap(0, -1, i, j, side);
				break;
			
			case 5:/*♔*/
				paintmap(0, 0, i + 1, j + 1, side);
				paintmap(0, 0, i - 1, j - 1, side);
				paintmap(0, 0, i - 1, j + 1, side);
				paintmap(0, 0, i + 1, j - 1, side);
				paintmap(0, 0, i + 1, j, side);
				paintmap(0, 0, i - 1, j, side);
				paintmap(0, 0, i, j + 1, side);
				paintmap(0, 0, i, j - 1, side);
				break;
			
			case 6:/*♙*/
				paintmap(0, 0, i + side, j + side, side);
				paintmap(0, 0, i + side, j + side * -1, side);
				break;
		}
		
		if(board[i][j] == 5) KingPosP1 = pii(i, j);
		if(board[i][j] == -5) KingPosP2 = pii(i, j);
		if(board[i][j] * side != 5 && board[i][j] * side > 0 && kingmap[i][j] >= 0) kingmap[i][j] = -1;
	}
  }
  
	cout << "\n";
  	for(int i = 0; i < 8; i++){
		cout << 8 - i << " ";
		for(int j = 0; j < 8; j++){
			cout << abs(kingmap[i][j]) << " ";
		}
		cout << "\n";
	}
	if(side == 1) {return kingmap[KingPosP1.first][KingPosP1.second] < 0;}
	else {return kingmap[KingPosP2.first][KingPosP2.second] < 0;}
}

bool validateMove(int r1, int r2, int c1, int c2, int piece, bool revert = false){
	int side;
	if(piece > 0) side = 1;
	if(piece < 0) side = -1;
	
	int tempPiece = board[r2][c2];
	board[r1][c1] = 0;
	board[r2][c2] = piece;
	
	if(side == 1){
		if(generateKingmap(side, kingmap1)){
			board[r1][c1] = piece;
			board[r2][c2] = tempPiece;
			return false;
		}
	}else{
		if(generateKingmap(side, kingmap2)){
			board[r1][c1] = piece;
			board[r2][c2] = tempPiece;
			return false;
		}
	}
	if(revert){
		board[r1][c1] = piece;
		board[r2][c2] = tempPiece;
	}
	return true;
}

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
			if(side == 1){
				if(i == 6) movementTemp.push_back(pii(i - 2, j));
				if(board[i - 1][j + 1] < 0) movementTemp.push_back(pii(i - 1, j + 1));
				if(board[i - 1][j - 1] < 0) movementTemp.push_back(pii(i - 1, j - 1));
				if(board[i - 1][j] == 0) movementTemp.push_back(pii(i - 1, j));
			}else{
				if(i == 1) movementTemp.push_back(pii(i + 2, j));
				if(board[i + 1][j + 1] > 0) movementTemp.push_back(pii(i + 1, j + 1));
				if(board[i + 1][j - 1] > 0) movementTemp.push_back(pii(i + 1, j - 1));
				if(board[i + 1][j] == 0) movementTemp.push_back(pii(i + 1, j));
			}
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
			return validateMove(r1, r2, c1, c2, board[r1][c1]);
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
