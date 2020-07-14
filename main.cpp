#include <bits/stdc++.h>
#include <stdlib.h>
#include "board.h"
#include "local.h"
#include "engine.h"

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
			cout << "   --maxis or -m starts a match with Maxis.\n";	
			cout << "   --source prints link to the source code and MIT license for ChessCLI\n\n";
			
			cout << "In-Game Arguments:\n";
			cout << "   q causes the program to exit\n";
			cout << "   Any other commands will be classified as UCI commands.\n";
			cout << "       Examples:  e2e4, e7e5, e1g1 (white short castling), e7e8q (for promotion).\n";
		
		
		}else if(argument == "--source"){
			cout << "https://github.com/thaniel-c/chess\n\n";
			cout << R"(MIT License

Copyright (c) 2020 Nathan Coulas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.)" << "\n";
	}else if(argument == "--local"){
		localMode();
	}else if(argument == "--cpu" || argument == "-c"){
		engineMode();
	}else{
		cout << "Argument not recognized. Use --help for a list of arguments.\n";
	}
		
	}
	
	return 0;
}
