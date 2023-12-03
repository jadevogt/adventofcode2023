#import <iostream>
#import <fstream>
#import <string>
#import <vector>
#import <sstream>
#import <exception>
#include "game.h"



int main() {
	std::ifstream infile("input.txt");
	std::string line;
	std::vector<game> games;
	while (std::getline(infile, line)) {
		games.push_back(parseGame(line));
	}
	std::cout << "\n\n\n";
	long long total = 0;
	for (game game : games) {
		std::cout << game.id << ":\n";
		std::cout << "\tred:" << game.redCount << "\n";
		std::cout << "\tgreen:" << game.greenCount << "\n";
		std::cout << "\tblue:" << game.blueCount << "\n";
		total += game.redCount * game.greenCount * game.blueCount;
	}
	std::cout << total << "\n";
	return 0;
}
