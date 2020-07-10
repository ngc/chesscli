#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

typedef long long LL; 
typedef pair<int, int> pii; 
typedef pair<LL, LL> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<LL> vl; 
typedef vector<vl> vvl;
typedef queue<int> qi;
typedef queue<char> qc;
typedef stack<int> si;
typedef stack<char> sc;

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

/*int board[8][8] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, -3, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 5, 0, 0, 0,
};*/

int kingmap[8][8];

void paintmap(int rd, int cd, int r, int c){
	/**Takes two arguments for direction and location and marks kingmap**/
	r += rd;
	c += cd;
	cout << r << " " << c << " | "<< rd << " " << cd << "\n";
	
	if(r > 7 || r < 0) return;
	if(c > 7 || c < 0) return;
	
	kingmap[r][c] = -1;
	if(board[r][c] != 0) return;
	if(rd == 0 && cd == 0) return;
	paintmap(rd, cd, r, c);
}

void generateKingmap(int side){
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
				paintmap(-1, 0, i, j);
				paintmap(1, 0, i, j);
				paintmap(0, 1, i, j);
				paintmap(0, -1, i, j);
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
				paintmap(-1, -1, i, j);
				paintmap(1, -1, i, j);
				paintmap(-1, 1, i, j);
				paintmap(1, 1, i, j);
				break;
			
			case 4:/*♕*/
				paintmap(-1, -1, i, j);
				paintmap(1, -1, i, j);
				paintmap(-1, 1, i, j);
				paintmap(1, 1, i, j);
				
				paintmap(-1, 0, i, j);
				paintmap(1, 0, i, j);
				paintmap(0, 1, i, j);
				paintmap(0, -1, i, j);
				break;
			
			case 5:/*♔*/
				paintmap(0, 0, i + 1, j + 1);
				paintmap(0, 0, i - 1, j - 1);
				paintmap(0, 0, i - 1, j + 1);
				paintmap(0, 0, i + 1, j - 1);
				paintmap(0, 0, i + 1, j);
				paintmap(0, 0, i - 1, j);
				paintmap(0, 0, i, j + 1);
				paintmap(0, 0, i, j - 1);
				break;
			
			case 6:/*♙*/
				paintmap(0, 0, i + side, j + side);
				paintmap(0, 0, i + side, j + side * -1);
				break;
		}
		
		if(board[i][j] * side != 5 && board[i][j] * side * -1 < 0) kingmap[i][j] = -1;
		
	}
  }
  
	cout << "\n";
  	for(int i = 0; i < 8; i++){
		cout << 8 - i << " ";
		for(int j = 0; j < 8; j++){
			cout << (kingmap[i][j] == -1 ? 'X' : 'O') << " ";
		}
		cout << "\n";
	}
}

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

