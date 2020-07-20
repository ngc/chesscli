#include <bits/stdc++.h>
#include <stdlib.h>
#include "board.h"
#include "local.h"
#include "engine.h"

/*
  ██████ ██   ██ ███████ ███████ ███████   ██████ ██      ██ 
 ██      ██   ██ ██      ██      ██       ██      ██      ██ 
 ██      ███████ █████   ███████ ███████  ██      ██      ██ 
 ██      ██   ██ ██           ██      ██  ██      ██      ██ 
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
			cout << "   --cpu or -c starts a match with Stockfish.\n";
			cout << "   --source prints link to the source code and MIT license for ChessCLI\n\n";
			
			cout << "In-Game Arguments:\n";
			cout << "   quit causes the program to exit\n";
			cout << "   Any other commands will be classified as UCI commands.\n";
			cout << "       Examples:  e2e4, e7e5, e1g1 (white short castling), e7e8q (for promotion).\n";
		
		 
		}else if(argument == "--source"){
			cout << "https://github.com/thaniel-c/chess\n\n";
			cout << R"(Chess CLI tool to analyse and play Chess games within a terminal.
Copyright (C) 2020 Nathan Coulas

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.)" << "\n";
	}else if(argument == "--local"){
		localMode();
	}else if(argument == "--cpu" || argument == "-c"){
		engineMode();
	}else{
		cout << "Argument not recognized. Use --help for a list of arguments.\n";
	}
		
	}else{
		localMode();
	}
	
	return 0;
}
