#include <bits/stdc++.h>
#include <stdlib.h>
#include "board.h"
#include "local.h"

/*
  ██████ ██   ██ ███████ ███████ ███████   ██████ ██      ██ 
 ██      ██   ██ ██      ██      ██       ██      ██      ██ 
 ██      ███████ █████   ███████ ███████  ██      ██      ██ 
 ██      ██   ██ ██           ██      ██  ██      ██      ██ 
  ██████ ██   ██ ███████ ███████ ███████   ██████ ███████ ██  
*/

using namespace std; 

int main(int argc, char** argv){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	if(argc > 2){
		cout << "Too many arguments, --help for a list of possible arguments.\n";
		return 0;
	}if(argc == 2){
		string argument = argv[1];
		if(argument == "--help" || argument == "-h"){
			
			cout << R"(
  ██████ ██   ██ ███████ ███████ ███████   ██████ ██      ██ 
 ██      ██   ██ ██      ██      ██       ██      ██      ██ 
 ██      ███████ █████   ███████ ███████  ██      ██      ██ 
 ██      ██   ██ ██           ██      ██  ██      ██      ██ 
  ██████ ██   ██ ███████ ███████ ███████   ██████ ███████ ██)" << "\n\n";

			//3 SPACE TABS
			cout << "ChessCLI Help Menu:\n\n";
			cout << "Command Line Arguments:\n";
			cout << "   --help or -h brings up this help menu.\n";
			cout << "   --local or no arguments starts a local match with two players taking turns controlling the same terminal.\n";
			cout << "   --ssh %IP %PORT(Optional) starts an online multiplayer match with another player.\n";
			cout << "   --cpu or -c starts a match with Stockfish.\n";
			cout << "   --maxis or -m starts a match with Maxis.\n\n";	
			
			cout << "In-Game Arguments:\n";
			cout << "   q causes the program to exit\n";
			cout << "   Any other commands will be classified as UCI commands.\n";
			cout << "       Examples:  e2e4, e7e5, e1g1 (white short castling), e7e8q (for promotion).\n";
			
		}
		
		return 0;
	}else{
		localMode();
	}
	
	return 0;
}