bool checkMove(string command, bool isPlayer1){
	if(command.length() != 6) return false;
	
	int side;
	int r1 = 7 - (command[1] - '0' - 1);
	int c1 = abs(command[0] - 'A');
	int r2 = 7 - (command[5] - '0' - 1);
	int c2 = abs(command[4] - 'A');
	
	if(isPlayer1){
		side = 1;
	}else{
		side = -1;
	}
	
	if(r1 == r2 && c1 == c2) return false;
	if(abs(board[r2][c2]) == 5) return false;
	if(c2 > 7 || c2 < 0 || c1 > 7 || c1 < 0 || r2 > 7 || r2 < 0 || r1 > 7 || r1 < 0) return false;
	//if(board[r1][c1] * side != 1) return false;
	
	switch(board[r1][c1]){
		case 1: /*♖*/ 
		if((r1 == r2 && c1 != c2) || (c1 == c2 && r1 != r2)){
			if(c2 == c1){
				for(int j = 1; j < abs(r2 - r1); j++){
					int cur = j * (((r1 > r2) * -1) + (r1 < r2));
					if(board[r1 + cur][c1] != 0) return false;
				}
			}else{
				for(int j = 1; j < abs(c2 - c1); j++){
					int cur = j * (((c1 > c2) * -1) + (c1 < c2));
					if(board[r1][c1 + cur] != 0) return false;
				}	
			}
			board[r1][c1] = 0;
			board[r2][c2] = 1;
			return true;
		}
		
		case 2: /*♘*/			
			if(abs(r2 - r1) == 1 && abs(c2 - c1) != 2) return false;
			if(abs(r2 - r1) == 2 && abs(c2 - c1) != 1) return false;
			
			board[r1][c1] = 0;
			board[r2][c2] = 2;
			return true;
		
		case 3: /*♗*/
			if(abs(r2 - r1) == abs(c2 - c1) && (board[r2][c2] / side) <= 0){
				for(int i = 1; i < abs(c2 - c1); i++){
					if(board[r1 + (i * (((r1 > r2) * -1) + (r1 < r2)))][c1 + (i * (((c1 > c2) * -1) + (c1 < c2)))] != 0) return false;
				}
			
				board[r1][c1] = 0;
				board[r2][c2] = 3;
				return true;
			}
			
		case 4:/*♕*/
		if((r1 == r2 && c1 != c2) || (c1 == c2 && r1 != r2)){
			if(c2 == c1){
				for(int j = 1; j < abs(r2 - r1); j++){
					int cur = j * (((r1 > r2) * -1) + (r1 < r2));
					if(board[r1 + cur][c1] != 0) return false;
				}
			}else{
				for(int j = 1; j < abs(c2 - c1); j++){
					int cur = j * (((c1 > c2) * -1) + (c1 < c2));
					if(board[r1][c1 + cur] != 0) return false;
				}	
			}
			board[r1][c1] = 0;
			board[r2][c2] = 4;
			return true;
			
		}else if(abs(r2 - r1) == abs(c2 - c1) && (board[r2][c2] / side) <= 0){
			for(int i = 1; i < abs(c2 - c1); i++){
				if(board[r1 + (i * (((r1 > r2) * -1) + (r1 < r2)))][c1 + (i * (((c1 > c2) * -1) + (c1 < c2)))] != 0) return false;
			}
			board[r1][c1] = 0;
			board[r2][c2] = 4;
			return true;
		}
	
		case 5: /*♔*/
			generateKingmap(side);
			if(abs(r2 - r1) <= 1 && abs(c2 - c1) <= 1 && kingmap[r2][c2] == 0){
				board[r1][c1] = 0;
				board[r2][c2] = 5;
				return true;	
			}else{
				return false;
			}
		
		case 6: /*♙ PAWN: Check if on players initial row, if so then permit a movement of 2 if not permit a movement of 1*/
			if(c2 == c1){
				if(r2 - r1 == -1 && board[r2][c2] == 0){
					board[r1][c1] = 0;
					board[r2][c2] = 6;
					return true;
				}else if(r1 == 6 && r2 - r1 == -2 && board[r2][c2] == 0 && board[r2 + 1][c2] == 0){
					board[r1][c1] = 0;
					board[r2][c2] = 6;
					return true;
				}
			}else if(abs(c2 - c1) == 1 && r2 - r1 == -1 && (board[r2][c2] / side) < 0){
				board[r1][c1] = 0;
				board[r2][c2] = 6;
				return true;
			}
		
		////////////////////////////////////////////////////////////////
		case 0: return false;
		////////////////////////////////////////////////////////////////
	}
	
	return false;
}

int PrintBoard(){
	//system("clear");
	for(int i = 0; i < 8; i++){
		cout << 8 - i << " ";
		for(int j = 0; j < 8; j++){
			printCell(board[i][j]);
		}
		cout << "\n";
	}
	cout << "• A B C D E F G H\n";
	return 0;
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
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool player1Turn = true;

	cout << "Example command: A7 -> A5 \n";
	cout << "TURN: " << (player1Turn ? "Player 1\n" : "Player 2\n");
	player1Turn = !player1Turn;
	
	while(true){
		PrintBoard();
		cout << "Command: ";
		string command = pause(true);
		cout << command << "\n";
		cout << "TURN: " << (player1Turn ? "Player 1\n" : "Player 2\n");
		player1Turn = !player1Turn;
	}

	return 0;
}
