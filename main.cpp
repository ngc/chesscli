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

bool checkMove(string command){
	if(command.length() != 6) return false;
	
	int r1 = command[1] - '0' - 1;
	int c1 = abs(command[0] - 'H');
	int r2 = command[5] - '0' - 1;
	int c2 = abs(command[4] - 'H');
	
	if(r1 == r2 && c1 == c2) return false;
	if(c2 > 7 || c2 < 0 || c1 > 7 || c1 < 0 || r2 > 7 || r2 < 0 || r1 > 7 || r1 < 0) return false;
	
	//cout << "|" << r1 << "." << c1 << "\\" << "|" << r2 << "." << c2 << "\\" << "\n";
	
	switch(board[r1][c1]){
		case 1: /*♖*/ 
		if((r1 == r2 && c1 != c2) || (c1 == c2 && r1 != r2)){
			if(c2 == c1){
				for(int j = 0; j < abs(r2 - r1); j++){
					int cur = j * (((r1 > r2) * -1) + (r1 < r2));
					cout << "SEARCHING: ROW: " << r1 + cur << " COL: " << c2 << " | " << printCell(board[r1 + cur][c1]) << "\n";
					if(board[r1 + cur][c1] != 0 && cur != 0) return false;
				}
			}else{
				for(int j = 0; j < abs(c2 - c1); j++){
					int cur = j * ((c1 > c2 * -1) + c1 < c2);
					cout << printCell(board[r1][c1 + cur]) << "\n";
					if(board[r1][c1 + cur] != 0) return false;
				}	
			}
			board[r1][c1] = 0;
			board[r2][c2] = 1;
			return true;
		}else{
			return false;
		}
		
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
	
	return true;
}

int PrintBoard(){
	system("clear");
	for(int i = 0; i < 8; i++){
		cout << i + 1 << " ";
		for(int j = 0; j < 8; j++){
			printCell(board[i][j]);
		}
		cout << "\n";
	}
	cout << "• H G F E D C B A\n";
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

	cout << "Example command: H7 -> H5 \n";
	while(true){
		PrintBoard();
		cout << "Command: ";
		string command = pause();
		cout << command << "\n";
	}

	return 0;
}
