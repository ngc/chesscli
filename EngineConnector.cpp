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

//#include "board.h"
//#include "local.h"

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

string getEngineMove(string position){
	ofstream Buffer("enginebuffer");
	Buffer << "isready\n";
	Buffer << "position startpos moves " << position << "\n";
	Buffer << "go\n";
	Buffer << "quit\n";
	Buffer.close();
	string engineResponse = exec("stockfish < enginebuffer");
	return exec("stockfish < enginebuffer").substr();
}

int main(void)
{    

		cout << getEngineMove("a2a4");
        return 0;
}
