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

int PrintBoard(int board[8][8]){
	//cout << "\x1B[2J\x1B[H";
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
	return command;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
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


	cout << "Example command: H7 -> H5 \n";
	while(true){
		PrintBoard(board);
		cout << "Command: " << pause() << "\n";
	}

	return 0;
}
