#ifndef ENGINECONNECTOR_H
#define ENGINECONNECTOR_H

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <string.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <fstream>
#include <array>
#include <string>
#include "board.h"

using namespace std;

string exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    
    return result;
}

string getEngineMove(string position, bool isPlayer1){
	ofstream Buffer("enginebuffer.sh");
	Buffer << "#!/bin/bash\n";
	Buffer << "echo isready\n";
	Buffer << "echo position startpos moves " << position << "\n";
	Buffer << "echo go depth 6\n";
	Buffer << "sleep 1\n";
	Buffer.close();
	string engineResponse = exec("./enginebuffer.sh | stockfish");
	if (!engineResponse.empty() && engineResponse[engineResponse.length()-1] == '\n') {
		engineResponse.erase(engineResponse.length()-1);
	}
	int n = engineResponse.find("bestmove");
	if(n != -1) engineResponse = engineResponse.substr(n+9, 4);
	
	if(checkMove(engineResponse, isPlayer1)){
		return engineResponse;
	}else{
		return getEngineMove(position, isPlayer1);
	}
}

#endif
