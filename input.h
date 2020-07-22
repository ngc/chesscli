#ifndef INPUT_H
#define INPUT_H

#include <bits/stdc++.h>
#include <stdlib.h>
#include "board.h"
using namespace std;

vector<string> tokenize(string input){
	vector<string> ret;
	
	string temp = "";
	for(int i = 0; i <= input.length(); i++){		
		if(i == input.length() - 1){
			temp += input[i];
		}
		
		if(input[i] == ' ' || i == input.length() - 1){
			ret.push_back(temp);
			temp = "";
		}else{
			temp += input[i];
		}
	}
	return ret;
}

string pause(bool isPlayer1) {
    cin.clear();
    cout << flush;
    string command;
    getline(cin, command);
   
   vector<string> commands = tokenize(command);
   
	if(command == "quit"){
		cout << "Exiting...\n";
		exit(0);
	}else if(command == "moves"){
		cout << moveLog << "\n";
	}
	
	if(commands[0] == "preview" && commands.size() == 2 && commands[1].length() == 2){
		PrintPreview(commands[1]);
	}

	command.erase(remove(command.begin(), command.end(), ' '), command.end()); 
	if(checkMove(command, isPlayer1)){
		return command;
	}else{
		return pause(isPlayer1);
	}
	system("clear");
	return command;
}
#endif
