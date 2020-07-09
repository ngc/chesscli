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

bool checkMove(string command, int side = 1){
	if(command.length() != 6) return false;
	
	int r1 = 7 - (command[1] - '0' - 1);
	int c1 = abs(command[0] - 'A');
	int r2 = 7 - (command[5] - '0' - 1);
	int c2 = abs(command[4] - 'A');
	
	//cout << "|" << r1 << "." << c1 << "\\" << "|" << r2 << "." << c2 << "\\" << "\n";
	
	if(r1 == r2 && c1 == c2) return false;
	if(abs(board[r2][c2] == 5)) return false;
	if(c2 > 7 || c2 < 0 || c1 > 7 || c1 < 0 || r2 > 7 || r2 < 0 || r1 > 7 || r1 < 0) return false;
	
	switch(board[r1][c1] / side){
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
			switch(abs(r2 - r1)){
				case  1: if(abs(c2 - c1) != 2) return false;
				case  2: if(abs(c2 - c1) != 1) return false;
			}
			
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
		case 4: cout << "♕︎"; break;
		case 5: cout << "♔"; break;
		case 6: /*♙ PAWN: Check if on players initial row, if so then permit a movement of 2 if not permit a movement of 1*/
		if(c2 == c1){
			if(r2 - r1 == -1 && board[r2][c2] == 0){
				board[r1][c1] = 0;
				board[r2][c2] = 6;
				return true;
			}else if(r1 == 6 && r2 - r1 == -2 && board[r2][c2] == 0){
				board[r1][c1] = 0;
				board[r2][c2] = 6;
				return true;
			}
		}else if(abs(c2 - c1) == 1 && r2 - r1 == -1 && (board[r2][c2] / side) < 0){
			board[r1][c1] = 0;
			board[r2][c2] = 6;
			return true;
		}
		
		case 0: return false;
		
		case -1: cout << "♜"; break;
		case -2: cout << "♞︎"; break;
		case -3: cout << "♝︎"; break;
		case -4: cout << "♛"; break;
		case -5: cout << "♚"; break;
		case -6: cout << "♟︎"; break;
	}
	
	return false;
}

int PrintBoard(){
	system("clear");
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

string pause() {
    cin.clear();
    cout << endl << "Last move: ";
    string command;
    getline(cin, command);
    string command_display = command;
    
	command.erase(remove(command.begin(), command.end(), ' '), command.end()); 
	for_each(command.begin(), command.end(), [](char & c){
		c = ::toupper(c);
	});
	checkMove(command);
	
	return command_display;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout << "Example command: A7 -> A5 \n";
	while(true){
		PrintBoard();
		cout << "Command: ";
		string command = pause();
		cout << command << "\n";
	}

	return 0;
}
