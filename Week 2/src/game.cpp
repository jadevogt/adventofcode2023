//
// Created by Jade Vogt on 12/2/23.
//

#import <exception>
#import <sstream>
#import <vector>
#import <string>
#import <fstream>
#import <iostream>
#include "game.h"



subGame getSubGame(std::string subgameStr) {
	if (subgameStr.find(':') != std::string::npos) {
        subgameStr = subgameStr.substr(subgameStr.find(':'));
	}
	std::cout << subgameStr << ": ";
	std::stringstream ss(subgameStr);
	std::string tmp;
	subGame sgame{0, 0, 0};
	while (ss >> tmp) {
		try {
			int newVal = std::stoi(tmp);
			std::cout << newVal;
			ss >> tmp;
			std::cout << "|" << tmp << "|";
			if (tmp == "red" || tmp == "red,") {
				sgame.redCount += newVal;
				std::cout << "red";
			} else if (tmp == "green" || tmp=="green,") {
				sgame.greenCount += newVal;
				std::cout << "green";
			} else if (tmp == "blue" || tmp=="blue,") {
				sgame.blueCount += newVal;
				std::cout << "blue";
			}
		}
		catch (std::exception &e) {
			continue;
		}
	}
	std::cout << "\n";
	return sgame;
}

std::vector<int> getIndices(std::string inputString, char delimiter) {
	std::vector<int> result {0};
	for (int i = 0; i < inputString.length(); i++) {
		if (inputString[i] == delimiter)
		{
			result.push_back(i);
		}
	}
	result.push_back(static_cast<int>(inputString.length()));
	return result;
}

game parseGame(std::string inputLine) {
	long long red = 0;
	long long green = 0;
	long long blue = 0;

	inputLine = inputLine.substr(5);
	std::string id = inputLine.substr(0, inputLine.find(':'));
	std::cout << id;
	int intId = std::stoi(id);
	std::vector<int> subGameIndices = getIndices(inputLine, ';');
	std::__1::vector<subGame> subGames{};
	for (int i = 0; i < subGameIndices.size() - 1; i++) {
		int len = subGameIndices.at(i + 1) - subGameIndices.at(i);
		subGames.push_back(getSubGame(inputLine.substr(subGameIndices.at(i), len)));
	}

	for (subGame sg : subGames) {
		std::cout << "\tred:" << sg.redCount << "\n";
		if (sg.redCount > red)
		{
			red = sg.redCount;
		}
		std::cout << "\tgreen:" << sg.greenCount << "\n";
		if (sg.greenCount > green)
		{
			green = sg.greenCount;
		}
		std::cout << "\tblue:" << sg.blueCount << "\n";
		if (sg.blueCount > blue)
		{
			blue = sg.blueCount;
		}
	}
	return game{intId, red, green, blue};
}